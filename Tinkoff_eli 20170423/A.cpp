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

long long arr[200000];

long long n,m;

int main()
{
	int i,j,k;
	scanf("%I64d %I64d",&n,&m);
	scanf("%I64d",&arr[0]);
	long long min = arr[0];
	for (i=1;i<n;i++)
	{
		scanf("%I64d",&arr[i]);
		if (arr[i]<min) min = arr[i];
	}
	long long ans=0;
	for (i=0;i<n;i++)
	{
		if ((arr[i]-min) % m != 0)
		{
			printf("-1\n");
			return 0;
		}
		ans += (arr[i]-min)/m;
	}
	printf("%I64d\n",ans);
	return 0;
}
