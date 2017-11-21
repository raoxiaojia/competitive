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
	int n,t;
	string str;
	cin>>n>>t;
	cin>>str;
	while (t--)
	{
		for (int i=0;i<n;i++)
		{
			if ((str[i] == 'B') && (str[i+1] == 'G'))
			{
				str[i] = 'G';
				str[i+1] = 'B';
				i++;
			}
		}
	}
	cout<<str<<endl;
	return 0;
}
