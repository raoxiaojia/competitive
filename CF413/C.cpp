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

int n,c,d;

typedef pair<int,int> ii;

ii mp(int a,int b)
{
	ii res;
	res.first = a;
	res.second = b;
	return res;
}

vector<ii> coin,diamond;

bool cmp(ii a,ii b)
{
	if (a.first<b.first) return true;
	if ((a.first==b.first) && (a.second>b.second)) return true;
	return false;
}

int bestc[200000],bestd[200000];

int bcp[200000],bdp[200000];

int main()
{
	int i,j,k;
	scanf("%d %d %d",&n,&c,&d);
	for (i=0;i<n;i++)
	{
		int b,p;
		char ch;
		scanf("%d %d %c",&b,&p,&ch);
		if (ch == 'C')
		{
			coin.push_back(mp(p,b));
		}
		else
		{
			diamond.push_back(mp(p,b));
		}
	}
	if (coin.size() > 0)
	sort(coin.begin(),coin.end(),cmp);
	if (diamond.size() > 0)
	sort(diamond.begin(),diamond.end(),cmp);
	long long ans = 0;
	if ((coin.size()>0) && (diamond.size()>0))
	{
		k=-1;
		for (i=0;i<coin.size();i++)
		{
			if (coin[i].first>c) break;
			if (coin[i].second>k) k=coin[i].second;
		}
		ans = k;
		k=-1;
		for (i=0;i<diamond.size();i++)
		{
			if (diamond[i].first>d) break;
			if (diamond[i].second>k) k=diamond[i].second;
		}
		if (ans != -1)
		{
			if (k == -1) ans = -1;
			else ans += k;
		}
	}
	if (coin.size()>=2)
	{
		bestc[0] = coin[0].second;
		bcp[0] = 0;
		for (i=1;i<coin.size();i++)
		{
			bestc[i] = (coin[i].second>bestc[i-1])?coin[i].second:bestc[i-1];
			bcp[i] = (bestc[i]>bestc[i-1])?i:bcp[i-1];
		}
		int cp = coin.size()-1;
		i = 0;
		while (i<cp)
		{
			if (bcp[i] != i)
			{
				i++;
				continue;
			}
			while (coin[cp].first+coin[i].first > c)
			{
				cp--;
				if (bcp[cp] <= i) break;
				cp = bcp[cp];
			}
			if (cp <= i) break;
			if (bcp[cp]>=i)
			for (j=cp;j>=bcp[cp];j--)
			{
				if (j <= i) break;
				if (coin[j].second+coin[i].second > ans) ans = coin[j].second+coin[i].second;
			}
			else
			if (coin[i].second+bestc[cp]>ans) ans = coin[i].second+bestc[cp];
			i++;
		}
	}
	if (diamond.size()>=2)
	{
		bestd[0] = diamond[0].second;
		bdp[0] = 0;
		for (i=1;i<diamond.size();i++)
		{
			bestd[i] = (diamond[i].second>bestd[i-1])?diamond[i].second:bestd[i-1];
			bdp[i] = (bestd[i]>bestd[i-1])?i:bdp[i-1];
		}
		int cp = diamond.size()-1;
		i = 0;
		while (i<cp)
		{
			if (bdp[i] != i)
			{
				i++;
				continue;
			}
			while (diamond[cp].first+diamond[i].first > d)
			{
				cp--;
				if (bdp[cp] <= i) break;
				cp = bdp[cp];
			}
			if (cp <= i) break;
			if (bdp[cp]>=i)
			for (j=cp;j>=bdp[cp];j--)
			{
				if (j <= i) break;
				if (diamond[i].second+diamond[j].second > ans) ans = diamond[i].second+diamond[j].second;
			}
			else
			if (diamond[i].second+bestd[cp] > ans) ans = diamond[i].second+bestd[cp];
			i++;
		}
	}
	if (ans<0) ans = 0;
	printf("%d\n",ans);
	return 0;
}
