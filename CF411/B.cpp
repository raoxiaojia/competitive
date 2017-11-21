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
	string str;
	cin>>str;
	int n = str.length();
	int i,j,k;
	long long ans = 0;
	long long mod = 1000000007;
	long long nb = 0;
	for (i=n-1;i>=0;i--)
	{
		if (str[i] == 'b')
		{
			nb = (nb+1)%mod;
		}
		else
		if (str[i] == 'a')
		{
			ans = (ans+nb)%mod;
			nb = (nb*2)%mod;
		}
	}
	printf("%d\n",(int)(ans%mod));
	return 0;
}
