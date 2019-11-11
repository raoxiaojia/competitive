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
	long long n;
	cin>>n;
	if (n%2 == 0) cout<<n/2;
	else cout<<(n-1)/2-n;
	return 0;
}
