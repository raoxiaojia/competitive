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
	int a,b,c,d;
	cin>>n;
	c = 0;
	d = 0;
	while (n--)
	{
		cin>>a>>b;
		if (a>b) c++;
		else if (a<b) d++;
	}
	if (c>d) printf("Mishka\n");
	else if (c<d) printf("Chris\n");
	else printf("Friendship is magic!^^\n");
	return 0;
}
