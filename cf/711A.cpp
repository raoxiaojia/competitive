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
	cin>>n;
	string str[2000];
	int i,j;
	for (i=0;i<n;i++) cin>>str[i];
	j = 0;
	for (i=0;i<n;i++)
	{
		if (str[i].substr(0,2) == "OO")
		{
			j = 1;
			str[i][0] = '+';
			str[i][1] = '+';
			break;
		}
		if (str[i].substr(3,2) == "OO")
		{
			j = 1;
			str[i][3] = '+';
			str[i][4] = '+';
			break;
		}
	}
	if (!j) cout<<"NO"<<endl;
	else
	{
		cout<<"YES"<<endl;
		for (i=0;i<n;i++) cout<<str[i]<<endl;
	}
	return 0;
}
