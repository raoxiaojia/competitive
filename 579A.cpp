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
	int n;
	cin>>n;
	int ans = 0;
	while (n)
	{
		ans += n%2;
		n/=2;
	}
	cout<<ans<<endl;
	return 0;
}
