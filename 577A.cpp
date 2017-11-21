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
	int n,x;
	cin>>n>>x;
	int i,j;
	long long ans = 0;
	for (i=1;i<=sqrt(x);i++)
	{
		if ((long long)i*n<x) continue;
		if (x%i == 0) ans += 2;
		if (i*i == x) ans --;
	}
	cout<<ans<<endl;
	return 0;
}
