#include "bits/stdc++.h"

using namespace std;

typedef vector<int> vi;

vi rem[100005];

int main()
{
	int n,m,k,i,j;
	cin>>n>>k>>m;
	for (i=0;i<n;i++)
	{
		cin>>j;
		rem[j%m].push_back(j);
		if (rem[j%m].size()>=k)
		{
			printf("Yes\n");
			for (auto it=rem[j%m].begin();it!=rem[j%m].end();it++)
			{
				printf("%d ",*it);
			}
			return 0;
		}
	}
	printf("No\n");
	return 0;
}
