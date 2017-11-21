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

long long g[3000][3000];

int contained[3000];

vector<int> minset;

long long minedge = 214748364711;

long long mfme[3000];

long long ans[3000];

int main()
{
	int n;
	int i,j,k;
	cin>>n;
	for (i=1;i<=n;i++)
	{
		for (j=i+1;j<=n;j++)
		{
			cin>>g[i][j];
			g[j][i] = g[i][j];
			if (g[i][j] < minedge) minedge = g[i][j];
		}
	}
	for (i=1;i<=n;i++)
	{
		for (j=i+1;j<=n;j++)
		{
			if (g[i][j] == minedge)
			{
				if (!contained[i])
				{
					minset.push_back(i);
					contained[i] = 1;
				}
				if (!contained[j])
				{
					minset.push_back(j);
					contained[j] = 1;
				}
			}
		}
	}
	for (i=1;i<=n;i++)
	{
		if (contained[i]) ans[i] = minedge*(n-1);
		else ans[i] = 1e16;
	}
	for (i=1;i<=n;i++)
	{
		if (contained[i])
		{
			continue;
		}
		mfme[i] = 2147483647112;
		for (j=0;j<minset.size();j++)
		{
			if (g[i][minset[j]] < mfme[i]) mfme[i] = g[i][minset[j]];
		}
		for (j=1;j<=n;j++)
		{
			if (contained[j]) continue;
			if (i == j) continue;
			long long tmp = mfme[i];
			if (g[i][j]<tmp) tmp = g[i][j];
			long long tmpans = minedge*(n-3)+g[i][j]+tmp;
			if (ans[j] > tmpans) ans[j] = tmpans;
		}
	}
	for (i=1;i<=n;i++)
	{
		if (contained[i]) continue;
		long long tmpans = minedge*(n-2)+mfme[i];
		if (ans[i]>tmpans) ans[i] = tmpans;
	}
	for (i=1;i<=n;i++)
	{
		cout<<ans[i]<<endl;
	}
	return 0;
}
