#include "bits/stdc++.h"

using namespace std;

int n;

typedef vector<int> vi;
typedef pair<int,int> ii;

vi g[250000];

deque<int> ans;

int key[200005];

int dist[200005];

int main()
{
	scanf("%d",&n);
	int i,j,k;
	vector<ii> stack;
	stack.clear();
	for (i=1;i<=n;i++)
	{
		scanf("%d",&k);
		key[i] = k;
		while ((stack.size()>0) && (stack.back().first < k)) stack.pop_back();
		if (stack.size() == 0)
		{
			g[0].push_back(i);
			stack.emplace_back(k,i);
		}
		else
		{
			g[stack.back().second].push_back(i);
			stack.emplace_back(k,i);
		}
	}
	ans.push_back(0);
	int cur = 0;
	while (cur<ans.size())
	{
		int x = ans[cur];
		for (auto it=g[x].begin();it != g[x].end();it++)
		{
			ans.push_back(*it);
			dist[*it] = dist[x] + 1;
		}
	}
	int curdist = 1;
	for (i=0;i<n;i++)
	{
		printf("%d ",ans[i]);
		if (dist[ans[i]] != curdist)
		{
			printf("\n");
			curdist = dist[ans[i]];
		}
	}
	return 0;
}
