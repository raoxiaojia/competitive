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
	cin>>n;
	if (n%2 == 0) printf("%d\n",n/2-1);
	else printf("%d\n",(n+1)/2-1);
	return 0;
}
