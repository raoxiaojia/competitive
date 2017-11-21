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

vector<int> color[500000];

vector<int> graph[500000];

int ans[500000];

int visited[500000];

int aux[500000];

void dfs(int x)
{
	visited[x] = 1;
	int i,j;
	for (i=0;i<color[x].size();i++)
	{
		if (ans[color[x][i]] > 0) 
		{
			aux[ans[color[x][i]]] = x;
		}
	}
	j = 1;
	for (i=0;i<color[x].size();i++)
	{
		if (ans[color[x][i]] > 0) continue;
		while (aux[j] == x) 
		{
			j++;
		//	printf("%d\n",j);
		}
		ans[color[x][i]] = j;
		aux[j] = x;
	}
	for (i=0;i<graph[x].size();i++)
	{
		if (!visited[graph[x][i]]) dfs(graph[x][i]);
	}
}

int main()
{
	int i,j,k,l;
	int max = 0;
	int maxj = 0;
	cin>>n>>m;
	for (i=0;i<n;i++)
	{
		scanf("%d",&k);
		if (k>max)
		{
			max = k;
			maxj = i+1;
		}
		while (k)
		{
			k--;
			scanf("%d",&j);
			color[i+1].push_back(j);
		}
	}
	for (i=0;i<n-1;i++)
	{
		scanf("%d %d",&j,&k);
		graph[j].push_back(k);
		graph[k].push_back(j);
	}
	if (max <= 1)
	{
		printf("1\n");
		for (i=0;i<m;i++)
		{
			printf("1 ");
		}
		printf("\n");
		return 0;
	}
	printf("%d\n",max);
	for (i=0;i<max;i++)
	{
		ans[color[maxj][i]] = i+1;
	}
	visited[maxj] = 1;
	for (i=0;i<graph[maxj].size();i++)
	{
		if (!visited[graph[maxj][i]])
		dfs(graph[maxj][i]);
	}
	for (i=1;i<=m;i++)
	{
		printf("%d ",ans[i]);
	}
	printf("\n");
	return 0;
}
