#include <bits/stdc++.h>

int n,m;

int value[205][2];

int f[205][205][3700];

using namespace std;

int ans;

int min(int x,int y)
{
	return x<y?x:y;
}

int main()
{
	cin>>n>>m;
	int i,j;
	long long k;
	for (i=1;i<=n;i++)
	{
		cin>>k;
		j = 0;
		while (k%5 == 0)
		{
			j++;
			k/=5;
		}
		value[i][1] = j;
		j = 0;
		while (k%2 == 0)
		{
			j++;
			k/=2;
		}
		value[i][0] = j;
	}
	for (j=0;j<=200;j++)
	{
		for (k=1;k<=3700;k++)
		{
			f[0][j][k] = -16383;
		}
	}
	for (i=0;i<=200;i++)
	{
		for (k=1;k<=3700;k++)
		{
			f[i][0][k] = -16383;
		}
	}
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=i;j++)
		{
			if (j>m) break;
			for (k=0;k<=j*28;k++)
			{
				if (k>3602) break;
				f[i][j][k] = f[i-1][j][k];
				if (value[i][1] <= k)
				{
					if (f[i-1][j-1][k-value[i][1]] + value[i][0] > f[i][j][k])
					{
						f[i][j][k] = f[i-1][j-1][k-value[i][1]] + value[i][0];
					}
				}
				if (min(f[i][j][k],k) > ans)
				{
					ans = min(f[i][j][k],k);
				}
				printf("%d %d %d %d\n",i,j,k,f[i][j][k]);
			}
		}
	}
	cout<<ans;
	return 0;
}
