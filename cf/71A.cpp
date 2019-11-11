#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <iostream>

using namespace std;

int main()
{
	int n;
	string str;
	scanf("%d",&n);
	while (n--)
	{
		cin>>str;
		if (str.length()<=10)
		{
			cout<<str<<endl;
			continue;
		}
		printf("%c%d%c\n",str[0],str.length()-2,str[str.length()-1]);
	}
	return 0;
}
