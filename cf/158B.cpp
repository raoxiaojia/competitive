#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	int res[4];
	int ans = 0;
	int i,j,k;
	memset(res,0,sizeof(res));
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{
		scanf("%d",&j);
		ans += j/4;
		res[j%4] ++;
	}
	if (res[1]>res[3])
	{
		ans += res[3];
		res[1] -= res[3];
		res[3] = 0;
		ans += (res[1]+res[2]*2+3)/4;
	}
	else
	{
		ans += res[3];
		ans += (res[2]+1)/2;
	}
	printf("%d\n",ans);
	return 0;
}
