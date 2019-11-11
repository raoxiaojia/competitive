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
	int n,m;
	cin>>n>>m;
	int i,j;
	for (i=0;i<n/2;i++)
	{
		for (j=0;j<m;j++) cout<<'#';
		cout<<endl;
		if (i%2 == 0)
		{
			for (j=0;j<m-1;j++) cout<<'.';
			cout<<'#'<<endl;
		}
		else
		{
			cout<<'#';
			for (j=0;j<m-1;j++) cout<<'.';
			cout<<endl;
		}
	}
	for (j=0;j<m;j++) cout<<'#';
	cout<<endl;
	return 0;
}
