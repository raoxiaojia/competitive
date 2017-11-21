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

int t;

int n;

double bdist[120][120];

double endu[120];

double velo[120];

double dist[120][120];

int main()
{
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	cin>>t;
	int q;
	int i,j,k;
	for (i=0;i<t;i++)
	{
		memset(bdist,0,sizeof(bdist));
		memset(dist,0,sizeof(dist));
		printf("Case #%d:",i+1);
		cin>>n>>q;
		for (j=0;j<n;j++)
		{
			cin>>endu[j]>>velo[j];
		}
		for (j=0;j<n;j++)
		{
			for (k=0;k<n;k++)
			{
				cin>>bdist[j][k];
				if (bdist[j][k] == -1) bdist[j][k] = 1e55;
			}
			bdist[j][j] = 0;
		}
		int l;
		for (l=0;l<n;l++)
		{
			for (j=0;j<n;j++)
			{
				for (k=0;k<n;k++)
				{
					if (bdist[j][k] > bdist[j][l] + bdist[l][k]) bdist[j][k] = bdist[j][l] + bdist[l][k];
				}
			}
		}
		for (j=0;j<n;j++)
		{
			dist[j][j] = 0;
			for (k=0;k<n;k++)
			{
				if (bdist[j][k] <= endu[j])
				{
					dist[j][k] = bdist[j][k]/velo[j];
				}
				else
				{
					dist[j][k] = 1e55;
				}
			}
		}
		for (l=0;l<n;l++)
		{
			for (j=0;j<n;j++)
			{
				for (k=0;k<n;k++)
				{
					if (dist[j][k] > dist[j][l] + dist[l][k]) dist[j][k] = dist[j][l] + dist[l][k];
				}
			}
		}
		for (j=0;j<q;j++)
		{
			cin>>k>>l;
			printf(" %.8lf",dist[k-1][l-1]);
		}
		printf("\n");
	}
	return 0;
}
