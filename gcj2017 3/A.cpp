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

int t;

int n;

int ans[7][1000005];

int checked[7][1000005];

int p10[6] = {1,10,100,1000,10000,100000};

int ccount[10];

int ox,app[1000000];

void rec(int x,int len)
{
	app[x] = ox;
	ans[len][x] ++;
	memset(ccount,0,sizeof(ccount));
	int i,j,k;
	for (i=len;i>=1;i--)
	{
		ccount[x%10] ++;
		x /= 10;
	}
	for (i=len+1;i<=9;i++)
	{
		if (ccount[i] > 0) return;
	}
	k = 0;
	for (i=1;i<=len;i++)
	{
		k = k*10+ccount[i];
	}
	if (app[k] == ox) return;
	rec(k,len);
}

int convert(string str)
{
	int i,res;
	res = 0;
	for (i=0;i<str.length();i++)
	{
		res = res*10+str[i]-'0';
	}
	return res;
}

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	memset(checked,0,sizeof(checked));
	int i,j,k;
	for (i=1;i<=5;i++)
	{
		for (j=1;j<=p10[i]-1;j++)
		{
			ox = j;
			rec(j,i);
		//	if (j%1000 == 0) fprintf(stderr,"%d %d\n",i,j);
		}
		memset(app,0,sizeof(app));
	}
	cin>>t;
	for (i=0;i<t;i++)
	{
		string str;
		cin>>str;
		printf("Case #%d: %d\n",i+1,ans[str.length()][convert(str)]);
	}
	return 0;
}
