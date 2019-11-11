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
	string str1,str2,str3;
	cin>>str1>>str2>>str3;
	int count[200];
	memset(count,0,sizeof(count));
	int i;
	for (i=0;i<str1.length();i++) count[str1[i]] ++;
	for (i=0;i<str2.length();i++) count[str2[i]] ++;
	for (i=0;i<str3.length();i++) count[str3[i]] --;
	for (i='A';i<='Z';i++)
	{
		if (count[i] != 0)
		{
			printf("NO\n");
			return 0;
		}
	}
	cout<<"YES"<<endl;
	return 0;
}
