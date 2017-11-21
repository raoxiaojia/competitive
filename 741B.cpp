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

int weight[2000],beauty[2000];

int fship[2000][2000];

int group[2000];

int ig[2000][2000];

int f[2000];

int g[2000];

int used[2000];

int igpoint[2000][2000];

int igpointcount[2000];

int inum;

int ffind(int x)
{
	if (group[x] == x) return x;
	int t = ffind(group[x]);
	group[x] = t;
	return t;
}

void funion(int x,int y)
{
	int tx,ty;
	tx = ffind(x);
	ty = ffind(y);
	group[ty] = tx;
}

int main()
{
	int n,m,w;
	cin>>n>>m>>w;
	int i,j,k;
	for (i=0;i<n;i++)
	{
		cin>>weight[i];
	}
	for (i=0;i<n;i++)
	{
		cin>>beauty[i];
		group[i] = i;
	}
	for (i=0;i<m;i++)
	{
		cin>>j>>k;
		j--;
		k--;
		funion(j,k);
	}
//	for (i=0;i<n;i++) cout<<group[i]<<endl;
	
	for (i=0;i<n;i++)
	{
		if (group[i] != i) continue;
//		cout<<i<<endl;
		int total=0,tw = 0;
		for (j=0;j<n;j++)
		{
			if (ffind(group[j]) == i)
			{
				used[i] = 1;
				total += beauty[j];
				tw += weight[j];
				if (ig[i][weight[j]] == 0)
				{
					igpoint[i][igpointcount[i]] = weight[j];
					igpointcount[i] ++;
				//	printf("%d in %d\n",j,i);
				}
				if (ig[i][weight[j]] < beauty[j])
				{
					ig[i][weight[j]] = beauty[j];
				}
			}
		}
		if (tw > w) continue;
		if (ig[i][tw] == 0)
		{
			igpoint[i][igpointcount[i]] = tw;
			igpointcount[i] ++;
		//	printf("-%d in %d\n",i,i);
		}
		ig[i][tw] = total;
	}
	for (i=0;i<n;i++)
	{
		if (!used[i]) continue;
	//	printf("%d %d\n",i,igpointcount[i]);
		for (j=1;j<=w;j++)
		{
			for (k=0;k<igpointcount[i];k++)
			{
				if (j-igpoint[i][k] < 0) continue;
	//			printf("%d %d\n",igpoint[i][k],ig[i][igpoint[i][k]]);
				int cur = g[j-igpoint[i][k]] + ig[i][igpoint[i][k]];
				if (cur>f[j]) f[j] = cur;
	//			printf("%d\n",cur);
			}
		}
		memcpy(g,f,sizeof(f));
	}
	int ans = 0;
	for (i=0;i<=w;i++)
	{
		if (f[i]>ans) ans = f[i];
	}
	cout<<ans<<endl;
	return 0;
}
