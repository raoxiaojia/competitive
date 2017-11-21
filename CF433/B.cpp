#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

typedef vector<int> vi;

typedef deque<int> di;

typedef pair<int,int> ii;

typedef pair<ii,ii> i4;

di dep[100005];

di ret[100005];

typedef deque<ii> dii;

dii cd,cr;

vector<i4> flight;

int n,m,k;

long long ans;

ii mp(int a,int b)
{
	ii res;
	res.first = a;
	res.second = b;
	return res;
}

i4 mi4(int a,int b,int c,int d)
{
	ii x1,x2;
	i4 res;
	x1.first = a;
	x1.second = b;
	x2.first = c;
	x2.second=d;
	res.first = x1;
	res.second = x2;
	return res;
}

bool cmp(i4 x,i4 y)
{
	if (x.first.first<y.first.first) return true;
	return false;
}

bool cmp2(ii x,ii y)
{
	if (x.first<y.first) return true;
	return false;
}

di dtime[100005],rtime[100005];

int main()
{
	cin>>n>>m>>k;
	if (m<2*n)
	{
		printf("-1\n");
		return 0;
	}
	int i,j;
	int d,f,t,c;
	for (i=0;i<m;i++)
	{
		cin>>d>>f>>t>>c;
		flight.push_back(mi4(d,f,t,c));
	}
	sort(flight.begin(),flight.end(),cmp);
	for (i=0;i<flight.size();i++)
	{
		if (flight[i].first.second != 0)
		{
			//departure
			int x = flight[i].first.second;
			if (dtime[x].size() == 0)
			{
				dtime[x].push_back(flight[i].first.first);
				dep[x].push_back(flight[i].second.second);
			}
			else
			if (flight[i].second.second < dep[x].back())
			{
				while (dtime[x].size()>0)
				{
					if (dtime[x].back() == flight[i].first.first)
					{
						dtime[x].pop_back();
						dep[x].pop_back();
					}
					else break;
				}
				dtime[x].push_back(flight[i].first.first);
				dep[x].push_back(flight[i].second.second);
			}
		}
		else
		{
			//return
			int x = flight[i].second.first;
			if (rtime[x].size() == 0)
			{
				rtime[x].push_back(flight[i].first.first);
				ret[x].push_back(flight[i].second.second);
			}
			else
			{
				while (rtime[x].size()>0)
				{
					if (ret[x].back() >= flight[i].second.second)
					{
						rtime[x].pop_back();
						ret[x].pop_back();
					}
					else break;
				}
				rtime[x].push_back(flight[i].first.first);
				ret[x].push_back(flight[i].second.second);
			}
		}
	}
	
	int ctime = 0;
	
	for (i=1;i<=n;i++)
	{
		if (dtime[i].size() == 0)
		{
			printf("-1");
			return 0;
		}
		if (dtime[i].front() > ctime) ctime = dtime[i].front();
	}
	ctime ++;
	int stime = ctime+k-1;
	bool ok = true;
	for (i=1;i<=n;i++)
	{
		while (dtime[i].size() > 1)
		{
			if (dtime[i][1] <= ctime-1)
			{
				dtime[i].pop_front();
				dep[i].pop_front();
			}
			else break;
		}
		if (rtime[i].size() == 0)
		{
			ok = false;
			break;
		}
		while (rtime[i].front() <= stime)
		{
			if (rtime[i].size() == 0)
			{
				ok = false;
				break;
			}
			rtime[i].pop_front();
			ret[i].pop_front();
			if (rtime[i].size() == 0)
			{
				ok = false;
				break;
			}
		}
		if (!ok) break;
	}
	if (!ok)
	{
		printf("-1");
		return 0;
	}
	ans = 1e16;
	long long cur = 0;
	for (i=1;i<=n;i++)
	{
		cur += ret[i].front();
		cur += dep[i].front();
		for (j=0;j<dtime[i].size();j++)
		{
			cd.push_back(mp(dtime[i][j]+1,i));
		}
		for (j=0;j<rtime[i].size();j++)
		{
			cr.push_back(mp(rtime[i][j],i));
		}
	}
	sort(cd.begin(),cd.end(),cmp2);
	sort(cr.begin(),cr.end(),cmp2);
	ans = cur;
	while (ok)
	{
		ctime ++;
		stime ++;
		while (cd.front().first == ctime)
		{
			int x = cd.front().second;
			if (dtime[x].size() == 1)
			{
				cd.pop_front();
				continue;
			}
			cur -= dep[x].front();
			dep[x].pop_front();
			dtime[x].pop_front();
			cur += dep[x].front();
			cd.pop_front();
		}
		while (cr.front().first == stime)
		{
			int x = cr.front().second;
			if (rtime[x].size() == 1)
			{
				ok = false;
				break;
			}
			cur -= ret[x].front();
			ret[x].pop_front();
			rtime[x].pop_front();
			cur += ret[x].front();
			cr.pop_front();
		}
		if (!ok) break;
		if (cur<ans) ans = cur;
	}
	cout<<ans<<endl;
	return 0;
}
