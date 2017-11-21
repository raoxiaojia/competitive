#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	string str;
	scanf("%d",&n);
	int ans = 0;
	while (n--)
	{
		cin>>str;
		if (str.find('+')!=string::npos) ans++;
		else ans --;
	}
	printf("%d\n",ans);
	return 0;
}
