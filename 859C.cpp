#include "bits/stdc++.h"

using namespace std;

int n;

int f[100][2];

int total;

int sz[100];

int main()
{
	cin>>n;
	int i,j,k;
	for (i=1;i<=n;i++)
	{
		cin>>sz[i];
		total += sz[i];
	}
	f[n][0] = sz[n];
	f[n][1] = 0;
	for (i=n-1;i>=1;i--)
	{
		f[i][0] = f[i+1][0]>f[i+1][1]+sz[i]?f[i+1][0]:f[i+1][1]+sz[i];
		f[i][1] = f[i+1][1]+sz[i]<f[i+1][0]?f[i+1][1]+sz[i]:f[i+1][0];
	}
	printf("%d %d\n",total-f[1][0],f[1][0]);
	return 0;
}
