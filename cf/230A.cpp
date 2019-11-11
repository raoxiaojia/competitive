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

typedef pair<int,int> ii;

vector<ii> dragon;

bool cmp(ii x, ii y)
{
	return x.first<y.first?true:false;
}

int main()
{
	int s,n;
	int a,b;
	cin>>s>>n;
	dragon.clear();
	dragon.reserve(100000);
	for (int i=0;i<n;i++)
	{
		cin>>a>>b;
		dragon.push_back(make_pair(a,b));
	}
	sort(dragon.begin(),dragon.end(),cmp);
	for (int i=0;i<n;i++)
	{
		if (s<=dragon[i].first)
		{
			printf("NO\n");
			return 0;
		}
		s += dragon[i].second;
	}
	printf("YES\n");
	return 0;
}
