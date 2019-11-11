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
	int i,j,k;
	k = 0;
	scanf("%d",&n);
	while (n--)
	{
		scanf("%d %d",&i,&j);
		k += j-i>=2?1:0;
	}
	printf("%d\n",k);
	return 0;
}
