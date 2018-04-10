#include "bits/stdc++.h"

using namespace std;

int n,m;

int nveh;
int nrides;
int bonus;
int steps;

struct i7
{
	int data[7];
};

vector<i7> rinfo; 

typedef vector<int> vi;

int rtaken[12000];

vi vtask[12000];

bool cmp(i7 x,i7 y)
{
	return x.data[4]<y.data[4];
}

int dist(int x1,int y1,int x2,int y2)
{
	return abs(x1-x2) + abs(y1-y2);
}

int main()
{
	cin>>n>>m>>nveh>>nrides>>bonus>>steps;
	int i,j,k;
	int maxscore = 0;
	for (i=0;i<nrides;i++)
	{
		i7 ri;
		for (j=0;j<6;j++)
		{
			cin>>ri.data[j];
		}	
		ri.data[6] = dist(ri.data[0],ri.data[1],ri.data[2],ri.data[3]);
		rinfo.push_back(ri);
		maxscore += ri.data[6];
	}
	maxscore += bonus*nrides;
	cout<<maxscore<<endl;
}
