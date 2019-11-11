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

int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	int ans = 0;
	ans = max(ans,a+b+c);
	ans = max(ans,a+b*c);
	ans = max(ans,a*b+c);
	ans = max(ans,a*b*c);
	ans = max(ans,(a+b)*c);
	ans = max(ans,a*(b+c));
	printf("%d\n",ans);
	return 0;
}
