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
	int a,b,c;
	scanf("%d",&n);
	int ans = 0;
	while (n--)
	{
		scanf("%d %d %d",&a,&b,&c);
		ans += (a+b+c>=2)?1:0;
	}
	printf("%d\n",ans);
	return 0;
}
