#include <bits/stdc++.h>

using namespace std;

int n;

typedef vector<int> vi;

vi g[100005];

typedef pair<int,int> ii;

typedef pair<ii,int> iii;

vector<iii> coord;

int visited[100005];

long long ans = 1;

const long long pmod = 1000000007;

long long expsize;

set<int> x,y;

bool cycle;

int mapback[100005];

long long qpmod(long long b,long long e)
{
	long long cur = b;
	long long res = 1;
	while (e)
	{
		if (e%2 == 1)
		{
			res = res * cur % pmod;
		}
		e /= 2;
		cur = cur * cur % pmod;
	}
	return res;
}

iii m3(int a,int b,int c)
{
	iii res;
	res.first.first = a;
	res.first.second = b;
	res.second =c;
	return res;
}

bool cmpx(iii x,iii y)
{
	if (x.first.first<y.first.first) return true;
	if ((x.first.first == y.first.first) && (x.first.second<y.first.second)) return true;
	return false;
}

bool cmpy(iii x,iii y)
{
	if (x.first.second<y.first.second) return true;
	if ((x.first.second == y.first.second) && (x.first.first<y.first.first)) return true;
	return false;
}

void dfs(int last,int cur)
{
	expsize ++;
	visited[cur] = 1;
	x.insert(coord[mapback[cur]].first.first);
	y.insert(coord[mapback[cur]].first.second);
	int i;
	for (i=0;i<g[cur].size();i++)
	{
		if (g[cur][i] == last) continue;
		if (visited[g[cur][i]])
		{
			cycle = true;
			continue;
		}
		dfs(cur,g[cur][i]);
	}
}

int main()
{
	scanf("%d",&n);
	int i,j,k;
	for (i=0;i<n;i++)
	{
		scanf("%d %d",&j,&k);
		coord.push_back(m3(j,k,i));
	}
	//x edges
	sort(coord.begin(),coord.end(),cmpx);
	for (i=1;i<n;i++)
	{
		if (coord[i].first.first == coord[i-1].first.first)
		{
			g[coord[i].second].push_back(coord[i-1].second);
			g[coord[i-1].second].push_back(coord[i].second);
		}
	}
	//y edges
	sort(coord.begin(),coord.end(),cmpy);
	for (i=1;i<n;i++)
	{
		if (coord[i].first.second == coord[i-1].first.second)
		{
			g[coord[i].second].push_back(coord[i-1].second);
			g[coord[i-1].second].push_back(coord[i].second);
		}
	}
	for (i=0;i<n;i++)
	{
		mapback[coord[i].second] = i;
	}
	for (i=0;i<n;i++)
	{
		if (visited[i] == 0)
		{
			x.clear();
			y.clear();
			cycle = false;
			dfs(i,i);
			expsize = x.size()+y.size();
			if (cycle)
			{
				ans = ans * qpmod(2,expsize) % pmod;
			}
			else
			{
				ans = ans * ((qpmod(2,expsize) + pmod - 1) % pmod) % pmod;
			}
		}
	}
	
	printf("%d\n",(int)ans);
	
	return 0;
}
