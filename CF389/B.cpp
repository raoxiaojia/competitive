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

int realchar[300];

int main()
{
	string str1,str2;
	cin>>str1>>str2;
	int i,j,k;
	for (i=0;i<300;i++)
	{
		realchar[i] = -1;
	}
	k = 0;
	for (i=0;i<str1.length();i++)
	{
		if (realchar[str1[i]] > 0)
		{
			if (realchar[str1[i]] == str2[i]) continue;
			printf("-1\n");
			return 0;
		}
		if (str1[i] == str2[i])
		{
			realchar[str1[i]] = str1[i];
			continue;
		}
		if (realchar[str2[i]] > 0)
		{
			printf("-1\n");
			return 0;
		}
		realchar[str1[i]] = str2[i];
		realchar[str2[i]] = str1[i];
		k++;
	}
	printf("%d\n",k);
	for (i=0;i<300;i++)
	{
		if ((realchar[i]>0) && (realchar[i] != i))
		{
			printf("%c %c\n",i,realchar[i]);
			realchar[realchar[i]] = -1;
			realchar[i] = -1;
		}
	}
	return 0;
}
