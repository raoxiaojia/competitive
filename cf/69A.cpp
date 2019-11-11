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
	int a,b,c,d,e,f;
	cin>>n;
	a = 0;
	b = 0;
	c = 0;
	while (n--)
	{
		cin>>d>>e>>f;
		a+=d;
		b+=e;
		c+=f;
	}
	if ((a == 0) && (b == 0) && (c == 0)) printf("YES\n");
	else printf("NO\n");
	return 0;
}
