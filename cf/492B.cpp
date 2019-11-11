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

vector<int> pos;

bool cmp(int x,int y)
{
	return x<y?true:false;
}

int main()
{
	int n,l;
	int i,j,k;
	pos.reserve(1000);
	cin>>n>>l;
	for (i=0;i<n;i++)
	{
		cin>>j;
		pos.push_back(j);
	}
	sort(pos.begin(),pos.end(),cmp);
	k = 0;
	for (i=1;i<n;i++)
	{
		if (pos[i]-pos[i-1] > k)
		{
			k = pos[i]-pos[i-1];
		}
	}
	if (pos[0]*2>k) k = pos[0]*2;
	if ((l-pos[n-1])*2>k) k = (l-pos[n-1])*2;
	printf("%.8lf\n",(double)k/2);
	return 0;
}
