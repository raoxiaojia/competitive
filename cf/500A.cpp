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
	vector<int> dist;
	dist.clear();
	dist.reserve(50000);
	int n,m,i;
	cin>>n>>m;
	for (i=1;i<n;i++)
	{
		cin>>dist[i];
	}
	i = 1;
	while (i<m)
	{
		i += dist[i];
	}
	if (i==m) printf("YES\n");
	else printf("NO\n");
	return 0;
}
