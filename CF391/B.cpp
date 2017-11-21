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

int total[500000];

int main()
{
	cin>>n;
	int i,j,k;
	for (i=0;i<n;i++) 
	{
		cin>>j;
		total[j] ++;
	}
	int ans = 1;
	for (i=2;i<=100000;i++)
	{
		int cur = 0;
		for (j=1;i*j<=100000;j++)
		{
			cur += total[i*j];
		}
		ans = cur>ans?cur:ans;
	}
	printf("%d\n",ans);
	return 0;
}
