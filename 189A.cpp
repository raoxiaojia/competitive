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

int d[5000];

int main()
{
	int n,a[3];
	int i,j;
	cin>>n>>a[0]>>a[1]>>a[2];
	memset(d,-1,sizeof(d));
	d[0] = 0;
	for (i=1;i<=n;i++)
	{
		for (j=0;j<3;j++)
		{
			if (i<a[j]) continue;
			if (d[i-a[j]] == -1) continue;
			if (d[i-a[j]]+1>d[i])
			{
				d[i] = d[i-a[j]]+1;
			}
		}
	}
	cout<<d[n]<<endl;
}
