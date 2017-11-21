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
	int i,j,k;
	int ans = 0;
	cin>>n>>m;
	for (i=0;i<n;i++)
	{
		cin>>j;
		if (j+m<=5) ans++;
	}
	cout<<ans/3<<endl;
	return 0;
}
