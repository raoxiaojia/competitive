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

const string key="qwertyuiopasdfghjkl;zxcvbnm,./";

int tr(char ch)
{
	return ch=='R'?-1:1;
}

int main()
{
	char ch;
	string str;
	cin>>ch;
	cin>>str;
	int i,j;
	j = tr(ch);
	for (i=0;i<str.length();i++)
	{
		cout<<key[key.find(str[i])+j];
	}
	cout<<endl;
	return 0;
}
