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
	int a,b,c,d,e;
	cin>>a>>b>>c>>d>>e;
	a = a+b+c+d+e;
	if ((a%5==0) && (a!=0)) cout<<a/5<<endl;
	else cout<<-1<<endl;
	return 0;
}
