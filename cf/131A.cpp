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
	int init = 1;
	while (1)
	{
		if (init) init = 0;
		else printf(" ");
		cin>>str;
		if (cin.eof()) break;
		int ncaps = 0;
		int i,j;
		for (i=0;i<str.length();i++)
		{
			if (str[i] >= 'a') ncaps ++;
		}
		if ((ncaps == 0) || ((ncaps == 1) && (str[0] >= 'a')))
		{
			for (i=0;i<str.length();i++)
			{
				if (isupper(str[i])) str[i] = tolower(str[i]);
				else str[i] = toupper(str[i]);
			}
			cout<<str;
		}
		else
		{
			cout<<str;
		}
	}
	printf("\n");
	return 0;
}
