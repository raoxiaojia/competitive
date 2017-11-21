#include <bits/stdc++.h>

using namespace std;

int n,r;

int f[100],s[100];
double p[100];

double ans[60][6000];

double min(double x,double y)
{
	return x<y?x:y;
}

int main()
{
	int i,j,k;
	cin>>n>>r;
	for (i=1;i<=n;i++)
	{
		cin>>f[i]>>s[i]>>p[i];
		p[i] /= 100.0;
	}
	for (i=1;i<=n;i++)
	{
		for (j=0;j<6000;j++)
		{
			ans[i][j] = 1e80;
		}
	}
	for (i=1;i<=n;i++)
	{
		for (j=f[i];j<=5000;j++)
		{
			if (j>=s[i])
			ans[i][j] = min(
			ans[i-1][j-s[i]]+p[i]*f[i]+(1-p[i])*s[i],
			(ans[i-1][j-f[i]]+p[i]*f[i]+(1-p[i])*s[i])/p[i]
			);
			else 
			ans[i][j] = (ans[i-1][j-f[i]]+p[i]*f[i]+(1-p[i])*s[i])/p[i];
			ans[i][j] = min(ans[i][j],ans[i][j-1]);
	//		printf("%d %d %.3lf\n",i,j,ans[i][j]);
		}
	}
	printf("%.12lf\n",ans[n][r]);
	return 0;
}
