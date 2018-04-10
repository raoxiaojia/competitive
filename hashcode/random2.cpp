#include "bits/stdc++.h"

using namespace std;

int n,m;

int nveh;
int nrides;
int bonus;
int steps;

struct i8
{
	int data[8];
};

vector<i8> rinfo; 

typedef vector<int> vi;

int rtaken[12000];


vi vtask[12000];

bool cmp(i8 x,i8 y)
{
	return x.data[5]<y.data[5];
}

int dist(int x1,int y1,int x2,int y2)
{
	return abs(x1-x2) + abs(y1-y2);
}

double sqr2(double x)
{
	return x*x;
}

int main()
{
	cin>>n>>m>>nveh>>nrides>>bonus>>steps;
	int i,j,k;
	for (i=0;i<nrides;i++)
	{
		i8 ri;
		for (j=0;j<6;j++)
		{
			cin>>ri.data[j];
		}	
		ri.data[6] = dist(ri.data[0],ri.data[1],ri.data[2],ri.data[3]);
		ri.data[7] = i;
		rinfo.push_back(ri);
	}
	sort(rinfo.begin(),rinfo.end(),cmp);
	long long score = 0;
	srand(time(NULL));
	int nveh1 = nveh * 0.9;
	for (i=0;i<nveh;i++)
	{
		int nvehfree = 0;
		int nposx = 0;
		int nposy = 0;
		for (j=0;j<nrides;j++)
		{
			if (rtaken[j]) continue;
			int d = dist(nposx,nposy,rinfo[j].data[0],rinfo[j].data[1]);
			if ((nvehfree + d + rinfo[j].data[6] <= rinfo[j].data[5]) && (rinfo[j].data[4]+rinfo[j].data[6] <= rinfo[j].data[5]))
			{
				int rec_prob = 0;
	//			if (nvehfree+d <= rinfo[j].data[4]) rec_prob = 9000;
	//			else rec_prob = 2;
				if (i < nveh1)
				{
					rec_prob = 10000.0*sqr2(((double)i+nveh)/((double)nveh+nveh))*sqr2((double)rinfo[j].data[6]/(rinfo[j].data[6]+d));
				}
				else 
				{
					rec_prob = 9000.0;
				}
				if (rand()%10000 < rec_prob)
				{
					rtaken[j] = 1;
					if (nvehfree+d <= rinfo[j].data[4])
					{
						score += bonus;
						nvehfree = rinfo[j].data[4] + rinfo[j].data[6];
						score += dist(rinfo[j].data[0],rinfo[j].data[1],rinfo[j].data[2],rinfo[j].data[3]);
					}
					else
					{
						score += dist(rinfo[j].data[0],rinfo[j].data[1],rinfo[j].data[2],rinfo[j].data[3]);
						nvehfree += d+rinfo[j].data[6];
					}
					vtask[i].push_back(rinfo[j].data[7]);
					nposx = rinfo[j].data[2];
					nposy = rinfo[j].data[3];
				}
				else
				{
					continue;
				}
			}
		}
	}
	for (i=0;i<nveh;i++)
	{
		printf("%d",vtask[i].size());
		for (j=0;j<vtask[i].size();j++)
		{
			printf(" %d",vtask[i][j]);
		}
		printf("\n");
	}
	return 0;
}
