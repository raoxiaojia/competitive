#include "bits/stdc++.h"
using namespace std;

int n;

int f[100005];

int cnt[100005];

vector<int> gsize;

int find(int x)
{
	if (f[x] == x) return x;
	f[x] = find(f[x]);
	return f[x];
}

void sunion(int x,int y)
{
	if (find(x) == find(y)) return;
	f[y] = f[x];
}

int main()
{
	int i,j,k;
	cin>>n;
	for (i=1;i<=n;i++) f[i] = i;
	for (i=1;i<=n;i++)
	{
		cin>>j;
		sunion(i,j);
	}
	for (i=1;i<=n;i++)
	{
		cnt[find(i)] ++;
	}
	for (i=1;i<=n;i++)
	{
		if (cnt[i] > 0) gsize.push_back(cnt[i]);
	}
	sort(gsize.begin(),gsize.end());
	if (gsize.size() >=2)
	{
		k = gsize.back();
		gsize.pop_back();
		k += gsize.back();
		gsize.pop_back();
		gsize.push_back(k);
	}
	long long ans =0;
	for (auto it=gsize.begin();it != gsize.end();it++)
	{
		ans += (long long )(*it)*(*it);
	}
	cout<<ans<<endl;
	return 0;
}
