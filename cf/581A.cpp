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
	int a,b,c;
	cin>>a>>b;
	if (a<b)
	{
		c=a;a=b;b=c;
	}
	cout<<b<<' '<<(a-b)/2<<endl;
	return 0;
}
