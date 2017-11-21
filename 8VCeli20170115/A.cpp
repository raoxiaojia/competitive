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
	int x;
	cin>>x;
	switch (x)
	{
		case 1: cout<<3<<endl; break;
		case 2: cout<<4<<endl; break;
		default: cout<<x-2<<endl; break;
	}
	return 0;
}
