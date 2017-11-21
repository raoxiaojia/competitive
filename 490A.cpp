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

deque<int> a[4];

inline min(int a,int b)
{
	return a<b?a:b;
}

int main()
{
	int n;
	int i,j,k;
	cin>>n;
	for (i=0;i<n;i++)
	{
		cin>>j;
		a[j].push_back(i+1);
	}
	k=min(a[1].size(),min(a[2].size(),a[3].size()));
	cout<<k<<endl;
	while (k--)
	{
		cout<<a[1].back()<<' '<<a[2].back()<<' '<<a[3].back()<<endl;
		for (i=1;i<=3;i++) a[i].pop_back();
	}
	return 0;
}
