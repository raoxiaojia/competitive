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
	int n;
	cin>>n;
	int i = 0;
	while (n--)
	{
		if (i % 2 == 0)
		{
			cout<<"I hate ";
		}
		else
		{
			cout<<"I love ";
		}
		i++;
		if (n)
		{
			cout<<"that ";
		}
	}
	cout<<"it"<<endl;
	return 0;
}
