#include "bits/stdc++.h"

using namespace std;

long long num;

int a,b;

vector<int> g[10];

int mat[3][3];

int visited[10];

vector<int> path;

void dfs(int cur)
{
	if (visited[cur]) return;
	visited[cur] = 1;
	path.push_back(cur);
	dfs(g[cur].front());
}

void score(int cur,long long& s1,long long& s2)
{
	switch (cur)
	{
		case 3:case 7:case 2: s1++;break;
		case 1:case 5:case 6: s2++;break;
	}
}

int main()
{
	int i,j,k;
	cin>>num>>a>>b;
	for (i=0;i<3;i++)
	{
		for (j=0;j<3;j++)
		{
			cin>>mat[i][j];
			mat[i][j] --;
			mat[i][j] *= 3;
		}
	}
	for (i=0;i<3;i++)
	{
		for (j=0;j<3;j++)
		{
			cin>>k;
			g[i*3+j].push_back(mat[i][j]+k-1);
		}
	}
	a = a*3+b-4;
	dfs(a);
	for (i=0;i<path.size();i++)
	{
		if (path[i] == g[path.back()].front()) break;
	}
	k=i;
	long long ans1,ans2;
	ans1 = 0;
	ans2 = 0;
	if (num <= k)
	{
		for (i=0;i<num;i++)
		{
			score(path[i],ans1,ans2);
		}
		printf("%I64d %I64d\n",ans1,ans2);
		return 0;
	}
	for (i=0;i<k;i++)
	{
		score(path[i],ans1,ans2);
	}
	num -= k;
	int clen = path.size()-k;
	long long cs1,cs2;
	cs1 = 0;
	cs2 = 0;
	for (i=k;i<path.size();i++)
	{
		score(path[i],cs1,cs2);
	}
	ans1 += cs1 * (num/clen);
	ans2 += cs2 * (num/clen);
	num %= clen;
	for (i=k;i<k+num;i++)
	{
		score(path[i],ans1,ans2);
	}
	printf("%I64d %I64d\n",ans1,ans2);
	return 0;
}
