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

int main()
{
	int t;
	int i,j,k;
	long long x,y,p,q;
	scanf("%d",&t);
	while (t--)
	{
		cin>>x>>y>>p>>q;
		if (p == 0)
		{
			if (x == 0) printf("0\n");
			else printf("-1\n");
			continue;
		}
		if (p == q)
		{
			if (x == y) printf("0\n");
			else printf("-1\n");
			continue;
		}
		if (x*q == p*y)
		{
			printf("0\n");
			continue;
		}
		long long ans;
		if (x*q-p*y>0)
		{
			ans = (x*q-p*y)/p+y;
			if (ans%q!=0) ans=ans/q*q+q;
			cout<<ans-y<<endl;
		}
		else
		{
			ans = (p*y-x*q)/(q-p)+y;
			if (ans%q!=0) ans=ans/q*q+q;
			cout<<ans-y<<endl;
		}
	}
	return 0;
}
