#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n,m;

typedef pair<int,int> ii;

typedef pair<int,ii> iii;

vector<iii> range;

priority_queue<int> q;

int ans,ansl,ansr;

bool cmp(iii x,iii y)
{
	if (x.second.second<y.second.second) return true;
	if ((x.second.second == y.second.second) && (x.second.first < y.second.first)) return true;
	return false;
}

int main()
{
	cin>>n>>m;
	int i,j,k;
	range.reserve(n);
	for (i=0;i<n;i++)
	{
		cin>>j>>k;
		ii tmp;
		tmp.first = j;
		tmp.second = k;
		iii tmp2;
		tmp2.first = i+1;
		tmp2.second = tmp;
		range.push_back(tmp2);
	}
	sort(range.begin(),range.end(),cmp);
	ans = -1;
	for (i=n-1;i>=0;i--)
	{
		if (q.size() == m)
		{
			q.push(range[i].second.first);
			q.pop();
		}
		else
			q.push(range[i].second.first);
		if (q.size() == m)
		{
			int tmp = q.top();
			if (tmp <= range[i].second.second)
			{
				if (range[i].second.second-tmp+1 > ans)
				{
					ans = range[i].second.second-tmp+1;
					ansl = tmp;
					ansr = range[i].second.second;
				}
			}
		}
	}
	if (ans == -1)
	{
		printf("0\n");
		for (i=0;i<m;i++)
		{
			printf("%d ",i+1);
		}
		printf("\n");
	}
	else
	{
		printf("%d\n",ans);
		i = 0;
		while (m)
		{
			if ((range[i].second.first <= ansl) && (range[i].second.second >= ansr))
			{
				printf("%d ",range[i].first);
				m--;
			}
			i++;
		}
		printf("\n");
	}
	return 0;
}
