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

int gcd(int x,int y)
{
	return x%y==0?y:gcd(y,x%y);
}

int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	while (1)
	{
		if (a%c == 0)
		{
			printf("0\n");
			return 0;
		}
		c -= gcd(a,c);
		if (b%c == 0)
		{
			printf("1\n");
			return 0;
		}
		c -= gcd(b,c);
	}
	return 0;
}
