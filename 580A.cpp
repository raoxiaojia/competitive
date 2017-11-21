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
	int last = 0;
	int ans = 0;
	int cur = 0;
	scanf("%d",&n);
	int x;
	cin>>last;
	ans = 1;
	cur = 1;
	n--;
	while (n--)
	{
		cin>>x;
		if (x>=last)
		{
			cur ++;
			ans = ans>cur?ans:cur;
			last = x;
		}
		else
		{
			last = x;
			cur = 1;
		}
	}
	printf("%d\n",ans);
	return 0;
}
