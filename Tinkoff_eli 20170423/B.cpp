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

int n,m;

string grid[2000];

int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

int s1ok[2000][2000],t1ok[2000][2000];

int main()
{
	cin>>n>>m;
	int i,j,k;
	int sx,sy,tx,ty;
	for (i=0;i<n;i++)
	{
		cin>>grid[i];
		for (j=0;j<m;j++)
		{
			if (grid[i][j] == 'S')
			{
				sx = i;
				sy = j;
			}
			if (grid[i][j] == 'T')
			{
				tx = i;
				ty = j;
			}
		}
	}
	s1ok[sx][sy] = 1;
	for (k=0;k<4;k++)
	{
		i = sx - dir[k][0];
		j = sy - dir[k][1];
		while ((i>=0) && (i<n) && (j>=0) && (j<m))
		{
			if (grid[i][j] == 'T')
			{
				printf("YES\n");
				return 0;
			}
			if (grid[i][j] == '.')
			{
				s1ok[i][j] = 1;
			}
			else break;
			i -= dir[k][0];
			j -= dir[k][1];
		}
	}
	t1ok[tx][ty] = 1;
	for (k=0;k<4;k++)
	{
		i = tx - dir[k][0];
		j = ty - dir[k][1];
		while ((i>=0) && (i<n) && (j>=0) && (j<m))
		{
			if (grid[i][j] == 'S')
			{
				printf("YES\n");
				return 0;
			}
			if (grid[i][j] == '.')
			{
				if (s1ok[i][j])
				{
					printf("YES\n");
					return 0;
				}
				t1ok[i][j] = 1;
			}
			else break;
			i -= dir[k][0];
			j -= dir[k][1];
		}
	}
	for (i=0;i<n;i++)
	{
		for (j=0;j<m;j++)
		{
			if (!s1ok[i][j]) continue;
			for (k=0;k<4;k++)
	{
		int p = i - dir[k][0];
		int q = j - dir[k][1];
		while ((p>=0) && (p<n) && (q>=0) && (q<m))
		{
			if (grid[p][q] == 'T')
			{
				printf("YES\n");
				return 0;
			}
			if (grid[p][q] == '.')
			{
				if (t1ok[p][q])
				{
					printf("YES\n");
					return 0;
				}
			}
			else break;
			p -= dir[k][0];
			q -= dir[k][1];
		}
	}
		}
	}
	printf("NO\n");
	return 0;
}
