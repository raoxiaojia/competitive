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
	int x = 1;
	string ans;
	ans.clear();
	while (str.length()>=3)
	{
		if (x)
		{
			x = 0;
		}
		else
		{
			ans += ' ';
		}
		while (str.substr(0,3) == "WUB")
		{
			str = str.substr(3,string::npos);
			if (str.length()<=2) break;
	//		cout<<str<<endl;
		}
		if (str.length()<=2) break;
		while (str.substr(0,3) != "WUB")
		{
			ans += str[0];
			str = str.substr(1,string::npos);
			if (str.length()<=2) break;
	//		cout<<str<<endl;
		}
	}
	ans += str;
	cout<<ans<<endl;
	return 0;
}
