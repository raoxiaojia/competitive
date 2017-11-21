#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>
#include "todd_and_steven.h"
#include "message.h"

using namespace std;

long long mod = 1000000007;

vector<long long> x;

int main()
{
	long long nodes = NumberOfNodes();
	long long my_id = MyNodeId();
	if (my_id != 0)
	{

	}
	else
	{
		long long ans = 0;
		x.clear();
		int n,m;
		n = GetToddLength();
		int i,j,k;
		for (i=0;i<n;i++)
		{
			x.push_back(GetToddValue(i));
		}
		m = GetStevenLength();
		for (i=0;i<m;i++)
		{
			x.push_back(GetStevenValue(i));
		}
		n = x.size();
		sort(x.begin(),x.end());
		for (i=0;i<n;i++)
		{
			ans = (ans+(x[i]^(long long)i)) % mod;
		}
		cout<<ans;
	}
	return 0;
}
