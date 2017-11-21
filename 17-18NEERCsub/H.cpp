#include "bits/stdc++.h"

using namespace std;

int n;

long long key[200000];

long long best = 1e17;

long long curleft = 0, curright = 0;

long long modright[200000],modleft[200000];

int main()
{
	cin>>n;
	int i,j,k;
	for (i=0;i<n;i++)
	{
		scanf("%lld",&key[i]);
	}
	long long last = 0;
	for (i=n-1;i>=0;i--)
	{
		if (key[i]>last) 
		{
			modright[i] = key[i];
			last = key[i];
			continue;
		}
		curright += last+1-key[i];
		last++;
		modright[i] = last;
	}
	best = curleft + curright;
	long long curans = curleft + curright;
	modleft[0] = modright[0];
	for (i=1;i<n;i++)
	{
		if (i > 1)
		{
			long long req = max(key[i-1],modleft[i-2]+1);
			if (modleft[i-1] > req)
			{
				curans -= modleft[i-1]-req;
				modleft[i-1] = req;
			}
		}
		long long req = max(key[i],max(modleft[i-1]+1,modright[i+1]+1));
		curans -= modright[i]-req;
		modright[i] = req;
		if (curans < best) best = curans;
	}
	cout<<best<<endl;
	return 0;
}
