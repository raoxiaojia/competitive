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
	int n,m;
	cin>>n>>m;
	int min = (n+1)/2;
	int max = n;
	if ((max<m) && (m!=1)) cout<<-1<<endl;
	else
	{
		cout<<(min+m-1)/m*m<<endl;
	}
	return 0;
}
