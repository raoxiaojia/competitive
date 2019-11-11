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
	int i,j,k = 0;
	for (i=0;i<n;i++)
	{
		cin>>j;
		k += j;
	}
	printf("%.8lf\n",(double)k/n);
	return 0;
}
