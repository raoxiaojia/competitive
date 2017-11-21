#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int n,m;

#define TRIAL 10

long long total[1300000][TRIAL];

long long mult[120000][TRIAL];

long long modp = 1297273;

long long res[1300000];

long long realres[1300000][TRIAL];

long long realmodp = 1000000007;

long long ans;

void update(int x)
{
	int i;
	for (i=2;i<=x;i++)
	{
		ans *= i;
		ans %= realmodp;
	}
}

int ok(int i,int j)
{
	int k;
	for (k=0;k<TRIAL;k++)
	{
		if (total[i][k] != realres[j][k]) return 0;
	}
	return 1;
}

int main()
{
	int i,j,k;
	cin>>n>>m;
	for (i=0;i<TRIAL;i++)
	{
		for (j=0;j<110000;j++)
		{
			mult[j][i] = rand() * 71;
			mult[j][i] += rand() * 13;
			mult[j][i] %= modp;
		}
	}
	for (i=0;i<n;i++)
	{
		int g;
		cin>>g;
		for (j=0;j<g;j++)
		{
			int l;
			cin>>l;
			for (k=0;k<TRIAL;k++)
			{
				total[l][k] += mult[i][k];
				total[l][k] %= modp;
			}
		}
	}
	for (i=1;i<=m;i++)
	{
		if (res[total[i][0]] == 0)
		{
			res[total[i][0]] = 1;
			memcpy(realres[total[i][0]],total[i],sizeof(total[i]));
			continue;
		}
		j = total[i][0];
		while (ok(i,j) == 0)
		{
			j++;
			if (res[j] == 0) break;
		}
		if (res[j] == 0)
		{
			res[j] = 1;
			memcpy(realres[j],total[i],sizeof(realres[j]));
		}
		else res[j] ++;
	}
	ans = 1;
	for (i=0;i<modp;i++)
	{
		if (res[i] >= 2)
		{
			update(res[i]);
		}
	}
	cout<<ans<<endl;
	return 0;
}
