#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>
#include "weird_editor.h"
#include "message.h"

using namespace std;

long long mod = 1000000007;

long long qp10mod(long long x)
{
	long long cur = 10;
	long long res = 1;
	while (x)
	{
		if (x%2 == 1) res *= cur;
		res %= mod;
		x /= 2;
		cur = (cur*cur)%mod;
	}
	return res;
}

int main()
{
	long long n = GetNumberLength();
	long long nodes = NumberOfNodes();
	long long my_id = MyNodeId();
	long long ans=0;
	if (my_id != 0)
	{
		int i,j,k;
		int size = n/(nodes-1);
		int stop = (my_id!=nodes-1)?my_id*size:n;
		if ((my_id-1)*size == stop)
		{
			long long dnum;
			long long largest;
			long long prevans;
			Receive(my_id+1);
			dnum = GetLL(my_id+1);
			Receive(my_id+1);
			largest = GetLL(my_id+1);
			Receive(my_id+1);
			prevans = GetLL(my_id+1);
			
			PutLL(my_id-1,dnum);
			Send(my_id-1);
			PutLL(my_id-1,largest);
			Send(my_id-1);
			PutLL(my_id-1,prevans);
			Send(my_id-1);
			return 0;
		}
		int tmp[11];
		memset(tmp,0,sizeof(tmp));
		for (i=(my_id-1)*size;i<stop;i++)
		{
			long long cur = GetDigit(i);
			for (j=0;j<cur;j++) tmp[j] = 0;
			tmp[cur] ++;
		}
		if (my_id == nodes-1)
		{
			long long dnum = 0;
			long long tans = 0;
			long long largest = 0;
			for (i=9;i>=0;i--)
			{
				if (tmp[i] > 0)
				if (largest == 0) largest = i;
				while (tmp[i])
				{
					tans = (tans*10+i) % mod;
					tmp[i] --;
					dnum ++;
				}
			}
			PutLL(nodes-2,dnum);
			Send(nodes-2);
			PutLL(nodes-2,largest);
			Send(nodes-2);
			PutLL(nodes-2,tans);
			Send(nodes-2);
			return 0;
		}
		long long segans[11];
		long long segd[11];
		memset(segans,0,sizeof(segans));
		memset(segd,0,sizeof(segd));
		for (i=9;i>=0;i--)
		{
			segd[i] = segd[i+1]+tmp[i];
		}
		long long tans = 0;
		int clarge = 0;
		for (i=9;i>=0;i--)
		{
			while (tmp[i])
			{
				if (clarge == 0) clarge = i;
				tans = (tans*10+i) % mod;
				tmp[i] --;
			}
			segans[i] = tans;
		}
		long long dnum;
		long long largest;
		long long prevans;
		Receive(my_id+1);
		dnum = GetLL(my_id+1);
		Receive(my_id+1);
		largest = GetLL(my_id+1);
		Receive(my_id+1);
		prevans = GetLL(my_id+1);
		
		ans = (prevans+segans[largest]*qp10mod(dnum) % mod) % mod;
		dnum = dnum + segd[largest];
		if (largest < clarge) largest = clarge;
		PutLL(my_id-1,dnum);
		Send(my_id-1);
		PutLL(my_id-1,largest);
		Send(my_id-1);
		PutLL(my_id-1,ans);
		Send(my_id-1);
	}
	else
	{
		long long dnum;
		long long largest;
		long long prevans;
		Receive(1);
		dnum = GetLL(1);
		Receive(1);
		largest = GetLL(1);
		Receive(1);
		prevans = GetLL(1);
		ans = (prevans*qp10mod(n-dnum)) % mod;
		printf("%lld\n",ans);
	}
	return 0;
}
