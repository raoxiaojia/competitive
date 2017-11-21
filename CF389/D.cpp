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

int n,m;

const int pmod = 1999993;

vector<int> hashlist[2000000];

string hashstr[2000000];

int hash(string str)
{
	int res = 0;
	int i;
	for (i=0;i<m;i++)
	{
		res += (str[i]-'a'+1) * (3*i+1);
		res %= pmod;
	}
	return res;
}

int revhash(string str)
{
	int res = 0;
	int i,j;
	j = 0;
	for (i=m-1;i>=0;i--)
	{
		res += (str[i]-'a'+1) * (3*j+1);
		j++;
		res %= pmod;
	}
}

int main()
{
	cin>>n>>m;
	string str;
	int i,j,k;
	printf("%d %d\n",hash("aab"),revhash("baa"));
	for (i=0;i<n;i++)
	{
		cin>>str>>k;
	}
	return 0;
}
