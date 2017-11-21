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
	int i,j,k;
	int count[4];
	memset(count,0,sizeof(count));
	for (i=0;i<str.length();i++)
	{
		switch(str[i])
		{
			case '+': break;
			case '1':
			case '2':
			case '3': count[str[i]-0x30] ++; break;
		}
	}
	string strout;
	strout.clear();
	for (i=1;i<=3;i++)
	{
		for (j=0;j<count[i];j++)
		{
			strout += (char)(i+0x30);
			strout += '+';
		}
	}
	strout.pop_back();
	cout<<strout<<endl;
	return 0;
}
