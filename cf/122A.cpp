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
	scanf("%d",&n);
	if (n%4 == 0) printf("YES\n");
	else if (n%7 == 0) printf("YES\n");
	else if (n%47 == 0) printf("YES\n");
	else if (n%74 == 0) printf("YES\n");
	else if (n%447 == 0) printf("YES\n");
	else if (n%474 == 0) printf("YES\n");
	else if (n%477 == 0) printf("YES\n");
	else if (n%747 == 0) printf("YES\n");
	else if (n%774 == 0) printf("YES\n");
	else printf("NO\n");
	return 0;
}
