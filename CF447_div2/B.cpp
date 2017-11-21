#include "bits/stdc++.h"
using namespace std;

int modbase = 1000000007;

long long n,m,t;

long long qpmod(long long base, long long e)
{
	long long res = 1;
	long long cur = base % modbase;
	while (e)
	{
		if (e&1) res = res*cur % modbase;
		cur = cur*cur%modbase;
		e /= 2;
	}
	return res;
}

int main()
{
	cin>>n>>m>>t;
	if ((t == -1) && (n+m%2 == 1))
	{
		cout<<0<<endl;
		return 0;
	}
	cout<<qpmod(qpmod(2,n-1),m-1)<<endl;
	return 0;
}
