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

int main()
{
		int n;
		vector<int> rank;
		cin>>n;
		rank.clear();
		int i,j,k;
		for (i=0;i<2*n;i++) 
		{
			cin>>j;
			rank.push_back(j);
		}
		sort(rank.begin(),rank.end());
		if (rank[n] == rank[n-1]) printf("NO\n");
		else printf("YES\n");
		return 0;
}