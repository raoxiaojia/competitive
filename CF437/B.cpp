#include <bits/stdc++.h>

using namespace std;

long long n,s;

long long req[100005],a[100005],b[100005],d[100005];

typedef pair<long long, long long> ii;

long long ans = 0;
long long total = 0;
vector<ii> info;

ii makepair(long long x,long long y)
{
	ii res;
	res.first = x;
	res.second = y;
	return res;
}

bool cmp(ii x,ii y)
{
	return x.second>y.second;
}

long long max(long long x,long long y)
{
	return x>y?x:y;
}

long long calc(long long t2)
{
	int i,j,k;
	long long res = 0;
	if (t2<0) return -1e16;
	long long t1 = total-t2;
	if (t1<0) return -1e16;
	t1 *= s;
	t2 *= s;
	for (i=0;i<n;i++)
	{
		if (info[i].second>0)
		{
			if (info[i].first < t2)
			{
				t2 -= info[i].first;
				res += info[i].first * info[i].second;
			}
			else
			{
				res += t2 * info[i].second;
				t2 = 0;
				break;
			}
		}
		else break;
	}
	for (i=n-1;i>=0;i--)
	{
		if (info[i].second<0)
		{
			if (info[i].first < t1)
			{
				t1 -= info[i].first;
			}
			else
			{
				res += (info[i].first - t1) * info[i].second;
				t1 = 0;
			}
		}
		else break;
	}
	return res;
}

int main()
{
	cin>>n>>s;
	int i,j,k;
	for (i=0;i<n;i++)
	{
		cin>>req[i]>>a[i]>>b[i];
		d[i]=b[i]-a[i];
		ans += a[i]*req[i];
		info.push_back(makepair(req[i],d[i]));
	}
	long long better = 0;
	sort(info.begin(),info.end(),cmp);
	for (i=0;i<n;i++)
	{
		better += d[i]>0?req[i]:0;
		total += req[i];
	}
	total = (total-1)/s+1;
	cout<<ans+max(calc(better/s-1),max(calc(better/s),calc(better/s+1)))<<endl;
	return 0;
}
