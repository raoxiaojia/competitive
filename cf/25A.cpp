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
	int a,b,c;
	cin>>n;
	cin>>a>>b;
	n-=2;
	int i=2;
	while (n--)
	{
		cin>>c;
		i++;
		if ((a^b)&1)
		{
			if ((a^c)&1)
			{
				cout<<1<<endl;
				return 0;
			}
			else
			{
				cout<<2<<endl;
				return 0;
			}
		}
		if ((a^c)&1)
		{
			cout<<i<<endl;
			return 0;
		}
	}
	return 0;
}
