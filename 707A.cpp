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

vector<int> stack;

int main()
{
	int n,m;
	cin>>n>>m;
	string str;
	int i,j;
	getline(cin,str);
	for (i=0;i<n;i++)
	{
		getline(cin,str);
		for (j=0;j<str.length();j++)
		{
			switch (str[j])
			{
				case 'C':
				case 'M':
				case 'Y':
					{
						printf("#Color\n");
						return 0;
					}
			}
		}
	}
	printf("#Black&White\n");
	return 0;
}
