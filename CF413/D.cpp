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

int a,b,h,w,n;

vector<int> ext;

bool cmp(int x,int y)
{
	if (x>y) return true;
	return false;
}

int ans = 100;

int na,nb;

void dfs(int d,long long x,long long y)
{
	if (d>=ans) return;
	if ((x>=a) && (y>=b))
	{
		if (d<ans) ans = d;
		return;
	}
	if (d>=n) return;
	if (ext[d] == 2)
	{
		int i,j,k;
		while ((d<n) && (x<a))
		{
			d++;
			x *= 2;
		}
		if (x<a) return;
			while ((d<n) && (y<b))
			{
				d++;
				y *= 2;
			}
		if (y<b) return;
		if (d<ans) ans = d;
		return;
	}
	if (x<a)
	dfs(d+1,x*ext[d],y);
	if (y<b)
	dfs(d+1,x,y*ext[d]);
}

int main()
{
	cin>>a>>b>>h>>w>>n;
	int i,j,k;
	for (i=0;i<n;i++)
	{
		scanf("%d",&j);
		ext.push_back(j);
	}
	sort(ext.begin(),ext.end(),cmp);
	dfs(0,h,w);
	dfs(0,w,h);
	if (ans < 100)
	printf("%d\n",ans);
	else printf("-1\n");
	return 0;
}
