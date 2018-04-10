#include "bits/stdc++.h"

using namespace std;

int main()
{
	int t;
	int n;
	scanf("%d",&t);
	int i,j,k;
	for (i=0;i<t;i++)
	{
		scanf("%d",&n);
		vector<int> v1;
		vector<int> v2;
		vector<int> v3;
		v1.clear();
		v2.clear();
		v3.clear();
		for (j=0;j<n;j++)
		{
			scanf("%d",&k);
			v3.push_back(k);
			if (j&1) v2.push_back(k);
			else v1.push_back(k);
		}
		sort(v1.begin(),v1.end());
		sort(v2.begin(),v2.end());
		sort(v3.begin(),v3.end());
		vector<int> v4;
		v4.clear();
		for (j=0;j<v2.size();j++)
		{
			v4.push_back(v1[j]);
			v4.push_back(v2[j]);
		}
		if (n&1) v4.push_back(v1[v1.size()-1]);
		int error = -1;
		for (j=0;j<n;j++)
		{
			if (v3[j] != v4[j])
			{
				error = j;
				break;
			}
		}
		if (error >= 0)
		{
			printf("Case #%d: %d\n",i+1,error);
		}
		else
		{
			printf("Case #%d: OK\n",i+1);
		}
	}
	return 0;
}
