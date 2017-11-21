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

int total[500];

int isletter(char ch)
{
	if ((ch>='A') && (ch <= 'Z')) return 1;
	if ((ch >= 'a') && (ch <= 'z')) return 1;
	return 0;
}

int main()
{
	string str;
	cin>>str;
	int n=str.length();
	for (int i=0;i<n;i++)
	{
		total[str[i]] ++;
	}
	int min = 1000000;
	min = total['B']<min?total['B']:min;
	min = total['u']/2<min?total['u']/2:min;
	min = total['l']<min?total['l']:min;
	min = total['b']<min?total['b']:min;
	min = total['a']/2<min?total['a']/2:min;
	min = total['s']<min?total['s']:min;
	min = total['r']<min?total['r']:min;
	printf("%d\n",min);
	return 0;
}
