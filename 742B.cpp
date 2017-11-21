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

int count2[200000];

int main()
{
	int n,x;
	cin>>n>>x;
	int i,j;
	for (i=0;i<n;i++)
	{
		cin>>j;
		count2[j] ++;
	}
	long long ans = 0;
	for (i=0;i<=100000;i++)
	{
		if (x != 0)
		if (i<(x^i))
		{
			ans += (long long)count2[i]*count2[x^i];
		//	printf("%d %d %d\n",i,x^i,ans);
		}
		if (x == 0)
		{
			ans += (long long)count2[i]*(count2[i]-1)/2;
		}
	}
	cout<<ans<<endl;
	return 0;
}
