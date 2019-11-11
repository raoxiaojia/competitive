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

bool cmp(int x,int y)
{
	if (x>y) return true;
	return false;
}

int main()
{
	int n;
	int i,j;
	vector<int>coin;
	coin.clear();
	scanf("%d",&n);
	int sum = 0;
	for (i=0;i<n;i++)
	{
		scanf("%d",&j);
		coin.push_back(j);
		sum += j;
	}
	sort(coin.begin(),coin.end(),cmp);
	int cur = 0;
	for (i=0;i<n;i++)
	{
		cur += coin[i];
		sum -= coin[i];
		if (cur>sum) break;
	}
	printf("%d\n",i+1);
	return 0;
}
