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

int n,p;

int g[101][101][101],f[101][101];

int c[5];

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	cin>>t;
	int i,j,k,l;
	for (l=0;l<t;l++)
	{
		int ans = 0;
		memset(c,0,sizeof(c));
		memset(f,0,sizeof(f));
		memset(g,0,sizeof(g));
		cin>>n>>p;
		for (i=0;i<n;i++)
		{
			cin>>j;
			if (j%p==0) ans++;
			else c[j%p] ++;
		}
		if (p == 2)
		{
			printf("Case #%d: %d\n",l+1,ans+(c[1]+1)/2);
			continue;
		}
		int aans = 0;
		if (p == 3)
		{
			for (i=0;i<=c[1];i++)
			{
				for (j=0;j<=c[2];j++)
				{
					if (i>=3)
					{
						if (f[i-3][j]+1>f[i][j]) f[i][j] = f[i-3][j]+1;
					}
					if (j>=3)
					{
						if (f[i][j-3]+1>f[i][j]) f[i][j] = f[i][j-3]+1;
					}
					if ((i>=1) && (j>=1))
					{
						if (f[i-1][j-1]+1>f[i][j]) f[i][j] = f[i-1][j-1] + 1;
					}
					if ((i==c[1]) && (j==c[2]))
				{
					if (aans<f[i][j]) aans = f[i][j];
				}
				else
				{
					if (aans<f[i][j]+1) aans = f[i][j]+1;
				}
				}
			}
		}
		else
		if (p==4)
		{
			for (i=0;i<=c[1];i++)
			{
				for (j=0;j<=c[2];j++)
				{
					for (k=0;k<=c[3];k++)
					{
						if (i>=4)
						{
							if (g[i-4][j][k]+1>g[i][j][k]) g[i][j][k] = g[i-4][j][k]+1;
						}
						if (j>=2)
						{
							if (g[i][j-2][k]+1>g[i][j][k]) g[i][j][k] = g[i][j-2][k]+1;
						}
						if (k>=4)
						{
							if (g[i][j][k-4]+1>g[i][j][k]) g[i][j][k] = g[i][j][k-4]+1;
						}
						if ((i>=1) && (k>=1))
						{
							if (g[i-1][j][k-1]+1>g[i][j][k]) g[i][j][k] = g[i-1][j][k-1]+1;
						}
						if ((i>=2) && (j>=1))
						{
							if (g[i-2][j-1][k]+1>g[i][j][k]) g[i][j][k] = g[i-2][j-1][k]+1;
						}
						if ((k>=2) && (j>=1))
						{
							if (g[i][j-1][k-2]+1>g[i][j][k]) g[i][j][k] = g[i][j-1][k-2]+1;
						}
						if ((i==c[1]) && (j==c[2]) && (k==c[3]))
				{
					if (aans<g[i][j][k]) aans = g[i][j][k];
				}
				else
				{
					if (aans<g[i][j][k]+1) aans = g[i][j][k]+1;
				}
					}
				}
				
			}
		}
		printf("Case #%d: %d\n",l+1,ans+aans);
	}
	return 0;
}
