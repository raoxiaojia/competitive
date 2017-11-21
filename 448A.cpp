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
	int a,b,c,d,e,f,n;
	cin>>a>>b>>c>>d>>e>>f>>n;
	n -= (a+b+c+4) / 5;
	n -= (d+e+f+9) / 10;
	if (n>=0) printf("YES\n");
	else printf("NO\n");
	return 0;
}
