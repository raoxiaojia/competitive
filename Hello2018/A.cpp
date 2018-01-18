#include "bits/stdc++.h"

using namespace std;

int main()
{
	long long n,m;
	cin>>n>>m;
	if (n<30) printf("%d\n",m%(1<<n));
	else printf("%d\n",m);
	return 0;
}
