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
	int n;
	int ans[150];
	scanf("%d",&n);
	int i,j;
	for (i=1;i<=n;i++)
	{
		scanf("%d",&j);
		ans[j] = i;
	}
	for (i=1;i<n;i++)
	{
		printf("%d ",ans[i]);
	}
	printf("%d\n",ans[n]);
	return 0;
}
