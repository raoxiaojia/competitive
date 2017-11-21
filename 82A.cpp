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

string name[5] = {"Sheldon","Leonard","Penny","Rajesh","Howard"};

int main()
{
	int n;
	int mult;
	cin>>n;
	mult = 1;
	n --;
	while (n>=mult*5)
	{
		n-=mult*5;
		mult <<= 1;
	}
	cout<<name[n/mult];
	return 0;
}
