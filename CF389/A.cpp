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
	int n,m,k;
	cin>>n>>m>>k;
	int a,b;
	a=(k-1)/(2*m);
	k-=a*2*m;
	b=(k-1)/2;
	k-=2*b;
	a++;
	b++;
	if (k%2==0) printf("%d %d R\n",a,b);
	else printf("%d %d L\n",a,b);
	return 0;
}
