#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>

using namespace std;

int n,m;

int tpos[2][2];

int mpos[200000][2],mvel[200000][2];

double ilow,ihigh;

int update(double cil, double cih)
{
	if (cil>=ihigh-1e-10) return -1;
	if (cih<=ilow+1e-10) return -1;
	if (cil>ilow) ilow = cil;
	if (cih<ihigh) ihigh = cih;
	if (ihigh-ilow<1e-11) return -1;
	return 0;
}

int main()
{
	int i,j,k;
	ilow = 0;
	ihigh = 1e60;
	cin>>n;
	cin>>tpos[0][0]>>tpos[0][1]>>tpos[1][0]>>tpos[1][1];
	for (i=0;i<n;i++)
	{
		cin>>mpos[i][0]>>mpos[i][1];
		cin>>mvel[i][0]>>mvel[i][1];
		double xil,xih;
		//x
		if (mpos[i][0]<=tpos[0][0])
		{
			if (mvel[i][0] <= 0)
			{
				printf("-1\n");
				return 0;
			}
			xil = (double)(tpos[0][0]-mpos[i][0])/(double)mvel[i][0];
			xih = (double)(tpos[1][0]-mpos[i][0])/(double)mvel[i][0];
			if (update(xil,xih) == -1)
			{
				printf("-1\n");
				return 0;
			}
		}
		else
		if (mpos[i][0]>=tpos[1][0])
		{
			if (mvel[i][0] >= 0)
			{
				printf("-1\n");
				return 0;
			}
			xil = (double)(tpos[1][0]-mpos[i][0])/(double)mvel[i][0];
			xih = (double)(tpos[0][0]-mpos[i][0])/(double)mvel[i][0];
			if (update(xil,xih) == -1)
			{
				printf("-1\n");
				return 0;
			}
		}
		else
		{
			if (mvel[i][0]<0)
			{
				xil = 0;
				xih = (double)(tpos[0][0]-mpos[i][0])/(double)mvel[i][0];
				if (update(xil,xih) == -1)
				{
					printf("-1\n");
					return 0;
				}
			}
			else
			if (mvel[i][0]>0)
			{
				xil = 0;
				xih = (double)(tpos[1][0]-mpos[i][0])/(double)mvel[i][0];
				if (update(xil,xih) == -1)
				{
					printf("-1\n");
					return 0;
				}
			}
		}
		//y
		if (mpos[i][1]<=tpos[0][1])
		{
			if (mvel[i][1] <= 0)
			{
				printf("-1\n");
				return 0;
			}
			xil = (double)(tpos[0][1]-mpos[i][1])/(double)mvel[i][1];
			xih = (double)(tpos[1][1]-mpos[i][1])/(double)mvel[i][1];
			if (update(xil,xih) == -1)
			{
				printf("-1\n");
				return 0;
			}
		}
		else
		if (mpos[i][1]>=tpos[1][1])
		{
			if (mvel[i][1] >= 0)
			{
				printf("-1\n");
				return 0;
			}
			xil = (double)(tpos[1][1]-mpos[i][1])/(double)mvel[i][1];
			xih = (double)(tpos[0][1]-mpos[i][1])/(double)mvel[i][1];
			if (update(xil,xih) == -1)
			{
				printf("-1\n");
				return 0;
			}
		}
		else
		{
			if (mvel[i][1]<0)
			{
				xil = 0;
				xih = (double)(tpos[0][1]-mpos[i][1])/(double)mvel[i][1];
				if (update(xil,xih) == -1)
				{
					printf("-1\n");
					return 0;
				}
			}
			else
			if (mvel[i][1]>0)
			{
				xil = 0;
				xih = (double)(tpos[1][1]-mpos[i][1])/(double)mvel[i][1];
				if (update(xil,xih) == -1)
				{
					printf("-1\n");
					return 0;
				}
			}
		}
	}
	printf("%.9lf\n",ilow);
	return 0;
}
