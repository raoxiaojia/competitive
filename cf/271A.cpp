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

bool ok(int n)
{
	int a,b,c,d;
	a = n%10;
	b = n/10%10;
	c = n/100%10;
	d = n/1000;
	if (a == b) return false;
	if (a == c) return false;
	if (a == d) return false;
	if (b == c) return false;
	if (b == d) return false;
	if (c == d) return false;
	return true;
}

int main()
{
	int n;
	scanf("%d",&n);
	n++;
	while (!ok(n)) n++;
	printf("%d\n",n);
	return 0;
}
