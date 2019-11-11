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

long long dfs(int d,int cost)
{
	if (d == 1) return 1;
	return dfs(d-1,cost+1)+(cost+1)=*(d-1)+1;
}

int main()
{
	int n;
	cin>>n;
	cout<<dfs(n,0)<<endl;
	return 0;
}
