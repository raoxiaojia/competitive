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
	int m,n;
	int i,j;
	int ans = 1000000;
	cin>>m>>n;
	m --;
	vector<int> num;
	num.clear();
	for (i=0;i<n;i++)
	{
		cin>>j;
		num.push_back(j);
	}
	sort(num.begin(),num.end());
	for (i=0;i+m<n;i++)
	{
		if (num[i+m]-num[i] < ans) ans = num[i+m]-num[i];
	}
	printf("%d\n",ans);
	return 0;
}
