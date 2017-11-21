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
	int x;
	int i,j,k;
	vector<bool> pass;
	pass.clear();
	pass.reserve(150);
	cin>>n;
	cin>>x;
	for (i=1;i<=n;i++) pass[i] = false;
	for (i=0;i<x;i++)
	{
		cin>>j;
		pass[j] = true;
	}
	cin>>x;
	for (i=0;i<x;i++)
	{
		cin>>j;
		pass[j] = true;
	}
	j=0;
	for (i=1;i<=n;i++)
	{
		if (!pass[i])
		{
			j = 1;
			break;
		}
	}
	if (j) printf("Oh, my keyboard!\n");
	else printf("I become the guy.\n");
	return 0;
}
