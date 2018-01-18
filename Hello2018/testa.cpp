#include <cmath>
#include <iostream>

using namespace std;

int main()
{
	long long n,m;
	cin>>n>>m;
	long long expo = pow(2,n);
	cout<<m%expo<<endl;
	return 0;
}
