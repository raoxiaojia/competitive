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

int n,m;

int p[1500000];

int visited[1500000];

vector<int> cycle;

ii item[1700000];

int dp[1200000];

deque<int> q;

int main()
{
	int i,j,k;
	cin>>n>>m;
	for (i=1;i<=n;i++)
	{
		cin>>p[i];
	}
	cycle.reserve(n);
	for (i=1;i<=n;i++)
	{
		if (visited[i] == 0)
		{
			visited[i] = 1;
			k = p[i];
			j = 1;
			while (k != i)
			{
				j++;
				visited[k] = 1;
				k = p[k];
			}
			cycle.push_back(j);
		}
	}
	sort(cycle.begin(),cycle.end());
/*	if (m == 1)
	{
		printf("2 2\n");
		return 0;
	}*/
	int icount = 1;
	int ccount = cycle.size();
	item[0].first = cycle[0];
	item[0].second = 1;
	for (i=1;i<ccount;i++)
	{
		if (cycle[i] == item[icount-1].first)
		{
			item[icount-1].second ++;
			continue;
		}
		item[icount].first = cycle[i];
		item[icount].second = 1;
		icount ++;
	}
	int ansmin = 0;
	int ansmax = 0;
	int tmp = m;
	for (i=0;i<icount;i++)
	{
		int ava = item[i].first / 2;
		ava *= item[i].second;
		if (tmp <= ava)
		{
			ansmax += tmp*2;
			tmp = 0;
			break;
		}
		ansmax += ava*2;
		tmp -= ava;
	}
	if (tmp != 0)
	{
		for (i=0;i<icount;i++)
		{
			int ava = item[i].first % 2;
			ava *= item[i].second;
			if (tmp <= ava)
			{
				ansmax += tmp;
				tmp = 0;
				break;
			}
			ansmax += ava;
			tmp -= ava;
		}
	}
	
	int ticount = icount;
	
	for (i=0;i<ticount;i++)
	{
		j = 1;
		while (item[i].second > j)
		{
			item[icount].first = j*item[i].first;
			item[i].second -= j;
			icount ++;
			j<<=1;
		}
		if (item[i].second != 0)
		{
			item[icount].first = item[i].second*item[i].first;
			icount ++;
		}
	}
	
	ansmin = 1;
	
	int realm = m;
	if (n-m<m) m = n-m;
	dp[0] = 1;
	for (i=0;i<m;i++)
	{
		if (dp[i] == 0) continue;
		for (j=ticount;j<icount;j++)
		{
			if (i+item[j].first > m)
			{
				icount = j;
				break;
			}
			dp[i+item[j].first] = 1;
		}
		if (dp[m] == 1)
		{
			break;
		}
	}
	if (dp[m] == 1) ansmin = 0;
	printf("%d %d\n",realm+ansmin,ansmax);
	return 0;
}
