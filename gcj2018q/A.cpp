#include "bits/stdc++.h"

using namespace std;

int main()
{
	int n;
	int i,j,k;
	string str;
	cin>>n;
	int max = 0;
	for (j=0;j<n;j++)
	{
		cin>>max>>str;
		int total = 0;
		int cur = 1;
		for (i=0;i<str.length();i++)
		{
			if (str[i] == 'C') cur <<= 1;
			if (str[i] == 'S') total += cur;
		}
		int ans = 0;
		bool optimal = false;
		while (total > max)
		{
			optimal = true;
			ans ++;
			for (i=str.length()-1;i>0;i--)
			{
				if (str[i] == 'S' && str[i-1] == 'C')
				{
					str[i] = 'C';
					str[i-1] = 'S';
					optimal = false;
					break;
				}
			}
			if (optimal) break;
			total = 0;
			cur = 1;
			for (i=0;i<str.length();i++)
			{
				if (str[i] == 'C') cur <<= 1;
				if (str[i] == 'S') total += cur;
			}
		}
		if (optimal)
		{
			printf("Case #%d: IMPOSSIBLE\n",j+1);
		}
		else
		{
			printf("Case #%d: %d\n",j+1,ans);
		}
	}
	return 0;
}
