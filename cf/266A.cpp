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
	scanf("%d",&n);
	int i,j;
	int ans = 0;
	char ch1,ch2;
	scanf("%c",&ch1);
	while (ch1 < 'A') scanf("%c",&ch1);
	for (i=1;i<n;i++)
	{
		scanf("%c",&ch2);
		if (ch1 == ch2) ans ++;
		ch1 = ch2;
	}
	printf("%d\n",ans);
	return 0;
}
