#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>

using namespace std;

int x;

vector<string> str1,str2;

int survive[1005];

int main()
{
	int n,m;
	cin>>n>>m;
	if (n>m) printf("YES\n");
	else if (n<m) printf("NO\n");
	else
	{
		int i,j;
		str1.reserve(n);
		str2.reserve(m);
		string tmp;
		for (i=0;i<n;i++) {cin>>tmp; str1.push_back(tmp);}
		for (i=0;i<m;i++) {cin>>tmp; str2.push_back(tmp);}
		sort(str1.begin(),str1.end());
		sort(str2.begin(),str2.end());
		x = 0;
		i = 0;
		j = 0;
		while ((i<n) && (j<m))
		{
			if (str1[i] == str2[j])
			{
				x++;
				i++;
				j++;
				continue;
			}
			if (str1[i] < str2[j])
			{
				i++;
				continue;
			}
			j++;
		}
		if (x%2 == 0) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}
