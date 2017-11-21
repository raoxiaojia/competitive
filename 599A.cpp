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
	int a,b,c;
	cin>>a>>b>>c;
	c=a+b<c?a+b:c;
	a=b+c<a?b+c:a;
	b=a+c<b?a+c:b;
	printf("%d\n",a+b+c);
	return 0;
}
