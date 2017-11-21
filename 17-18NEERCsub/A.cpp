#include "bits/stdc++.h"

using namespace std;

int main()
{
	int a;
	int cur;
	cin>>a;
	vector<int> v;
	v.clear();
	int max = 0;
	int sum = 0;
	for (int i=0;i<6;i++)
	{
		int j;
		cin>>j;
		if (j)
		{
			v.push_back(2+i);
			max = 2+i;
			sum += 2+i;
		}
	}
	string str;
	cin>>str;
	if (str == "RED") cur = 1; else cur = 0;
	if (a)
	{
		printf("%d\n",27+a*8+cur*7);
	}
	else printf("%d\n",sum+cur*7);
	return 0;
}
