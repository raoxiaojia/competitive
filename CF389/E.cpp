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

int orange[2000000];

int n,m;

int ok(int x)
{
	int i,j;
	long long total = 0;
	for (i=0;i<n;i++)
	{
		if (orange[i]<x) continue;
		if ((orange[i])/2<x)
		{
			total ++;
			if (total >= m) return 1;
			continue;
		}
		int high,low,hc,lc;
		high = (orange[i]+1)/2;
		low = orange[i]/2;
		hc = 1;
		lc = 1;
		while (low/2>=x)
		{
			if (high == low)
			{
				if (high%2 == 0)
				{
					high /= 2;
					low /= 2;
					hc *= 2;
					lc *= 2;
					continue;
				}
				else
				{
					high = (high+1)/2;
					low = low/2;
					hc *= 2;
					lc *= 2;
				}
			}
			else
			{
				if (high%2 == 0)
				{
					high = high/2;
					low = low/2;
					hc = hc*2+lc;
				}
				else
				{
					high = (high+1)/2;
					low = low/2;
					lc = lc*2+hc;
				}
			}
		}
		total += lc;
		if (high/2>=x) total += hc*2;
		else total += hc;
		if (total >= m) return 1;
	}
	return 0;
}

int main()
{
	int i,j,k;
	cin>>n>>m;
	int max=0;
	for (i=0;i<n;i++)
	{
		cin>>orange[i];
		if (orange[i]>max) max = orange[i];
	}
	int s,t,mid;
	s = 1;
	t = max;
	while (t-s>1)
	{
		mid = (s+t)/2;
		if (ok(mid)) s = mid;
		else t = mid;
	}
	if (ok(t)) printf("%d\n",t);
	else if (ok(s)) printf("%d\n",s);
	else printf("-1\n");
	return 0;
}
