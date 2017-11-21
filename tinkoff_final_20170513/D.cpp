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

vector<int> g[400000];

int n,m;

deque<int> bq;

int dist[400000];

vector<int> dset[400000];

int d1dist[400000];

int d1node;

#define ADD 1234567

int d2dist[400000];

int d2node;

int sign[400000];

int main()
{
	int i,j,k;
	scanf("%d %d",&n,&m);
	for (i=0;i<m;i++)
	{
		scanf("%d %d",&j,&k);
		g[j].push_back(k);
		g[k].push_back(j);
	}
	for (i=0;i<=n;i++)
	{
		dist[i] = -1;
	}
	dist[1] = 0;
	bq.push_back(1);
	while (bq.size() > 0)
	{
		i = bq.front();
		bq.pop_front();
		for (j=0;j<g[i].size();j++)
		{
			if (dist[g[i][j]] == -1) 
			{
				dist[g[i][j]] = dist[i] + 1;
				bq.push_back(g[i][j]);
			}
			if (dist[g[i][j]] > 0)
			{
				if (dist[g[i][j]] > dist[i]+1)
				{
					printf("NO\n");
					return 0;
				}
			}
		}
	}
	for (i=2;i<=n;i++)
	{
		dset[dist[i]].push_back(i);
	}
	if (dset[i].size() == 1)
	{
		printf("YES\n");
		for (i=1;i<=n;i++)
		{
			printf("%d ",dist[i]+1);
		}
		printf("\n");
		return 0;
	}
	for (i=0;i<=n;i++)
	{
		d1dist[i] = -1;
	}
	d1node = dset[1][0];
	d1dist[d1node] = 0;
	bq.clear();
	bq.push_back(d1node);
	sign[d1node] = 1;
	while (bq.size() > 0)
	{
		i = bq.front();
		bq.pop_front();
		for (j=0;j<g[i].size();j++)
		{
			if (d1dist[g[i][j]] == -1) 
			{
				d1dist[g[i][j]] = d1dist[i] + 1;
				bq.push_back(g[i][j]);
			}
			if (d1dist[g[i][j]] > 0)
			{
				if (d1dist[g[i][j]] > d1dist[i]+1)
				{
					printf("NO\n");
					return 0;
				}
			}
		}
	}
	
	for (i=2;i<=n;i++)
	{
		if ((d1dist[i] == 1) && (dist[i] == 1)) sign[i] = 1;
	}
	
	j = 0;
	for (i=2;i<=n;i++)
	{
		if ((dist[i] == 1) && (sign[i] == 0))
		{
			j = 1;
			break;
		}
	}
	if (j == 0)
	{
		printf("YES\n");
		for (i=1;i<=n;i++)
		{
			printf("%d ",dist[i]+1);
		}
		printf("\n");
		return 0;
	}
	
	
	
	d2node = i;
	for (i=0;i<=n;i++)
	{
		d2dist[i] = -1;
	}
	d2dist[d2node] = 0;
	sign[d2node] = -1;
	bq.clear();
	bq.push_back(d2node);
	while (bq.size() > 0)
	{
		i = bq.front();
		bq.pop_front();
		for (j=0;j<g[i].size();j++)
		{
			if (d2dist[g[i][j]] == -1) 
			{
				d2dist[g[i][j]] = d2dist[i] + 1;
				bq.push_back(g[i][j]);
			}
			if (d2dist[g[i][j]] > 0)
			{
				if (d2dist[g[i][j]] > d2dist[i]+1)
				{
					printf("NO\n");
					return 0;
				}
			}
		}
	}
	
	
	for (i=2;i<=n;i++)
	{
		if (i == d1node) continue;
		if (i == d2node) continue;
		if (d1dist[i] == 1)
		{
			if (d2dist[i] == 1) sign[i] = 77;
		}
		if (d1dist[i] == 2)
		{
			if (d2dist[i] == 2)
			{
				printf("NO\n");
				return 0;
			}
			sign[i] = -1;
		}
	}
	bq.clear();
	memset(dist,0,sizeof(dist));
	for (i=0;i<=n;i++)
	{
		dist[i] = -1;
	}
	dist[1] = 0;
	bq.push_back(1);
	for (i=2;i<=n;i++)
	{
		if (sign[i] == 77)
		{
			dist[i] = 0;
			bq.push_back(i);
		}
	}
	while (bq.size() > 0)
	{
		i = bq.front();
		bq.pop_front();
		for (j=0;j<g[i].size();j++)
		{
			if (dist[g[i][j]] == -1) 
			{
				if ((sign[g[i][j]] == 0) || (sign[g[i][j]] == 77))
				{
					sign[g[i][j]] = sign[i];
				}
				else
				{
					if ((sign[g[i][j]] == 1) && (sign[i] == -1))
					{
						printf("NO\n");
						return 0;
					}
					if ((sign[g[i][j]] == -1) && (sign[i] == 1))
					{
						printf("NO\n");
						return 0;
					}
				}
				dist[g[i][j]] = dist[i] + 1;
				bq.push_back(g[i][j]);
			}
			if (dist[g[i][j]] > 0)
			{
				if (dist[g[i][j]] > dist[i]+1)
				{
					printf("NO\n");
					return 0;
				}
			}
		}
	}
	printf("YES\n");
	for (i=1;i<=n;i++)
	{
		if ((sign[i] == 0) || (sign[i] == 77))
		{
			printf("%d ",ADD);
		}
		else
		if (sign[i] == 1)
		{
			printf("%d ",ADD+dist[i]);
		}
		else
		{
			printf("%d ",ADD-dist[i]);
		}
	}
	return 0;
}
