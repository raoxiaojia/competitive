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
	int top,bottom,cur;
	cin>>n>>top;
	n--;
	bottom = top;
	while (n--)
	{
		cin>>cur;
		if (cur>top)
		{
			top = cur;
			ans ++;
		}
		if (cur<bottom)
		{
			bottom = cur;
			ans ++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
