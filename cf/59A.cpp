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
	int count = 0;
	for (int i=0;i<str.length();i++)
	{
		if (isupper(str[i])) count ++;
	}
	if (count*2>str.length())
	{
		for (int i=0;i<str.length();i++) printf("%c",toupper(str[i]));
		cout<<endl;
	}
	else
	{
		for (int i=0;i<str.length();i++) printf("%c",tolower(str[i]));
		cout<<endl;
	}
	return 0;
}
