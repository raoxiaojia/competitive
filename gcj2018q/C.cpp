#include "bits/stdc++.h"

using namespace std;

int filled[20][20];

void send(int x,int y)
{
	cout<<500+x<<' '<<500+y<<endl;
}

void get(int* x,int* y)
{
	cin>>*x>>*y;
	*x -= 500;
	*y -= 500;
}

int getscore(int x,int y)
{
	int i,j,res;
	res = 9;
	for (i=-1;i<=1;i++)
	{
		for (j=-1;j<=1;j++)
		{
			res -= filled[x+i][y+j];
		}
	}
	return res;
}

int main()
{
	int t,a;
	cin>>t;
	int i,j,k;
	for (i=0;i<t;i++)
	{
		cin>>a;
		int rx,ry;
		//try fill (500,500)-(513,514)
		for (j=1;j<=12;j++)
		{
			for (k=0;k<5;k++)
			{
				send(j,1);
				get(&rx,&ry);
				if ((rx == -500) && (ry == -500))
				{
					goto next;
				}
				filled[rx][ry] = 1;
			}
			for (k=0;k<5;k++)
			{
				send(j,13);
				get(&rx,&ry);
				if ((rx == -500) && (ry == -500))
				{
					goto next;
				}
				filled[rx][ry] = 1;
			}
			for (k=0;k<5;k++)
			{
				send(1,j);
				get(&rx,&ry);
				if ((rx == -500) && (ry == -500))
				{
					goto next;
				}
				filled[rx][ry] = 1;
			}
			for (k=0;k<5;k++)
			{
				send(12,j);
				get(&rx,&ry);
				if ((rx == -500) && (ry == -500))
				{
					goto next;
				}
				filled[rx][ry] = 1;
			}
		}

		while (1)
		{
			int maxj,maxk;
			int max = 0;
			for (j=1;j<=12;j++)
			{
				for (k=1;k<=13;k++)
				{
					int l = getscore(j,k);
					if (l>max)
					{
						max = l;
						maxj = j;
						maxk = k;
						if (max == 9) break;
					}
				}
				if (max == 9) break;
			}
			send(maxj,maxk);
			get(&rx,&ry);
			if ((rx == -500) && (ry == -500))
			{
				goto next;
			}
			filled[rx][ry] = 1;
		}

next:		memset(filled,0,sizeof(filled));
	}
	return 0;
}
