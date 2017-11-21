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
	long long n,m;
	cin>>n>>m;
	if (m<=(n+1)/2) cout<<m*2-1<<endl;
	else cout<<(m-(n+1)/2)*2<<endl;
	return 0;
}
