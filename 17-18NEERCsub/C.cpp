#include "bits/stdc++.h"

using namespace std;

long long n,m;

int main()
{
	cin>>n>>m;
	int i,j,k;
	if (n*(n-1)/2 < m)
	{
		printf("Impossible\n");
		return 0;
	}
	long long req = (1+sqrt(4*m*2+1))/2;
	if (req*(req-1)/2 != m) req++;
	for (i=0;i<n-req;i++)
	{
		printf("()");
	}
	long long capacity = req*(req-1)/2, excess = capacity - m;
	if (excess == 0)
	{
		for (i=0;i<req;i++)
		{
			printf("(");
		}
		for (i=0;i<req;i++)
		{
			printf(")");
		}
		return 0;
	}
	for (i=0;i<req-1;i++)
	{
		printf("(");
		if (i == req-excess-1) printf("()");
	}
	for (i=0;i<req-1;i++)
	{
		printf(")");
	}
	return 0;
}
