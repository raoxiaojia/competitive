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
	int i=0;
	int n =str.length();
	while (i<n)
	{
		if (str[i] == 'h') break;
		i++; 
	}
	while (i<n)
	{
		if (str[i] == 'e') break;
		i++; 
	}
	while (i<n)
	{
		if (str[i] == 'l') break;
		i++; 
	}
	i++;
	while (i<n)
	{
		if (str[i] == 'l') break;
		i++; 
	}
	while (i<n)
	{
		if (str[i] == 'o') break;
		i++; 
	}
	if (i<n) printf("YES\n");
	else printf("NO\n");
	return 0;
}
