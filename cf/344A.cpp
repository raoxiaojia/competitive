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
	int x,y,ans = 0;
	cin>>n;
	cin>>x;
	n--;
	while (n--)
	{
		cin>>y;
		if (x!=y) ans++;
		x = y;
	}
	printf("%d\n",ans+1);
	return 0;
}
