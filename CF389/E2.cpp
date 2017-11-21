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

long long orange[12000000];

long long n,m;

int main()
{
	int i,j,k;
	cin>>n>>m;
	int max=0;
	long long total = 0;
	for (i=0;i<n;i++)
	{
		scanf("%d",&j);
		orange[j] ++;
		if (j>max) max = j;
	}
	total = n;
	while (total<m)
	{
		while ((max >= 2) && (orange[max] == 0)) max--;
		if (max <= 1)
		{
			printf("-1\n");
			return 0;
		}
		total += orange[max];
		orange[max/2] += orange[max];
		orange[(max+1)/2] += orange[max];
		orange[max] = 0;
		max --;
	}
	int base = 1;
	while (total-orange[base] >= m)
	{
		total -= orange[base];
		base ++;
	}
	while (1)
	{
		while (orange[max] == 0) max--;
		if (max/2 < base)
		{
			printf("%d\n",base);
			return 0;
		}
		total += orange[max];
		orange[max/2] += orange[max];
		orange[(max+1)/2] += orange[max];
		orange[max] = 0;
		max --;
		while (total-orange[base] >= m)
		{
			total -= orange[base];
			base ++;
		}
	}
	return 0;
}
