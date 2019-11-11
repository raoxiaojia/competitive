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

long long f[200000];

long long ans;

int main()
{
	long long count[200000];
	int n;
	int i,j,k;
	cin>>n;
	memset(count,0,sizeof(count));
	for (i=0;i<n;i++)
	{
		cin>>j;
		count[j] ++;
	}
	f[1] = count[1];
	f[2] = count[2]*2;
	ans = f[1]>f[2]?f[1]:f[2];
	for (i=3;i<=100000;i++)
	{
		f[i] = f[i-2]>f[i-3]?f[i-2]:f[i-3];
		f[i] += count[i]*i;
		if (f[i]>ans) ans = f[i];
	}
	cout<<ans<<endl;
	return 0;
}
