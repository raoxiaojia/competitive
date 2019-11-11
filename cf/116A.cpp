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
	int i,j,k;
	int max = 0;
	int cur = 0;
	scanf("%d",&n);
	while (n--)
	{
		scanf("%d %d",&i,&j);
		cur += j-i;
		max = max<cur?cur:max;
	}
	printf("%d\n",max);
	return 0;
}
