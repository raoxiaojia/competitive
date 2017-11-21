#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>
#include "query_of_death.h"
#include "message.h"

using namespace std;

int main()
{
	long long nodes = NumberOfNodes();
	long long my_id = MyNodeId();
	long long n = GetLength();
	if (my_id != 0)
	{
		int i,j,k;
		int size = n/(nodes-1);
		int stop = (my_id!=nodes-1)?my_id*size:n;
		if ((my_id-1)*size == stop)
		{
			PutLL(0,-1);
			Send(0);
			PutLL(0,0);
			Send(0);
			return 0;
		}
		short arr[2000000];
		int sum = 0;
		memset(arr,0,sizeof(arr));
		for (i=(my_id-1)*size;i<stop;i++)
		{
			arr[i-(my_id-1)*size] = GetValue(i);
			int broken = -1;
			for (j=0;j<100;j++)
			{
				k = GetValue(i);
				if (k != arr[i]-(my_id-1)*size)
				{
					broken = i;
					break;
				}
			}
			if (broken)
			{
				PutLL(0,broken);
				Send(0);
				PutLL(0,my_id);
				Send(0);
				PutLL(0,0);
				Send(0);
				return 0;
			}
			sum += arr[i-(my_id-1)*size];
		}
		PutLL(0,-1);
		Send(0);
		PutLL(0,sum);
		Send(0);
	}
	else
	{
		int i,j,k;
		int sum;
		int broken = -1;
		int bid = 0;
		for (i=1;i<nodes;i++)
		{
			Receive(i);
			j = GetLL(i);
			if (j != -1)
			{
				broken = 1;
				Receive(i);
				bid = GetLL(i);
			}
			Receive(i);
			j = GetLL(i);
			sum += j;
		}
		int size = n/(nodes-1);
		int stop = (bid!=nodes-1)?bid*size:n;
		for (i=(bid-1)*size;i<stop;i++)
		{
			if (i == broken) continue;
			j = GetValue(i);
			sum += j;
		}
		sum += GetValue(broken);
		printf("%lld\n",sum);
	}
	return 0;
}
