#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>

long long mod = 1000000007;

long long qp10mod(long long x)
{
	long long cur = 10;
	long long res = 1;
	while (x)
	{
		if (x%2 == 1) res *= cur;
		res %= mod;
		x /= 2;
		cur = (cur*cur)%mod;
	}
	return res;
}

int main()
{
	int i;
	for (i=0;i<19;i++)
	printf("%lld\n",qp10mod(i));
	return 0;
}
