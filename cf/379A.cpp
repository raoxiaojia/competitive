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
	int a,b;
	cin>>a>>b;
	int ans = a;
	while (a>=b)
	{
		ans += a/b;
		a = a/b+a%b;
	}
	cout<<ans<<endl;
	return 0;
}
