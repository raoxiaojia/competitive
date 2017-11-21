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

int n;

int coord[2000][5];

int dist(int a,int b)
{
	int tmp = 0;
	for (int i=0;i<5;i++)
	{
		tmp += (coord[a][i]-coord[b][i])*(coord[a][i]-coord[b][i]);
	}
	return tmp;
}

int eliminate(int a,int b,int c)
{
	int dab=dist(a,b);
	int dbc=dist(b,c);
	int dac=dist(a,c);
	if (dab+dbc>dac) return b;
	if (dab+dac>dbc) return a;
	return c;
}

int main()
{
	cin>>n;
	int i,j,k;
	for (i=0;i<n;i++)
	{
		for (j=0;j<5;j++)
		{
			cin>>coord[i][j];
		}
	}
	if (n==2)
	{
		printf("2\n1\n2\n");
		return 0;
	}
	if (n==1)
	{
		printf("1\n1\n");
		return 0;
	}
	int ga = 0;
	int gb = 1;
	for (i=2;i<n;i++)
	{
		int x = eliminate(ga,gb,i);
		if (i == x) continue;
		if (ga == x)
		{
			ga = gb;
			gb = i;
		}
		else
		{
			gb = i;
		}
	}
	for (i=0;i<n;i++)
	{
		for (j=i+1;j<n;j++)
		{
			if (i == ga) continue;
			if (j == ga) continue;
			if (dist(i,ga)+dist(ga,j) > dist(i,j))
			{
				ga = -1;
				break;
			}
		}
		if (ga == -1) break;
	}
	for (i=0;i<n;i++)
	{
		for (j=i+1;j<n;j++)
		{
			if (i == gb) continue;
			if (j == gb) continue;
			if (dist(i,gb)+dist(gb,j) > dist(i,j))
			{
				gb = -1;
				break;
			}
		}
		if (gb == -1) break;
	}
	int ans = 0;
	if (ga != -1) ans ++;
	if (gb != -1) ans++;
	printf("%d\n",ans);
	if (ga != -1) printf("%d\n",ga+1);
	if (gb != -1) printf("%d\n",gb+1);
	return 0;
}
