#include "bits/stdc++.h"
using namespace std;

int main()
{
	string str;
	cin>>str;
	int ans = 0;
	int i,j,k;
	int tot = 0;
	int n = str.length();
	for (i=0;i<n;i++)
	{
		if (str[i] == 'Q') tot++;
	}
	j = 0;
	for (i=0;i<n;i++)
	{
		if (str[i] == 'Q') j ++;
		if (str[i] == 'A') ans += j*(tot-j);
	}
	cout<<ans<<endl;
	return 0;
}
