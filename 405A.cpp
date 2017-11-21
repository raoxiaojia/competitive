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

bool cmp(int x,int y)
{
	return x<y?true:false;
}

int main()
{
	int n;
	vector<int> height;
	height.clear();
	height.reserve(200);
	cin>>n;
	int i,j;
	for (i=0;i<n;i++)
	{
		cin>>j;
		height.push_back(j);
	}
	sort(height.begin(),height.end(),cmp);
	for (i=0;i<n-1;i++) cout<< height[i] << " ";
	cout<<height[n-1]<<endl;
	return 0;
}
