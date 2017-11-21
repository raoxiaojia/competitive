#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int n,k;

typedef pair<int,int> ii;

auto cmp = [](ii x1,ii x2) {
	if (x1.first<x2.first) return true;
	return false;
};

priority_queue<ii,vector<ii>,decltype(cmp) > cost(cmp);

ii mp(int a,int b)
{
	ii res;
	res.first = a;
	res.second = b;
	return res;
}

long long ans;

int outtime[500000];

int main()
{
	int i,j;
	cin>>n>>k;
	long long cur = 0;
	for (i=0;i<n;i++)
	{
		cin>>j;
		cost.push(mp(j,i+1));
		cur += j;
		if (i>=k)
		{
			ii x = cost.top();
			cur -= x.first;
			outtime[x.second] = i+1;
			cost.pop();
		}
		ans += cur;
	}
	for (i=0;i<k;i++)
	{
		ii x = cost.top();
		cur -= x.first;
		outtime[x.second] = i+1+n;
		cost.pop();
		ans += cur;
	}
	cout<<ans<<endl;
	for (i=1;i<=n;i++)
	{
		printf("%d ",outtime[i]);
	}
	return 0;
}
