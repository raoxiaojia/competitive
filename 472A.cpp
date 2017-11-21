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
	if (n%4 == 0) printf("%d %d\n",n/2,n/2);
	else if (n%2 == 0) printf("%d %d\n",n/2+1,n/2-1);
	else printf("9 %d\n",n-9);
	return 0;
}
