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
	string str1,str2;
	int n;
	cin>>str1>>str2;
	if (str1.length() != str2.length())
	{
		printf("NO\n");
		return 0;
	}
	n = str1.length();
	for (int i=0;i<n;i++)
	{
		if (str1[i] != str2[n-1-i])
		{
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}
