#include "bits/stdc++.h"

using namespace std;


int res;

int fixed2;

int changed;

int main()
{
	int n;
	int i,j,k;
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{
		char ch;
		scanf("%c",&ch);
start:;
		switch (ch)
		{
			case '|': scanf("%d",&k); fixed2 |= k; res &= (1023^k); changed |= k; break;
			case '&': scanf("%d",&k); fixed2 &= k; res &= k; changed |= (1023^k); break;
			case '^': scanf("%d",&k); fixed2 ^= k; res ^= k; break;
			default: scanf("%c",&ch); goto start; break;
		}
	}
	printf("3\n");
	printf("^ %d\n", (1023^changed) & res);
	printf("& %d\n", fixed2 | (1023^changed));
	printf("| %d\n", changed & fixed2);
	return 0;
}
