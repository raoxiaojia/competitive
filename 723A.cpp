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

inline max(int a,int b)
{
	return a>b?a:b;
}

inline min(int a,int b)
{
	return a<b?a:b;
}

int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	cout<<max(a,max(b,c))-min(a,min(b,c))<<endl;
	return 0;
}
