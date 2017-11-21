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
	int ans,cur;
	cin>>n>>m;
	m=240-m;
	ans = 0;
	cur = 5;
	while (m>=cur)
	{
		ans ++;
		m -= cur;
		cur += 5;
		n--;
		if (n == 0) break;
	}
	printf("%d\n",ans);
	return 0;
}
