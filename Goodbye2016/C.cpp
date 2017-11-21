#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>

#define INF 200000000

using namespace std;

int main()
{
	int n;
	cin>>n;
	int min = -INF;
	int max = INF*10;
	while (n)
	{
		n--;
		int c,d;
		cin>>c>>d;
		if (d == 1)
		{
			min = min>1900?min:1900;
		}
		else
		{
			max = max<1899?max:1899;
		}
		if (min>max)
		{
			printf("Impossible\n");
			return 0;
		}
		min += c;
		max += c;
		if (max > INF)
		{
			max == INF*10;
		}
	}
	if (max > INF)
	{
		printf("Infinity\n");
	}
	else printf("%d\n",max);
	return 0;
}
