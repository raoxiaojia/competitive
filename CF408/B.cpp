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

int hole[2000000];

int main()
{
	int n,m,s;
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>s;
	int i,j,k;
	for (i=0;i<m;i++)
	{
		cin>>j;
		hole[j] = 1;
	}
	int curpos = 1;
	for (i=0;i<s;i++)
	{
		int a,b;
		if (hole[curpos])
		{
			cout<<curpos<<endl;
			return 0;
		}
		cin>>a>>b;
		if (a == curpos)
		{
			curpos = b;
		}
		else
		if (b == curpos)
		{
			curpos = a;
		}
	}
	cout<<curpos<<endl;
	return 0;
}
