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

int arr[200005];

int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}

int main()
{
	int n;
	int i,j,k;
	scanf("%d",&n);
	int cur = 0;
	for (i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
		cur = gcd(cur,arr[i]);
	}
	if (cur != 1)
	{
		printf("YES\n0\n");
		return 0;
	}
	i=0;
	int ans = 0;
	while (i<n)
	{
		if (arr[i] % 2 == 0)
		{
			i++;
			continue;
		}
		if (i == n-1)
		{
			printf("YES\n");
			printf("%d\n",ans+2);
			return 0;
		}
		if (arr[i+1] % 2 == 0)
		{
			ans += 2;
			i+=2;
		}
		else
		{
			ans += 1;
			i+=2;
		}
	}
	printf("YES\n");
	printf("%d\n",ans);
	return 0;
}
