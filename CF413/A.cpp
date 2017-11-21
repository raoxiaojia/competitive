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
	long long n,t,k,d;
	cin>>n>>t>>k>>d;
	int i,j;
	long long tmpcake = d/t*k;
	if (tmpcake+k>=n) printf("NO\n");
	else printf("YES\n");
	return 0;
}
