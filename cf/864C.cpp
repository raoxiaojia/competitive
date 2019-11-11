#include "bits/stdc++.h"

using namespace std;

int main()
{
	int a,b,f,k;
	int i,j;
	cin>>a>>b>>f>>k;
	int dist = 2*(a-f);
	int cur = b;
	if (((b<dist) || (b<2*a-dist)) && (k>=3))
	{
		printf("-1\n");
		return 0;
	}
	if (k == 1)
	{
		if ((b<f) || (b<a-f))
		{
			printf("-1\n");
			return 0;
		}
		if (b>=a)
		{
			printf("0\n");
			return 0;
		}
		printf("1\n");
		return 0;
	}
	cur -= f;
	int ans = 0;
	for (i=0;i<k-1;i++)
	{
		if (cur<dist)
		{
			ans ++;
			cur = b;
		}
		cur -= dist;
		dist = 2*a-dist;
		if(cur<0)
		{
			printf("-1\n");
			return 0;
		}
	}
	if (cur<dist/2)
	{
		ans ++;
	}
	cout<<ans<<endl;
	return 0;
}
