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

typedef pair<int,int> ii;

int main()
{
	int n;
	ii color[200];
	memset(color,0,sizeof(color));
	cin>>n;
	int i,j,ans=0;
	for (i=0;i<n;i++)
	{
		cin>>color[i].first>>color[i].second;
	}
	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
		{
			if (i==j) continue;
			if (color[i].first == color[j].second) ans++;
		}
	}
	cout<<ans;
	return 0;
}
