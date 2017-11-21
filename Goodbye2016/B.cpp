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
	int y;
	y = 0;
	while (n)
	{
		n--;
		int dist;
		string str;
		cin>>dist>>str;
		if (str == "South")
		{
			y += dist;
			if (y>20000)
			{
				printf("NO\n");
				return 0;
			}
		}
		else
		if (str == "North")
		{
			y -= dist;
			if (y<0)
			{
				printf("NO\n");
				return 0;
			}
		}
		else
		{
			if ((y == 0) || (y == 20000))
			{
				printf("NO\n");
				return 0;
			}
		}	
	}
	if (y == 0) printf("YES\n");
	else printf("NO\n");
	return 0;
}
