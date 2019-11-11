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

vector<int> stack;

int main()
{
	int n;
	string str;
	cin>>n>>str;
	int i,j;
	for (i=0;i<n;i++)
	{
		if (stack.empty())
		{
			stack.push_back(str[i]);
			continue;
		}
		if (stack.back() == str[i])
		{
			stack.push_back(str[i]);
		}
		else
		{
			stack.pop_back();
		}
	}
	cout<<stack.size()<<endl;
	return 0;
}
