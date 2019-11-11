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
	cin>>str1>>str2;
	int i;
	for (i=0;i<str1.length();i++)
	{
		printf("%d",(str1[i]-0x30)^(str2[i]-0x30));
	}
	printf("\n");
	return 0;
}
