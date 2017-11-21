#include <bits/stdc++.h>

using namespace std;

int n;

int main()
{
	int i;
	cin>>n;
	while (n--)
	{
		cin>>i;
		if (i <= 3)
		{
			printf("-1\n");
			continue;
		}
		if ((i%4 == 0) || (i%4 == 2))
		{
			printf("%d\n",i/4);
		}
		else
		{
			if ((i == 5) || (i == 7) ||(i == 11))
			{
				printf("-1\n");
				continue;
			}
			else
			{
				printf("%d\n",(i-9)/4+1);
			}
		}
	}
	return 0;
}
