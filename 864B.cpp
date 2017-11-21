#include "bits/stdc++.h"

using namespace std;

string str;

int type[30];

int main()
{
	int i,j,k;
	int n;
	cin>>n;
	cin>>str;
	int ans = 0;
	for (i=0;i<n;i++)
	{
		if (str[i]<'a')
		{
			k=0;
			for (j=0;j<26;j++)
			{
				k += type[j];
			}
			ans = k>ans?k:ans;
			memset(type,0,sizeof(type));
		}
		else
		{
			type[str[i]-'a'] = 1;
		}
	}
	k=0;
			for (j=0;j<26;j++)
			{
				k += type[j];
			}
			ans = k>ans?k:ans;
			memset(type,0,sizeof(type));
	cout<<ans<<endl;
	return 0;
}
