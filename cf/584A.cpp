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
	int n,t;
	cin>>n>>t;
	if (t!=10)
	{
		while (n--) cout<<t;
		cout<<endl;
	}
	else
	if (n==1)
	{
		cout<<-1<<endl;
	}
	else
	{
		cout<<1;
		n--;
		while (n--) cout<<0;
		cout<<endl;
	}
	return 0;
}
