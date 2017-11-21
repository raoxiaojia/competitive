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

int num[2000];

int main()
{
	int n;
	cin>>n;
	int i,j,k;
	int sum = 0;
	int notzero = -1;
	for (i=0;i<n;i++)
	{
		cin>>num[i];
		sum+=num[i];
		if (notzero == -1)
		{
			if (num[i] != 0) notzero = i;
		}
	}
	if (sum != 0) printf("YES\n1\n1 %d\n",n);
	else if (notzero == -1) printf("NO\n");
	else printf("YES\n2\n1 %d\n%d %d\n",notzero+1,notzero+2,n);
	return 0;
}
