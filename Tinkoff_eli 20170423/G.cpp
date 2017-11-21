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

int n;

int q;

int row[20000],col[20000];

int main()
{
	cin>>n>>q;
	int i,j,k;
	for (i=0;i<q;i++)
	{
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		for (j=a;j<=c;j++)
		{
			row[j] -= (d-b+1);
		}
		for (j=b;j<=d;j++)
		{
			col[j] -= (c-a+1);
		}
	}
	int ansx = 0;
	int ansy = 0;
	for (i=1;i<=n;i++)
	{
		if (row[i] > -n) ansx ++;
		if (col[i] > -n) ansy ++;
	}
	printf("%d\n",ansx<ansy?ansx:ansy);
	return 0;
}
