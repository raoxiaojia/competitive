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

int stime[212][5];

//0=submission,1=correct
int sta[5][2];

//min subs needed for question i to be class j
int greq[5][6];

int choice[5];

int currank[5];

int best = -1;

int findmax()
{
	int i;
	int res = 0;
	for (i=0;i<5;i++)
	{
		if (greq[i][choice[i]]>res)
		res = greq[i][choice[i]];
	}
	return res;
}

inline int getscore(int maxscore,int t)
{
	if (t == -1) return 0;
	return maxscore*250-t*maxscore;
}

void update(int x)
{
	if (x == -1) return;
	if ((best == -1) || (x<best))
	{
		best = x;
	}
}

int getrank(int y,int x)
{
	if (x*2>y) return 2;
	if (x*4>y) return 4;
	if (x*8>y) return 6;
	if (x*16>y) return 8;
	if (x*32>y) return 10;
	return 12;
}

void check(int x)
{
//	printf("checking %d\n",x);
	int i,j,k;
	int s1 = 0;
	int s2 = 0;
	for (i=0;i<5;i++)
	{
		if (stime[0][i] == -1)
		{
			if (stime[1][i] != -1) s2 += getscore(getrank(sta[i][0]+x,sta[i][1]),stime[1][i]);
	//		printf("choice=%d,s1=%d,s2=%d\n",getrank(sta[i][0]+x,sta[i][1]),s1,s2);
		}
		else
		{
			if ((stime[1][i] == -1) || (stime[0][i] < stime[1][i]))
			{
				j = currank[i];
				while ((j<=4) && (greq[i][j+1] <= x)) j++;
				s1 += getscore(j*2+2,stime[0][i]);
				s2 += getscore(j*2+2,stime[1][i]);
		//		printf("choice=%d,s1=%d,s2=%d\n",j,s1,s2);
			}
			else
			{
				j = currank[i];
				while ((j>=1) && (greq[i][j-1] <= x)) j--;
				s1 += getscore(j*2+2,stime[0][i]);
				s2 += getscore(j*2+2,stime[1][i]);
			//	printf("choice=%d,s1=%d,s2=%d\n",j,s1,s2);
			}
		}
	}
	if (s1>s2)
	{
		if ((best == -1) || (best>x)) best = x;
	}
}

int main()
{
	int n;
	int i,j,k;
	cin>>n;
	for (i=0;i<n;i++)
	{
		for (j=0;j<5;j++)
		{
			cin>>stime[i][j];
			if (stime[i][j] == -1)
			{
				sta[j][0] ++;
			}
			else
			{
				sta[j][0] ++;
				sta[j][1] ++;
			}
		}
	}
	for (i=0;i<5;i++)
	{
		int x = sta[i][1];
		int y = sta[i][0];
		if (2*x>y)
		{
			greq[i][0] = 0;
			greq[i][1] = 2*x-y;
			greq[i][2] = 4*x-y;
			greq[i][3] = 8*x-y;
			greq[i][4] = 16*x-y;
			greq[i][5] = 32*x-y;
			currank[i] = 0;
		}
		else
		if (4*x>y)
		{
			greq[i][0] = y-2*x+1;
			greq[i][1] = 0;
			greq[i][2] = 4*x-y;
			greq[i][3] = 8*x-y;
			greq[i][4] = 16*x-y;
			greq[i][5] = 32*x-y;
			currank[i] = 1;
		}
		else
		if (8*x>y)
		{
			greq[i][0] = y-2*x+1;
			greq[i][1] = (y-4*x)/3+1;
			greq[i][2] = 0;
			greq[i][3] = 8*x-y;
			greq[i][4] = 16*x-y;
			greq[i][5] = 32*x-y;
			currank[i] = 2;
		}
		else
		if (16*x>y)
		{
			greq[i][0] = y-2*x+1;
			greq[i][1] = (y-4*x)/3+1;
			greq[i][2] = (y-8*x)/7+1;
			greq[i][3] = 0;
			greq[i][4] = 16*x-y;
			greq[i][5] = 32*x-y;
			currank[i] = 3;
		}
		else
		if (32*x>y)
		{
			greq[i][0] = y-2*x+1;
			greq[i][1] = (y-4*x)/3+1;
			greq[i][2] = (y-8*x)/7+1;
			greq[i][3] = (y-16*x)/15+1;
			greq[i][4] = 0;
			greq[i][5] = 32*x-y;
			currank[i] = 4;
		}
		else
		{
			greq[i][0] = y-2*x+1;
			greq[i][1] = (y-4*x)/3+1;
			greq[i][2] = (y-8*x)/7+1;
			greq[i][3] = (y-16*x)/15+1;
			greq[i][4] = (y-32*x)/31+1;
			greq[i][5] = 0;
			currank[i] = 5;
		}
	}
	for (i=0;i<5;i++)
	{
		for (j=0;j<6;j++)
		{
			check(greq[i][j]);
		}
	}
	cout<<best<<endl;
	return 0;
}
