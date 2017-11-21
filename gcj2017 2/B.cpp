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

int t;

int n,m,c;

typedef pair<int,int> ii;

vector<ii> ticket;

ii mp(int x,int y)
{
	ii res;
	res.first = x;
	res.second = y;
	return res;
}

int ccount[2000];

int needsum[2000];

int need[2000];

int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	cin>>t;
	int i,j,k,l;
	for (l=0;l<t;l++)
	{
		memset(ccount,0,sizeof(ccount));
		memset(needsum,0,sizeof(needsum));
		memset(need,0,sizeof(need));
		cin>>n>>c>>m;
		ticket.clear();
		int ansmin = 0;
		for (i=0;i<m;i++)
		{
			cin>>j>>k;
			ticket.push_back(mp(j,k));
			ccount[k] ++;
			needsum[j] ++;
			need[j] ++;
		}
		for (i=1;i<=c;i++)
		{
			if (ccount[i] > ansmin) ansmin = ccount[i];
		}
		int seatans = 0;
		for (i=1;i<=n;i++)
		{
			needsum[i] += needsum[i-1];
			if ((needsum[i]-1)/i+1 > seatans) seatans = (needsum[i]-1)/i+1;
		}
		int ans = seatans>ansmin?seatans:ansmin;
		int promo = 0;
		for (i=1;i<=n;i++)
		{
			if (need[i]>ans) promo += need[i]-ans;
		}
		printf("Case #%d: %d %d\n",l+1,ans,promo);
	}
	return 0;
}
