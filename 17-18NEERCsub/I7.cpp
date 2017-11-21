#include "bits/stdc++.h"

using namespace std;

int n,m,p,q;

int dir[4][2]=
{
	{1,0},
	{0,1},
	{0,-1},
	{-1,0}
};

long long ans[300][300];

string grid[300];

typedef pair<int,int> ii;
typedef pair<ii,int> iii;

int visited[300][300];

iii m3(int x,int y,int z)
{
	iii res;
	res.first.first = x;
	res.first.second = y;
	res.second = z;
	return res;
}

void bfs(int x,int y,int st)
{
	deque<iii> q;
	q.clear();
	q.push_back(m3(x,y,st));
	ans[x][y] += st;
	visited[x][y] = x*m+y+1;
	while (q.size()>0)
	{
		int sx = q[0].first.first;
		int sy = q[0].first.second;
		int noise = q[0].second;
		for (int i=0;i<4;i++)
		{
			int tx = sx + dir[i][0];
			int ty = sy + dir[i][1];
			if ((tx < 0) || (tx >= n) || (ty < 0) || (ty >= m)) continue;
			if (grid[tx][ty] == '*') continue;
			if (visited[tx][ty] == x*m+y+1) continue;
			visited[tx][ty] = x*m+y+1;
			ans[tx][ty] += noise/2;
			if (noise/2>1)
			{
				q.push_back(m3(tx,ty,noise/2));
			}
		}
		q.pop_front();
	}
}

int main()
{
	cin>>n>>m>>q>>p;
	int i,j,k;
	for (i=0;i<n;i++)
	{
		cin>>grid[i];
	}
	for (i=0;i<n;i++)
	{
		for (j=0;j<m;j++)
		{
			if (grid[i][j] >= 'A')
			{
				int strength = (grid[i][j]-'A'+1)*q;
				bfs(i,j,strength);
			}
		}
	}
	k = 0;
	for (i=0;i<n;i++)
	{
		for (j=0;j<m;j++)
		{
			if (ans[i][j] > p) k++;
	//		printf("%d ",ans[i][j]);
		}
	//	printf("\n");
	}
	cout<<k<<endl;
	return 0;
}

