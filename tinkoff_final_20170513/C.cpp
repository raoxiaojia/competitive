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

string s1,s2;

int c1[300],c2[300];

char ans[400000];

int main()
{
	cin>>s1;
	cin>>s2;
	int i,j,k;
	int n = s1.length();
	for (i=0;i<n;i++)
	{
		c1[s1[i]]++;
		c2[s2[i]]++;
	}
	j=0;
	int need1,need2;
	need2=n/2;
	need1=n-need2;
	int opos1,opos2;
	for (i=96;i<155;i++)
	{
		if (j+c1[i] >= need1)
		{
			c1[i] = need1-j+1;
			opos1 = i;
			for (k=i+1;k<155;k++)
			{
				c1[k] = 0;
			}
			break;
		}
		j += c1[i];
	}
	j=0;
	for (i=155;i>96;i--)
	{
		if (j+c2[i] >= need2)
		{
			c2[i] = need2-j+1;
			opos2 = i;
			for (k=i-1;k>96;k--)
			{
				c2[k] = 0;
			}
			break;
		}
		j += c2[i];
	}
	j = 96;
	k = 155;
	while (c1[j] == 0) j++;
	while (c2[k] == 0) k--;
	int changemode = 0;
	i=0;
	int pos1 = 0;
	while (n>0)
	{
		if (j<k)
		{
			ans[i*2]=j;
			c1[j]--;
			n--;
		}
		else
		{
			changemode = 1;
			pos1 = 2*i;
			break;
		}
		if (n == 0) break;
		while (c1[j] == 0) j++;
		if (j<k)
		{
			ans[i*2+1]=k;
			c2[k]--;
			n--;
		}
		else
		{
			changemode = 2;
			pos1 = 2*i+1;
			break;
		}
		while (c2[k] == 0) k--;
		i++;
	}
	if (changemode == 0)
	{
		for (i=0;i<s1.length();i++)
		{
			printf("%c",ans[i]);
		}
		printf("\n");
		return 0;
	}
	c1[opos1] --;
	c2[opos2] --;
	j=155;
	k=96;
	int pos2 = s1.length()-1;
	if (changemode == 2)
	{
		while (c2[k] == 0) k++;
		ans[pos2] = k;
		c2[k] --;
		pos2 --;
	}
	while (pos2>=pos1)
	{
		while (c1[j] == 0) j--;
		ans[pos2] = j;
		c1[j] --;
		pos2 --;
		if (pos2 < pos1) break;
		while (c2[k] == 0) k++;
		ans[pos2] = k;
		c2[k] --;
		pos2 --;
	}
	for (i=0;i<s1.length();i++)
	{
		printf("%c",ans[i]);
	}
	printf("\n");
	return 0;
}
