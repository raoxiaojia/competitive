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

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	cin>>t;
	int i,j,k;
	double dist;
	for (i=0;i<t;i++)
	{
		cin>>dist>>n;
		double time = 0;
		for (j=0;j<n;j++)
		{
			double a,b,c;
			cin>>a>>b;
			c = (dist-a)/b;
			if (c>time) time = c;
		}
		printf("Case #%d: %.8lf\n",i+1,(double)dist/time);
	}
	return 0;
}
