#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int q;

#define MAX 1000005

#define modp 1000000007

long long f0[1100000];

long long f(int n,int r)
{
	int i;
	long long res = 0;
	if (r == 0)
	{
		i = 2;
		res = 1;
		while (i*i<=n)
		{
			if (n%i == 0)
			{
				res *= 2;
				while (n%i == 0) n/=i;
			}
			i++;
		}
		if (n != 1) res *= 2;
		return res;
	}
	for (i=1;i<=n;i++)
	{
		if (n%i == 0)
		{
			res += f(i,r-1);
			res %= modp;
		}
	}
	return res;
}

int main()
{
	int i,j,k;
	cin>>q;
	int n,r;
	for (i=0;i<q;i++)
	{
		cin>>r>>n;
		cout<<f(n,r)<<endl;
	}
	return 0;
}
