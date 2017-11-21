#include "bits/stdc++.h"
using namespace std;

int n;

int a[6000];

int appear[2000000];

int gcd(int x,int y)
{
	return x%y==0?y:gcd(y,x%y);
}

int main()
{
	int i,j,k;
	cin>>n;
	int cur = a[0];
	for (i=0;i<n;i++)
	{
		cin>>a[i];
		appear[a[i]] = 1;
		cur = gcd(cur,a[i]);
	}
	if (appear[cur] == 0)
	{
		printf("-1\n");
		return 0;
	}
	printf("%d\n",2*n);
	for (i=0;i<n;i++)
	{
		printf("%d %d ",cur,a[i]);
	}
	printf("\n");
	return 0;
}
