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

int n;

int a[200000],b[200000];

long long aavg,bavg,asum,bsum;

int picked[200000];

int ma[200000],mb[200000];

int main()
{
	scanf("%d",&n);
	int i,j,k;
	for (i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
		asum += a[i];
	}
	aavg = (long long)(asum/2+1)/(n/2+1);
	for (i=0;i<n;i++)
	{
		scanf("%lld",&b[i]);
		bsum += b[i];
	}
	bavg = (long long)(bsum/2+1)/(n/2+1);
	return 0;
}
