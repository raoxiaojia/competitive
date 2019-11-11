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
	scanf("%d %d %d",&a,&b,&c);
	b -= (1+c)*c/2*a;
	if (b>0) printf("0\n");
	else printf("%d\n",-b);
	return 0;
}
