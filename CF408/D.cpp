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

vector<ii> con[500000];

int stapos[500000];

int dist[500000];

ii mp(int x,int y)
{
	ii res;
	res.first = x;
	res.second = y;
	return res;
}

int n,m,d;

int down[500000];

int visited[500000];

int main()
{
	cin>>n>>m>>d;
	int i,j,k;
	for (i=0;i<m;i++)
	{
		scanf("%d",&j);
		stapos[j] = 1;
	}
	for (i=0;i<n-1;i++)
	{
		cin>>j>>k;
		con[j].push_back(mp(k,i+1));
		con[k].push_back(mp(j,i+1));
	}
	m=0;
	for (i=1;i<=n;i++)
	{
		m+=stapos[i];
	}
	cout<<m-1<<endl;
	deque<int> q;
	q.clear();
	for (i=1;i<=n;i++)
	{
		if (stapos[i])
		{
			q.push_back(i);
			visited[i] = 1;
		}
	}
	while (q.size()>0)
	{
		k = q.front();
		j = con[k].size();
		for (i=0;i<j;i++)
		{
			if ((visited[con[k][i].first]) && (dist[con[k][i].first] >= dist[k]))
			{
				if (down[con[k][i].second] == 0)
				{
					down[con[k][i].second] = 1;
					printf("%d ",con[k][i].second);
				}
			}
			else
			if (visited[con[k][i].first] == 0)
			{
				visited[con[k][i].first] = 1;
				q.push_back(con[k][i].first);
				dist[con[k][i].first] = dist[k] + 1;
			}
		}
		q.pop_front();
	}
	return 0;
}
