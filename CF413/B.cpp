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

int p[300000],a[300000],b[300000],c[300000],d[300000];

typedef pair<int,int> ii;

vector<ii> info;

int dead[300000];

ii mp(int a,int b)
{
	ii res;
	res.first = a;
	res.second = b;
	return res;
}

bool cmp(ii a,ii b)
{
	if (a.first<b.first) return true;
	return false;
}

int main()
{
	int n,m;
	int i,j,k;
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{
		scanf("%d",&p[i]);
	}
	for (i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		d[i] |= (1<<(a[i]-1));
	}
	for (i=0;i<n;i++)
	{
		scanf("%d",&b[i]);
		d[i] |= (1<<(b[i]-1));
	}
	scanf("%d",&m);
	for (i=0;i<m;i++)
	{
		scanf("%d",&c[i]);
	}
	for (i=0;i<n;i++)
	{
		info.push_back(mp(p[i],i));
	}
	sort(info.begin(),info.end(),cmp);
	int cp1=-1,cp2=-1,cp3=-1;
	for (i=0;i<n;i++)
	{
		if (d[info[i].second]&1)
		{
			cp1 = i;
			break;
		}
	}
	for (i=0;i<n;i++)
	{
		if (d[info[i].second]&2)
		{
			cp2 = i;
			break;
		}
	}
	for (i=0;i<n;i++)
	{
		if (d[info[i].second]&4)
		{
			cp3 = i;
			break;
		}
	}
	for (i=0;i<m;i++)
	{
		if (c[i] == 1) {if (cp1 == -1) printf("-1 "); else {printf("%d ",info[cp1].first); dead[cp1] = 1;}} else
		if (c[i] == 2) {if (cp2 == -1) printf("-1 "); else {printf("%d ",info[cp2].first); dead[cp2] = 1;}} else
		if (c[i] == 3) {if (cp3 == -1) printf("-1 "); else {printf("%d ",info[cp3].first); dead[cp3] = 1;}}
		if (cp1 != -1)
		while ((dead[cp1]) || ((d[info[cp1].second] & 1) == 0))
		{
			cp1++;
			if (cp1>=n)
			{
				cp1 = -1;
				break;
			}
		}
		if (cp2 != -1)
		while (dead[cp2] || ((d[info[cp2].second] & 2 )== 0))
		{
			cp2++;
			if (cp2>=n)
			{
				cp2 = -1;
				break;
			}
		}
		if (cp3 != -1)
		while (dead[cp3] || ((d[info[cp3].second] & 4 )== 0))
		{
			cp3++;
			if (cp3>=n)
			{
				cp3 = -1;
				break;
			}
		}
	}
	return 0;
}
