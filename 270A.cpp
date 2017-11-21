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

int ok[200];

int main()
{
	int i,n;
	for (i=3;i<30000;i++)
	{
		if ((i-2)*180%i == 0)
		{
			ok[(i-2)*180/i] = 1;
		}
	}
	cin>>n;
	while (n--)
	{
		cin>>i;
		if (ok[i]) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
