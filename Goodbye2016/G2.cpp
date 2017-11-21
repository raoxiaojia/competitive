#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>

int ans[100000];

int sum(int x,int y)
{
	if (x == y) return x;
	if (x>=y*2) return sum(x/2,y)+x;
	if (y>=x*2) return sum(x,y/2)+y;
	return sum(x/2,y/2)+x+y;
}

int main()
{
	int n = 1000;
	for (int i=1;i<=n;i++)
	{
		for (int j=i;j<=n;j++)
		{
			ans[sum(i,j)]++;
		}
	}
	for (int i=1;i<=n;i++) printf("%d:%d\n",i,ans[i]);
	return 0;
}
