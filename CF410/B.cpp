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

int pos[100];

int main()
{
	int n;
	string str[100];
	scanf("%d",&n);
	int i,j,k;
	int len = 0;
	for (i=0;i<n;i++)
	{
		cin>>str[i];
		len = str[0].length();
		if (str[i].length() != len)
		{
			printf("-1\n");
			return 0;
		}
	}
	int ans = 100000000;
	for (i=0;i<len;i++)
	{
		int cur = i;
		for (j=1;j<n;j++)
		{
			string tmpstr = str[j];
			int steps = 0;
			while (tmpstr != str[0])
			{
				char tmp = tmpstr[0];
				for (k=0;k<len-1;k++)
				{
					tmpstr[k] = tmpstr[k+1];
				}
				tmpstr[len-1] = tmp;
				steps ++;
				if (steps>len+2) break;
			}
			if (steps>len+2)
			{
				printf("-1\n");
				return 0;
			}
			cur += steps;
		}
		if (cur<ans) ans = cur;
		char tmp = str[0][0];
		for (k=0;k<len-1;k++)
		{
			str[0][k] = str[0][k+1];
		}
		str[0][len-1] = tmp;
	}
	printf("%d\n",ans);
	return 0;
}
