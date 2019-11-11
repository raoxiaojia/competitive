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
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	if (b*c<=d)
	{
		cout<<a*c<<endl;
		return 0;
	}
	int tmp = (a+b-1)/b*d;
	tmp = tmp<a/b*d+a%b*c?tmp:a/b*d+a%b*c;
	cout<<tmp<<endl;
	return 0;
}
