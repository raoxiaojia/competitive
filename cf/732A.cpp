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
	int ans = 1;
	while ((n*ans%10 != m) && (n*ans%10 != 0))
	{
		ans++;
	}
	cout<<ans<<endl;
	return 0;
}
