#include "bits/stdc++.h"

using namespace std;

vector<int> v;

int main()
{
	int n;
	int i,j,k;
	cin>>n;
	for (i=0;i<n;i++)
	{
		cin>>j;
		v.push_back(j);
	}
	int d = v[1]-v[0];
	k =1;
	for (i=2;i<n;i++)
	{
		if (v[i]-v[i-1] != d)
		{
			k = 0;
			break;
		}
	}
	if (k == 0) printf("%d\n",v[n-1]);
	else printf("%d\n",v[n-1]+d);
}
