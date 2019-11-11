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

int main()
{
	int n;
	vector<int> height;
	height.clear();
	height.reserve(100);
	cin>>n;
	int i,j,k;
	int min,minpos,max,maxpos;
	min = 1000000;
	max = -1;
	for (i=0;i<n;i++) 
	{
		cin>>height[i];
		if (height[i] > max)
		{
			max = height[i];
			maxpos = i;
		}
		if (height[i] <= min)
		{
			min = height[i];
			minpos = i;
		}
	}
	if (minpos > maxpos) printf("%d\n",n-1-minpos+maxpos);
	else printf("%d\n",n-2-minpos+maxpos);
	return 0;
}
