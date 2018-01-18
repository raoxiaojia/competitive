#include "bits/stdc++.h"

using namespace std;

long long cost[100];

long long ans = 0;

int main()
{
	long long n,l;
	int i,j,k;
	cin>>n>>l;
	for (i=0;i<n;i++)
	{
		cin>>cost[i];
		if (i==0) continue;
		if (cost[i-1]*2 < cost[i]) cost[i] = cost[i-1]*2;
	}
	ans = -1;
	k = 0;
	do
	{
		long long cur = 1<<(n-1);
		long long curans = (l/cur)*cost[n-1];
		long long tl = l % cur;
		for (i=n-1;i>=0;i--)
		{
			cur = 1<<(i);
			if (tl>=cur)
			{
				tl -= cur;
				curans += cost[i];
			}
		}
		if (curans<ans || ans == -1) ans = curans;
		if (l&(l-1))
		{
			if (l&(1<<k)) l += (1<<k);
		}
		else
		{
			l *= 2;
		}
		k++;
	}
	while ((l&(l-1)) || (l<=(1<<n)));
	cout<<ans<<endl;
	return 0;
}
