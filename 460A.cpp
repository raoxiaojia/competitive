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
	int n,m;
	int day = 1;
	cin>>n>>m;
	while (1)
	{
		n--;
		if (n < 0) break;
		if (day%m == 0) n++;
		day ++;
	}
	cout<<day-1<<endl;
	return 0;
}
