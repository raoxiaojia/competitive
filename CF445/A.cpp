#include "bits/stdc++.h"
using namespace std;

deque<int> x;

int main()
{
	int n;
	int i,j,k;
	cin>>n;
	for (i=0;i<n;i++)
	{
		scanf("%d",&j);
		x.push_back(j);
	}
	sort(x.begin(),x.end());
	int ans = 1;
	while ((x.size()>=2))
	{
		if (x[0] == x[1]) ans ++;
		x.pop_front();
	}
	cout<<ans<<endl;
	return 0;
}
