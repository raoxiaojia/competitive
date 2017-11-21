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

int g[200][200],ag[200][200];

int ans;

int main()
{
	int n,m;
	cin>>n>>m;
	int i,j,k;
	for (i=0;i<n;i++)
	{
		for (j=0;j<m;j++)
		{
			cin>>g[i][j];
		}
	}
	int min = 10000000;
	int omin = min;
	for (i=0;i<m;i++)
	{
		if (g[0][i]<min) min = g[0][i];
	}
	omin = min;
	for (i=1;i<n;i++)
	{
		for (j=0;j<m;j++)
		{
			if (g[i][j]-g[i][0] != g[0][j] - g[0][0])
			{
				printf("-1\n");
				return 0;
			}
			if (g[i][j]<omin) omin = g[i][j];
		}
	}
	for (i=0;i<n;i++)
	{
		for (j=0;j<m;j++)
		{
			g[i][j] -= omin;
		}
	}
	min -= omin;
	memcpy(ag,g,sizeof(g));
	for (i=0;i<m;i++)
	{
		k = g[0][i]-min;
		ans += k;
		for (j=0;j<n;j++)
		{
			g[j][i] -= k;
		}
	}
	for (i=0;i<n;i++)
	{
		ans += g[i][0];
	}
	printf("%d\n",ans+omin*(n<m?n:m));
	if (n<m)
	{
		for (i=0;i<omin;i++)
		{
			for (j=0;j<n;j++)
			{
				printf("row %d\n",j+1);
			}
		}
	}
	else
	{
		for (i=0;i<omin;i++)
		{
			for (j=0;j<m;j++)
			{
				printf("col %d\n",j+1);
			}
		}
	}
	for (i=0;i<m;i++)
	{
		k = ag[0][i]-min;
		for (j=0;j<k;j++)
		{
			printf("col %d\n",i+1);
		}
		for (j=0;j<n;j++)
		{
			ag[j][i] -= k;
		}
	}
	for (i=0;i<n;i++)
	{
		for (j=0;j<ag[i][0];j++)
		{
			printf("row %d\n",i+1);
		}
	}
	return 0;
}
