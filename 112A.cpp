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
	cin>>str1;
	cin>>str2;
	int i;
	for (i=0;i<str1.length();i++)
	{
		str1[i] = tolower(str1[i]);
		str2[i] = tolower(str2[i]);
	}
	if (str1>str2) printf("1\n");
	else if (str1<str2) printf("-1\n");
	else printf("0\n");
	return 0;
}
