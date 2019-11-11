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

int main()
{
	string str;
	cin>>str;
	int i,j,k;
	j = 1;
	k = str[0];
	for (i=1;i<str.length();i++)
	{
		if (str[i] == k) j++;
		else
		{
			j = 1;
			k = str[i];
		}
		if (j >= 7) break;
	}
	if (j>=7) printf("YES\n");
	else printf("NO\n");
	return 0;
}
