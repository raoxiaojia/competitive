#include "bits/stdc++.h"

using namespace std;

int acount[105];

int n;

int ans1,ans2;

int main()
{
	int i,j;
	cin>>n;
	for (i=0;i<n;i++)
	{
		cin>>j;
		acount[j] ++;
	}
	j = 0;
	for (i=1;i<=100;i++)
	{
		j += acount[i]>0?1:0;
		if (j>=3)
		{
			printf("NO\n");
			return 0;
		}
		if (acount[i]>0)
		{
			if (acount[i] != n/2)
			{
				printf("NO\n");
				return 0;
			}
			ans2 = ans1;
			ans1 = i;
		}
	}
	printf("YES\n%d %d\n",ans1,ans2);
	return 0;
}
