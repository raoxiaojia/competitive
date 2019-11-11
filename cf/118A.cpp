#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

bool notvowel(char ch)
{
	ch = tolower(ch);
	if (ch == 'a') return false;
	if (ch == 'e') return false;
	if (ch == 'i') return false;
	if (ch == 'o') return false;
	if (ch == 'u') return false;
	if (ch == 'y') return false;
	return true;
}

int main()
{
	string str;
	cin>>str;
	string str2;
	str2.clear();
	for (int i=0;i<str.length();i++)
	{
		if (notvowel(str[i]))
		{
			str2 = str2+"."+(char)tolower(str[i]);
		}
	}
	cout<<str2<<endl;
	return 0;
}
