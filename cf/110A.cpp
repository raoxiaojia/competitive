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
	long long n;
	scanf("%lld",&n);
	int ans = 0;
	while (n)
	{
		if ((n%10 == 4) || (n%10 == 7)) ans ++;
		n /= 10;
	}
	if ((ans == 4) || (ans == 7)) printf("YES\n");
	else printf("NO\n");
	return 0;
}
