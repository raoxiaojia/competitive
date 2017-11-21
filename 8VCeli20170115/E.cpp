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
	int n,m;
	int i;
	cin>>n>>m;
	if ((m==1) || (m>=4) || (n<=3))
	{
		printf("-1\n");
		return 0;
	}
	if (m == 2)
	{
		printf("%d\n",n-1);
		for (i=1;i<n;i++)
		{
			printf("%d %d\n",i,i+1);
		}
		return 0;
	}
	if (m == 3)
	{
		if (n<=4)
		{
			printf("-1\n");
			return 0;
		}
		printf("%d\n",2*n-5);
		for (i=1;i<n;i++)
		{
			printf("%d %d\n",i,i+1);
		}
		printf("3 1\n");
		for (i=6;i<=n;i++)
		{
			printf("3 %d\n",i);
		}
	}
	return 0;
}
