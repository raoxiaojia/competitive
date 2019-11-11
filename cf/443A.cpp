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
	getline(cin,str);
	int i;
	int count[50];
	memset(count,0,sizeof(count));
	for (i=0;i<str.length();i++)
	{
		if ((str[i]>='a') && (str[i]<='z')) count[str[i]-'a'] ++;
	}
	int ans = 0;
	for (i=0;i<=25;i++) ans += count[i]>0?1:0;
	cout<<ans<<endl;
	return 0;
}
