#include "bits/stdc++.h"
using namespace std;

int main()
{
	int m,s,i,j,k;
	cin>>m>>s;
	if ((s == 0) && (m == 1))
	{
		printf("0 0\n");
		return 0;
	}
	if ((s == 0) || (s > m*9)) 
	{
		printf("-1 -1\n");
		return 0;
	}
	vector<int> minans,maxans;
	minans.clear();
	maxans.clear();
	i=m;j=s;
	while (j>=10)
	{
		minans.push_back(9);
		maxans.push_back(9);
		j -= 9;
		i--;
	}
	k = j;

	while (i>1)
	{
		minans.push_back(j-1);
		j -= (j-1);
		maxans.push_back(k>9?9:k);
		k -= maxans.back();
		i--;
	}
	if (i==1)
	{
		minans.push_back(j);
		maxans.push_back(k);
	}
	for (i=m-1;i>=0;i--) printf("%d",minans[i]);
	printf(" ");
	for (i=0;i<m;i++) printf("%d",maxans[i]);
	printf("\n");
	return 0;
}
