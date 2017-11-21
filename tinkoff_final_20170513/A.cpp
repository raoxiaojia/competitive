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

vector<int> x;

int main()
{
	int n,a,b,c;
	cin>>a>>b>>c;
	cin>>n;
	int i,j,k;
	for (i=0;i<n;i++)
	{
		scanf("%d",&j);
		x.push_back(j);
	}
	x.push_back(a);
	x.push_back(b);
	x.push_back(c);
	sort(x.begin(),x.end());
	i=0;
	int sb,sc;
	sb = -1;
	sc = -1;
	while (i<x.size())
	{
		if (x[i]>b)
		{
			sb = i;
			break;
		}
		i++;
	}
	while (i<x.size())
	{
		if (x[i]>=c)
		{
			sc = i;
			break;
		}
		i++;
	}
	if (sc != -1)
	cout<<sc-sb-1<<endl;
	else cout<<0<<endl;
	return 0;
}
