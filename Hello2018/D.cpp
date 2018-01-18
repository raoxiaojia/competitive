#include "bits/stdc++.h"

using namespace std;

typedef pair<int,int> ii;

typedef pair<int,ii> iii;

bool cmp(iii x,iii y)
{
	return x.second.first>y.second.first;
}

bool cmp2(iii x,iii y)
{
	return x.second.second<y.second.second;
}

vector<iii> prob;

iii mp3(int x,int y,int z)
{
	iii res;
	res.first = x;
	res.second.first = y;
	res.second.second = z;
	return res;
}

int n,t;

int best = 0;

int main()
{
	int i,j,k;
	cin>>n>>t;
	for (i=0;i<n;i++)
	{
		scanf("%d %d",&j,&k);
		prob.push_back(mp3(i+1,j,k));
	}
	sort(prob.begin(),prob.end(),cmp);
	int s = 0;
	int tail = n;
	while (s<=tail)
	{
		int mid = (s+tail)/2;
		vector<iii> newprob;
		newprob.clear();
		i=0;
		while (prob[i].second.first >= mid)
		{
			newprob.push_back(prob[i]);
			i++;
			if (i==n) break;
		}
		if (newprob.size() < mid)
		{
			tail=mid-1;
			continue;
		}
		sort(newprob.begin(),newprob.end(),cmp2);
		int curtime = 0;
		for (i=0;i<mid;i++)
		{
			curtime += newprob[i].second.second;
			if (curtime > t) break;
		}
		if (curtime > t) tail = mid-1;
		else
		{
			best = mid;
			s = mid+1;
		}
	}
	vector<iii> newprob;
	newprob.clear();
	i=0;
	while (prob[i].second.first>=best)
	{
		newprob.push_back(prob[i]);
		i++;
		if (i==n) break;
	}
	sort(newprob.begin(),newprob.end(),cmp2);
	printf("%d\n%d\n",best,best);
	for (i=0;i<best;i++)
	{
		printf("%d ",newprob[i].first);
	}
	printf("\n");
	return 0;
}
