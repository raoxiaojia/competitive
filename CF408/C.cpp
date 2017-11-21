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

int str[500000];

vector<int> con[500000];

vector<int> maxpos,maxm1pos;

int infl[500000];

int main()
{
	int n;
	int i,j,k;
	cin>>n;
	int max = -2147400000;
	int ans = 2147483647;
	for (i=0;i<n;i++)
	{
		cin>>str[i];
		if (max<str[i]) max = str[i];
	}
	for (i=0;i<n;i++)
	{
		if (str[i] == max) maxpos.push_back(i);
		if (str[i] == max-1) maxm1pos.push_back(i);
	}
	for (i=0;i<n-1;i++)
	{
		int a,b;
		cin>>a>>b;
		a--;
		b--;
		con[a].push_back(b);
		con[b].push_back(a);
	}
	if (maxpos.size() >= 2)
	{
		k = maxpos.size();
		for (i=0;i<k;i++)
		{
			for (j=0;j<con[maxpos[i]].size();j++)
			{
				infl[con[maxpos[i]][j]] ++;
			}
			infl[maxpos[i]] ++;
		}
		for (i=0;i<n;i++)
		{
			if (infl[i] == k)
			{
				cout<<max+1<<endl;
				return 0;
			}
		}
		cout<<max+2<<endl;
		return 0;
	}
	else
	{
		k = maxm1pos.size();
		for (i=0;i<k;i++)
		{
			int foundmp = 0;
			for (j=0;j<con[maxm1pos[i]].size();j++)
			{
				if (con[maxm1pos[i]][j] == maxpos[0])
				{
					foundmp = 1;
					break;
				}
			}
			if (foundmp == 0)
			{
				cout<<max+1<<endl;
				return 0;
			}
		}
		cout<<max<<endl;
		return 0;
	}
	return 0;
}
