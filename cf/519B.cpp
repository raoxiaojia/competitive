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

vector<int> s1,s2,s3;

bool cmp(int x,int y)
{
	return x<y?true:false;
}

int main()
{
	int n;
	cin>>n;
	s1.reserve(n);
	s2.reserve(n);
	s3.reserve(n);
	int i,j;
	for (i=0;i<n;i++)
	{
		cin>>j;
		s1.push_back(j);
	}
	for (i=0;i<n-1;i++)
	{
		cin>>j;
		s2.push_back(j);
	}
	for (i=0;i<n-2;i++)
	{
		cin>>j;
		s3.push_back(j);
	}
	sort(s1.begin(),s1.end(),cmp);
	sort(s2.begin(),s2.end(),cmp);
	sort(s3.begin(),s3.end(),cmp);
	i = -1;
	j = -1;
	while ((i<0) || (j<0))
	{
		if (s1.back() != s2.back())
		{
			i=s1.back();
			s1.pop_back();
			continue;
		}
		if (s2.back() != s3.back())
		{
			j=s2.back();
			s1.pop_back();
			s2.pop_back();
			continue;
		}
		s1.pop_back();
		s2.pop_back();
		s3.pop_back();
	}
	cout<<i<<endl<<j<<endl;
	return 0;
}
