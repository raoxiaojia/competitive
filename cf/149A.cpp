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

vector<int> growth;

int main()
{
	int n;
	int i,j;
	cin>>n;
	for (i=0;i<12;i++)
	{
		cin>>j;
		growth.push_back(j);
	}
	sort(growth.begin(),growth.end());
	i = 12;
	while ((n>0) && (i>0))
	{
		i--;
		n -= growth[i];
	}
	if (n<=0) printf("%d\n",12-i);
	else printf("-1\n");
	return 0;
}
