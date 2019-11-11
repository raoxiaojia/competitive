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
	int i,j,k;
	for (i=0;i<5;i++)
	{
		for (j=0;j<5;j++)
		{
			scanf("%d",&k);
			if (k == 1)
			{
				printf("%d\n",abs(i-2)+abs(j-2));
				return 0;
			}
		}
	}
	return 0;
}
