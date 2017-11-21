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

int n,m,p;

short f[52][1010][1010];

short max[52][1010][1010];

int g1[2000],g2[2000];

int main()
{
	cin>>n>>m>>p;
	int i,j,k;
	cin>>k;
	for (i=0;i<k;i++)
	{
		cin>>j;
		g1[j] = 1;
	}
	cin>>k;
	for (i=0;i<k;i++)
	{
		cin>>j;
		g2[j] = 1;
	}
	f[0][0][0] = 0;
	for (i=1;i<m;i++)
	{
		for ()
	}
	return 0;
}
