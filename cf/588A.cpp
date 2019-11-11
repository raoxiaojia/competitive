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
	int ans = 0;
	int a,b;
	int min = 10000;
	cin>>n;
	while (n--)
	{
		cin>>a>>b;
		if (b<min) min = b;
		ans += a*min;
	}
	cout<<ans<<endl;
	return 0;
}
