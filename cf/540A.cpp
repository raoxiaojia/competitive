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

int diff(int x,int y)
{
	int t = abs(y-x);
	if (t<=5) return t;
	return 10-t;
}

int main()
{
	int n;
	string str1,str2;
	cin>>n>>str1>>str2;
	int i;
	int ans = 0;
	for (i=0;i<n;i++) ans += diff(str1[i]-0x30,str2[i]-0x30);
	cout<<ans<<endl;
	return 0;
}
