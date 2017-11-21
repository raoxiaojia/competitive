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
	int diff = 0;
	int n = str.length();
	int i=0;
	int j=n-1;
	while (i<j)
	{
		if (str[i] != str[j])
		{
			diff ++;
		}
		i++;
		j--;
	}
	if (diff == 1) printf("YES\n");
	else if (diff >= 2) printf("NO\n");
	else if (i == j) printf("YES\n");
	else printf("NO\n");
	return 0;
}
