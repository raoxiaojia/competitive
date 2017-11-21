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
	int a,b,c,d,e;
	scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
	int ans = 0;
	for (int i=1;i<=e;i++)
	{
		ans += (i%a)*(i%b)*(i%c)*(i%d)?0:1;
	}
	printf("%d\n",ans);
	return 0;
}
