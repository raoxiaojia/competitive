#include "bits/stdc++.h"

using namespace std;

int n;

int beanr[100005],beanl[100005]; //excl

vi dp,lastdp;

string str;

int main()
{
	cin>>n;
	cin>>str;
	int i,j,k;
	int last = -1;
	for (i=0;i<n;i++)
	{
		beanl[i] = last;
		if (str[i] == '*') last = i;
	}
	last = -1;
	for (i=n-1;i>=0;i--)
	{
		beanr[i] = last;
		if (str[i] == '*') last = i;
	}
	dp.reserve(n);
	int lastmanpos = -1;
	for (i=0;i<n;i++)
	{
		if (str[i] != 'P') continue;
		lastdp = dp;
		dp.clear();
		j = i;//left
		k = i;//right
		while (1)//k
		{
			while (1)//j
			{
				dp[]
			}
		}
	}
	return 0;
}

