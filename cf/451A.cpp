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
	int n,m;
	cin>>n>>m;
	if (n>m) n = m;
	if (n%2 == 0) printf("Malvika\n");
	else printf("Akshat\n");
	return 0;
}
