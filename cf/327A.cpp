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
	int i,j;
	int cur,max,ans = 0;
	cur = 0;
	max = 0;
	while (n--)
	{
		cin>>i;
		if (i==1)
		{
			cur --;
			if (cur < 0) cur = 0;
			ans ++;
		}
		else
		{
			cur ++;
			if (cur>max) max = cur;
		}
	}
	if (max == 0) max = -1;
	cout<<ans+max<<endl;
	return 0;
}
