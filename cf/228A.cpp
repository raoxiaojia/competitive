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
	int a,b,c,d;
	int ans = 1;
	cin>>a>>b>>c>>d;
	if (b!=a) ans++;
	if ((c!=a) && (c!=b)) ans++;
	if ((d!=a) && (d!=b) && (d!=c)) ans++;
	cout<<4-ans<<endl;
	return 0;
}
