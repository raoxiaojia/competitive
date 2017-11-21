#include "bits/stdc++.h"
using namespace std;

int n;

int ans;

int a[5000];

int gcd(int a,int b)
{
	return a%b==0?b:gcd(b,a%b);
}

int main()
{
	cin>>n;
	int i,j,k;
	for (i=0;i<n;i++)
	{
		cin>>a[i];
	}
	ans = 10000;
	for (i=0;i<n;i++)
	{
		int cur = a[i];
		int min = -1;
		for (j=i;j<n;j++)
		{
			cur = gcd(cur,a[j]);
			if (cur == 1)
			{
				min = j-i;
				break;
			}
		}
		if (min == -1) continue;
		if (min<ans) ans = min;
	}
	if (ans == 10000)
	{
		printf("-1\n");
		return 0;
	}
	if (ans == 0)
	{
		for (i=0;i<n;i++)
		{
			if (a[i] != 1) ans ++;
		}
		printf("%d\n",ans);
		return 0;
	}
	printf("%d\n",ans+n-1);
	return 0;
}
