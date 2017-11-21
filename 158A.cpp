#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	int i,j,k;
	deque<int> score;
	scanf("%d %d",&n,&k);
	score.clear();
	for (i=0;i<n;i++)
	{
		scanf("%d",&j);
		score.push_back(j);
	}
	i = 0;
	j = 0;
	while ((k--) && (score.front()>0))
	{
		j = score.front();
		i++;
		score.pop_front();
	}
	if (j>0)
	while (score.front() == j)
	{
		i++;
		score.pop_front();
	}
	printf("%d\n",i);
	return 0;
}
