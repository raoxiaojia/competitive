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
	long long  ans = 0;
	int pos[500000];
	memset(pos,0,sizeof(pos));
	cin>>n>>m;
	for (i=0;i<m;i++) cin>>pos[i];
	k = 1;
	for (i=0;i<m;i++)
	{
		ans += (pos[i]+n-k)%n;
		k = pos[i];
	}
	cout<<ans<<endl;
	return 0;
}
