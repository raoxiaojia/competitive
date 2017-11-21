#include "bits/stdc++.h"
using namespace std;

int main()
{
	int n,x;
	vector<int> a;
	cin>>n;
	while (n--)
	{
		cin>>x;
		a.push_back(x);
	}
	sort(a.begin(),a.end());
	int ans = 0;
	for (auto it=a.begin();it != a.end();it++) ans += a.back()-*it;
	cout<<ans<<endl;
	return 0;
}
