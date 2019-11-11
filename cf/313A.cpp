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
	if (n>0) cout<<n<<endl;
	else
	{
		n=-n;
		if (n%10>n/10%10) cout<<-n/10<<endl;
		else cout<<-(n/100*10+n%10)<<endl;
	}
	return 0;
}
