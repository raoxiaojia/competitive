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
	int n,h;
	cin>>n>>h;
	int i,j,k=0;
	for (i=0;i<n;i++)
	{
		cin>>j;
		if (j>h) k++;
		k++;
	}
	cout<<k<<endl;
	return 0;
}
