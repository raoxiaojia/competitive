#include <bits/stdc++.h>

using namespace std;

int n;

int xres[2][10000];

typedef vector<int> vi;

vector<vi> poss;

vi curans;
vi curinv;

int main()
{
	int i,j,k;
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{
		printf("? 0 %d\n",i);
		fflush(stdout);
		scanf("%d",&xres[0][i]);
	}
	for (i=0;i<n;i++)
	{
		printf("? %d 0\n",i);
		fflush(stdout);
		scanf("%d",&xres[1][i]);
	}
	for (i=0;i<n;i++)
	{
		curans.push_back(0);
		curinv.push_back(0);
	}
	for (i=0;i<n;i++)
	{
		curans[0] = i;
		int success = 1;
		for (j=0;j<n;j++)
		{
			curinv[j] = curans[0]^xres[0][j];
			if (curinv[j]>=n)
			{
				success =0;
				break;
			}
		}
		for (j=1;j<n;j++)
		{
			curans[j] = curinv[0]^xres[1][j];
			if (curans[j]>=n)
			{
				success = 0;
				break;
			}
		}
		if (!success) continue;
		for (j=0;j<n;j++)
		{
			if (curans[curinv[j]] != j)
			{
				success = 0;
				break;
			}
		}
		if (!success) continue;
		for (j=0;j<poss.size();j++)
		{
			success = 0;
			for (k=0;k<n;k++)
			{
				if (poss[j][k] != curans[k])
				{
					success = 1;
					break;
				}
			}
			if (!success) break;
		}
		if (!success) continue;
		poss.push_back(curans);
	}
	printf("!\n%d\n",poss.size());
	vi tmp = poss[0];
	for (i=0;i<n;i++)
	{
		printf("%d ",tmp[i]);
	}
	fflush(stdout);
	return 0;
}
