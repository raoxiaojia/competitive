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

int notprime[1000005];

int ptotal[1000005];

long long n,x,y;

long long num[600000];

long long ans = (1e16);

long long ntotal[1000005];

int main()
{
	int i,j,k;
	notprime[0] = 1;
	notprime[1] = 1;
	for (i=2;i<=1000;i++)
	{
		if (notprime[i]) continue;
		for (j=2;i*j<=1000000;j++) notprime[i*j] = 1;
	}
	cin>>n>>x>>y;
	for (i=0;i<n;i++)
	{
		cin>>num[i];
		ntotal[num[i]] ++;
	}
	for (i=2;i<=1000000;i++)
	{
		if (notprime[i]) continue;
		for (j=1;i*j<=1000000;j++) ptotal[i] += ntotal[i*j];
	}
	if (x<=y)
	{
		int best = 0;
		for (i=2;i<=1000000;i++)
		{
			if (notprime[i]) continue;
			best = best<ptotal[i]?ptotal[i]:best;
		}
		cout<<(long long)(n-best)*x<<endl;
		return 0;
	}
	ans = (n-ptotal[2])*y;
	long long req = 0;
	long long maxreq = x/y;
	for (i=3;i<=1000000;i++)
	{
		if ((n-ptotal[i])*y >= ans) continue;
		int success = 1;
		long long cur = 0;
		for (j=0;j<n;j++)
		{
			if (num[j]%i == 0) continue;
			req = i-(num[j]%i);
			cur += req>maxreq?x:req*y;
			if (cur>=ans)
			{
				success = 0;
				break;
			}
		}
		if (!success) continue;
		ans = cur;
	}
	cout<<ans<<endl;
	return 0;
}
