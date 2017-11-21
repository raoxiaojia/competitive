#include "bits/stdc++.h"
using namespace std;

multiset<long long> x;

long long ans = 0;

int main()
{
	int n;
	int i,j;
	long long k = 0;
	cin>>n;
	for (i=0;i<n;i++)
	{
		cin>>j;
		x.insert(j);
	}
	if (n%2 == 0) x.insert(0);
	while (x.size() >= 3)
	{
		k = *x.begin();
		x.erase(x.begin());
		k += *x.begin();
		x.erase(x.begin());
		k += *x.begin();
		x.erase(x.begin());
		x.insert(k);
		ans += k;
	}
	cout<<ans<<endl;
	return 0;
}
