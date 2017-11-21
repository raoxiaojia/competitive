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

int f[20000];

int used[20000];

int find(int x)
{
	if (f[x] == x) return x;
	int fx = find(f[x]);
	f[x] = fx;
	return fx;
}

void uni(int x,int y)
{
	if (x == y) return;
	if (x>y)
	{
		uni(y,x);
		return;
	}
	f[x] = find(x);
	f[y] = find(y);
	if (f[x]>f[y]) f[x] = f[y];
	else f[y] = f[x];
}

int main()
{
	int n;
	cin>>n;
	int i,j,k;
	for (i=1;i<=n;i++)
	{
		f[i] = i;
	}
	for (i=1;i<=n;i++)
	{
		cin>>k;
		uni(i,k);
	}
	for (i=1;i<=n;i++)
	{
		used[find(i)] = 1;
	}
	k = 0;
	for (i=1;i<=n;i++)
	{
		k += used[i];
	}
	cout<<k<<endl;
	return 0;
}
