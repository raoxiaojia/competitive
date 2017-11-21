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
	int n,m;
	cin>>n>>m;
	int i,j,k;
	j = 1;
	k = 1+m;
	long long inc = 0;
	long long ans = 1;
	for (i=0;i<n;i++)
	{
		if ((k<=m) && (k!=1)) inc++;
		if (j<=m) inc++;
		ans += inc;
		cout<<ans<<' ';
		j = (j+m-1)%n+1;
		k = (k+m-1)%n+1;
	}
	printf("\n");
	return 0;
}
