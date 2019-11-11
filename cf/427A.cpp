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
	int cur = 0;
	cin>>n;
	while (n--)
	{
		int j;
		cin>>j;
		if (j == -1)
		{
			if (cur == 0) ans++;
			else cur--;
		}
		else
		{
			cur += j;
		}
	}
	cout<<ans<<endl;
	return 0;
}
