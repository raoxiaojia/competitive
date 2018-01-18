#include "bits/stdc++.h"

using namespace std;

string s0;

string s1,s2,s3;

int q,n;
unsigned long long m;

unsigned long long len[150000];

char getans(int n, unsigned long long x)
{
	int i,j,k;
	if (n == 0)
	{
		if (x>len[0]) return '.';
		return s0[x-1];
	}
	if (len[n] == 0)
	{
		return getans(n-1,x-s1.length());
	}
	if (len[n] < x)
	{
		return '.';
	}
	if (s1.length()>=x)
	{
		return s1[x-1];
	}
	if (len[n-1]+s1.length()>=x)
	{
		return getans(n-1,x-s1.length());
	}
	if (len[n-1]+s1.length()+s2.length()>=x)
	{
		return s2[(x-len[n-1]-s1.length()-1)];
	}
	if (len[n-1]+s1.length()+s2.length()+len[n-1]>=x)
	{
		return getans(n-1,x-len[n-1]-s1.length()-s2.length());
	}
	return s3[x-len[n-1]*2-s1.length()-s2.length()-1];
}

int main()
{
	s0 = "What are you doing at the end of the world? Are you busy? Will you save us?";
	s1 = "What are you doing while sending \"";
	s2 = "\"? Are you busy? Will you send \"";
	s3 = "\"?";
	int i,j,k;
	len[0] = s0.length();
	for (i=1;i<=100;i++)
	{
		len[i] = len[i-1]*2+s1.length()+s2.length()+s3.length();
		if (len[i] > 1e18) break;
	}
	scanf("%d",&q);
	for (i=0;i<q;i++)
	{
		cin>>n>>m;
		cout<<getans(n,m);
	}
	return 0;
}
