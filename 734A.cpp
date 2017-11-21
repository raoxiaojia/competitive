#include "bits/stdc++.h"

using namespace std;

int main()
{
	int n,x=0;
	string str;
	cin>>n;
	cin>>str;
	while (n)
	{
		n--;
		x += str[n]=='A'?1:-1;
	}
	if (x>0) cout<<"Anton"<<endl;
	else if (x<0) cout<<"Danik"<<endl;
	else cout<<"Friendship"<<endl;
	return 0;
}
