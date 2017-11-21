#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <ctime>

using namespace std;

typedef pair<int,int> ii;

typedef vector<ii> vii;

long long dist[100005];

auto comp = [](int x,int y) {
	return dist[x]>dist[y];
};

priority_queue<int,vector<int>, decltype(comp)> q(comp);

vii g[100005];

int n,m;

int exist[100005];

int src[100005];

int fixed2[100005];

ii makepair(int a,int b)
{
	ii res;
	res.first = a;
	res.second = b;
	return res;
}

void printpath(int x)
{
	if (x != 1) printpath(src[x]);
	printf("%d ",x);
}

int main()
{
	cin>>n>>m;
	srand(time(NULL));
	int i,j,k;
	int a,b,c;
	for (i=0;i<m;i++)
	{
		cin>>a>>b>>c;
		g[a].push_back(makepair(b,c));
		g[b].push_back(makepair(a,c));
	}
	for (i=2;i<=n;i++)
	{
		dist[i] = 1e15;
	}
	dist[1] = 0;
	q.push(1);
	while (q.size()>0)
	{
		int x = q.top();
		q.pop();
		if (fixed2[x]) continue;
		fixed2[x] = 1;
		for (i=0;i<g[x].size();i++)
		{
			if (dist[x]+g[x][i].second < dist[g[x][i].first])
			{
				dist[g[x][i].first] = dist[x]+g[x][i].second;
				src[g[x][i].first] = x;
				q.push(g[x][i].first);
			}
		}
	}
	if (src[n] == 0)
	{
		printf("-1\n");
		return 0;
	}
	printpath(n);
	return 0;
}
