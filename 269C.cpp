#include "bits/stdc++.h"

using namespace std;

int n,m;

typedef pair<int,int> ii;
typedef pair<ii,int> iii;
typedef vector<iii> viii;

viii g[300000];

long long total[300000];

int main()
{
	int i,j,k;
	scanf("%d %d",&n,&m);
	for (i=0;i<m;i++)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		g[a].emplace_back(b,c,0);
		g[b].emplace_back(a,c,0);
		total[a] += c;
		total[b] += c;
	}
	for (auto it=g[1].begin(); it != g[1].end();it++)
	{
		g[1].second = 1;
	}
	return 0;
}
