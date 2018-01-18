#include "bits/stdc++.h"

using namespace std;

int p[10000];

int son[10000];

int realson[10000];

int main()
{
	int n;
	int i,j,k;
	cin>>n;
	for (i=2;i<=n;i++)
	{
		cin>>p[i];
		son[p[i]]++;
	}
	for (i=2;i<=n;i++)
	{
		if (son[i] == 0) realson[p[i]] ++;
	}
	bool ok = true;
	for (i=1;i<=n;i++)
	{
		if (son[i] == 0) continue;
		if (realson[i] <= 2)
		{
			ok = false;
			break;
		}
	}
	if (ok) printf("YES\n");
	else printf("NO\n");
	return 0;
}
