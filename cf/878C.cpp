#include "bits/stdc++.h"
using namespace std;

int att[10];

struct scc
{
	int ub[10],lb[10];
	int size;
	scc()
	{
		memcpy(ub,att,sizeof(att));
		memcpy(lb,att,sizeof(att));
		size = 1;
	}
	scc operator += (const scc &x)
	{
		size += x.size;
		for (int i=0;i<10;i++)
		{
			ub[i] = max(ub[i],x.ub[i]);
			lb[i] = min(lb[i],x.lb[i]);
		}
	}
	bool operator < (const scc &x) const
	{
		return ub[0] < x.ub[0];
	}
};

set<scc> groups;

int n,m;

int main()
{
	int i,j,k;
	scanf("%d %d",&n,&m);
	for (i=0;i<n;i++)
	{
		for (j=0;j<m;j++)
		{
			scanf("%d",&att[j]);
		}
		scc cur;
		while (groups.size()>0)
		{
			auto it = groups.lower_bound(cur);
			if (it == groups.begin()) break;
			it --;
			int b=0,s=0;
			for (k=0;k<m;k++)
			{
				if (it->ub[k] > cur.lb[k]) b=1;
				if (cur.ub[k] > it->lb[k]) s=1;
			}
			if (s&b)
			{
				cur += *it;
				groups.erase(it);
			}
			else break;
		}
		while (groups.size()>0)
		{
			auto it = groups.lower_bound(cur);
			if (it == groups.end()) break;
			int b=0,s=0;
			for (k=0;k<m;k++)
			{
				if (it->ub[k] > cur.lb[k]) b=1;
				if (cur.ub[k] > it->lb[k]) s=1;
			}
			if (s&b)
			{
				cur += *it;
				groups.erase(it);
			}
			else break;
		}
		groups.insert(cur);
		printf("%d\n",(--groups.end())->size);
	}
	return 0;
}
