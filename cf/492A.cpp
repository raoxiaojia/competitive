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
	int i;
	int cur;
	i = 0;
	cur = 0;
	cin>>n;
	while (1)
	{
		i++;
		cur+=i;
		n-=cur;
		if (n<0)
		{
			cout<<i-1<<endl;
			return 0;
		}
	}
	return 0;
}
