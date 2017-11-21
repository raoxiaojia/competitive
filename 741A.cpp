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

int target[1000];

int sizec[1000];

int visited[1000];

long long gcd(long long x,long long y)
{
	return x%y==0?y:gcd(y,x%y);
}

int main()
{
	int n;
	cin>>n;
	int i,j,k;
	for (i=1;i<=n;i++) cin>>target[i];
	for (i=1;i<=n;i++)
	{
		if (!visited[i])
		{
			j = i;
			k = 0;
			while (!visited[j])
			{
				visited[j] = 1;
				k++;
				j = target[j];
			}
			if (j != i)
			{
				cout<<-1<<endl;
				return 0;
			}
			sizec[k] ++;
		}
	}
	long long ans = 1;
	for (i=1;i<=n;i++)
	{
		if (sizec[i]>0)
		{
			if (i%2 == 0) j = i/2;
			else j = i;
			ans = ans/gcd(ans,j)*j;
		}
	}
	cout<<ans<<endl;
	return 0;
}
