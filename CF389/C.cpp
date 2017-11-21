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
	int n;
	string str;
	cin>>n>>str;
	int i,j,k;
	int ans = 0;
	int cur1=0,cur2=0;
	for (i=0;i<n;i++)
	{
		switch (str[i])
		{
			case 'U':
			case 'D':
				if (cur1 == 0)
				{
					cur1 = str[i];
					break;
				}
				if (cur1 != str[i])
				{
					ans ++;
					cur1 = str[i];
					cur2 = 0;
					break;
				}
				break;
			case 'L':
			case 'R':
				if (cur2 == 0)
				{
					cur2 = str[i];
					break;
				}
				if (cur2 != str[i])
				{
					ans ++;
					cur2 = str[i];
					cur1 = 0;
					break;
				}
				break;
		}
	}
	cout<<ans+1<<endl;
	return 0;
}
