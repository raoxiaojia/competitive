#include "bits/stdc++.h"
using namespace std;

int n;

vector<int> a,b;

int c[2000];

int main()
{
	cin>>n;
	int i,j,k;
	for (i=0;i<n;i++)
	{
		cin>>j;
		a.push_back(j);
		b.push_back(j);
	}
	sort(a.begin(),a.end());
	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
		{
			if (b[j] == a[i])
			{
				c[j] = a[(i+1)%n];
			}
		}
	}
	for (i=0;i<n-1;i++)
	{
		printf("%d ",c[i]);
	}
	printf("%d\n",c[n-1]);
	return 0;
}
