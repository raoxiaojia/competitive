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
	int n,dst,max;
	cin>>n>>dst>>max;
	int i;
	int best = 1000000;
	int cp;
	for (i=1;i<=n;i++)
	{
		cin>>cp;
		if (cp > max) continue;
		if (cp == 0) continue;
		if (abs(i-dst) < best)
		{
			best = abs(i-dst);
		}
	}	
	cout<<best*10<<endl;
	return 0;
}
