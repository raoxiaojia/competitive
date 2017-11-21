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

long long dfs(int x,int y)
{
	if (x==1) return 1;
	if (y==1) return 1;
	return dfs(x-1,y)+dfs(x,y-1);
}

int main()
{
	int n;
	cin>>n;
	cout<<dfs(n,n)<<endl;
	return 0;
}
