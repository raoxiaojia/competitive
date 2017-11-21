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

int n;

double dist[120],disttotal[120];

double f[120];

double endu[120];

double velo[120];

int main()
{
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	cin>>t;
	int q;
	int i,j,k;
	for (i=0;i<t;i++)
	{
		memset(f,0,sizeof(f));
		memset(dist,0,sizeof(dist));
		memset(disttotal,0,sizeof(disttotal));
		printf("Case #%d: ",i+1);
		cin>>n>>q;
		for (j=0;j<n;j++)
		{
			cin>>endu[j]>>velo[j];
		}
		int l;
		for (j=0;j<n;j++)
		{
			for (k=0;k<n;k++)
			{
				cin>>l;
				if (l != -1)
				{
					dist[j+1] = l;
					disttotal[j+1] = disttotal[j] + dist[j+1];
				}
			}
		}
		for (j=0;j<q;j++)
		{
			cin>>k>>k;
		}
		f[0] = 0;
		for (j=1;j<n;j++)
		{
			f[j] = 1e50;
			for (k=0;k<j;k++)
			{
				if (disttotal[j]-disttotal[k] <= endu[k])
				{
					double tmp = f[k] + (disttotal[j]-disttotal[k])/velo[k];
					if (tmp<f[j]) f[j] = tmp;
				}
			}
		}
		printf("%.8lf\n",f[n-1]);
	}
	return 0;
}
