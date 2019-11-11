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
	cin>>n;
	cin>>str;
	int i;
	int count[50];
	memset(count,0,sizeof(count));
	for (i=0;i<n;i++)
	{
		count[tolower(str[i])-'a'] ++;
	}
	for (i=0;i<=25;i++)
	{
		if (count[i] == 0)
		{
			cout<<"NO"<<endl;
			return 0;
		}
	}
	cout<<"YES"<<endl;
	return 0;
}
