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
	int i;
	for (i=0;i<str.length();i++)
	{
		if ((str[i] == 'H') || (str[i] == 'Q') || (str[i] == '9'))
		{
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}
