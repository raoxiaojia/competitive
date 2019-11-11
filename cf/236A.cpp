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
	bool sign[500];
	memset(sign,false,sizeof(sign));
	int i;
	for (i=0;i<str.length();i++)
	{
		sign[str[i]] = true;
	}
	for (i=0;i<256;i++)
	{
		sign[i+1] ^= sign[i];
	}
	if (sign[256]) printf("IGNORE HIM!\n");
	else printf("CHAT WITH HER!\n");
	return 0;
}
