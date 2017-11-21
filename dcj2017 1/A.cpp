#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>
#include "pancakes.h"
#include "message.h"

using namespace std;

int main()
{
	long long n = GetStackSize();
	long long nodes = NumberOfNodes();
	long long my_id = MyNodeId();
	long long ans=0;
	if (my_id != 0)
	{
		int i,j,k;
		long long size = n/(nodes-1);
		long long stop = (my_id!=nodes-1)?my_id*size:n;
		if (stop == (my_id-1)*size)
		{
			PutLL(0,0);
			Send(0);
			PutLL(0,-1);
			Send(0);
			PutLL(0,-1);
			Send(0);
			return 0;
		}
		long long prev = 0;
		long long first,last;
		first = GetStackItem((my_id-1)*size);
		last = GetStackItem(stop-1);
		for (i=(my_id-1)*size;i<stop;i++)
		{
			long long cur = GetStackItem(i);
			if (cur<prev)
			{
				ans ++;
			}
			prev = cur;
		}
		PutLL(0,ans);
		Send(0);
		PutLL(0,first);
		Send(0);
		PutLL(0,last);
		Send(0);
	}
	else
	{
		int i;
		long long prev = 0;
		for (i=1;i<nodes;i++)
		{
			long long j,k;
			Receive(i);
			j = GetLL(i);
			ans += j;
			Receive(i);
			j = GetLL(i);
			if (j != -1)
			if (j<prev) ans++;
			Receive(i);
			j= GetLL(i);
			if (j != -1)
			prev = j;
		}
		printf("%lld\n",ans+1);
	}
	return 0;
}
