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

int h;

int initiallist[20];

int inicount;

int query[20];

int ans[20][4];

int asked[300];

int qcount = 0;

void sendquery(int x)
{
	printf("? %d\n",x);
	query[qcount] = x;
	asked[x] = 1;
	fflush(stdout);
	qcount ++;
}

void getans()
{
	cin>>ans[qcount-1][0];
	for (int i=0;i<ans[qcount-1][0];i++) cin>>ans[qcount-1][i+1];
}

void printans(int x)
{
	printf("! %d\n",x);
	fflush(stdout);
}

void bfsans(int x)
{
	int list[100];
					int s = 0;
					int t = 1;
					memset(list,0,sizeof(list));
					list[0] = x;
					while (s<t)
					{
						sendquery(list[s]);
						getans();
						if (ans[qcount-1][0] == 2)
						{
							printans(query[qcount-1]);
	return;
						}
						if (ans[qcount-1][0] == 1)
						{
							s++;
							continue;
						}
						for (int i=1;i<=3;i++)
						{
							if (asked[ans[qcount-1][i]]) continue;
							list[t] = ans[qcount-1][i];
							t++;
						}
						s++;
					}
}

void findfather(int x)
{
	
}

int main()
{
	int t;
	int i,j,k,l;
	cin>>t;
	while (t)
	{
start:;
		t--;
		cin>>h;
		if (h<=4)
		{
			for (i=1;i<(1<<h);i++)
			{
				printf("? %d\n",i);
				fflush(stdout);
				cin>>l;
				for (j=0;j<l;j++)
				{
					cin>>k;
				}
				if (l == 2)
				{
					printans(i);
					break;
				}
			}
			continue;
		}
		memset(asked,0,sizeof(asked));
		qcount = 0;
		memset(initiallist,0,sizeof(initiallist));
		inicount = 0;
		sendquery(2);
		getans();
		while (ans[qcount-1][0] == 3)
		{
			i=1;
			while (asked[ans[qcount-1][i]]) i++;
			sendquery(ans[qcount-1][i]);
			getans();
		}
		if (ans[qcount-1][0] == 2)
		{
			printans(query[qcount-1]);
			continue;
		}
		int depth;
		int curroot;
		if (qcount > 1)
		{
			int depth1 = qcount;
			sendquery(ans[0][2]);
			getans();
			while (ans[qcount-1][0] == 3)
			{
				i=1;
				while (asked[ans[qcount-1][i]]) i++;
				sendquery(ans[qcount-1][i]);
				getans();
			}
			int depth2 = qcount-depth1+1;
			if (depth1 == depth2)//query[0] is the current root, with depth  = depth1 = depth2
			{
				curroot = 0;
				depth = depth1;
			}
			else
			if (depth1 > depth2)
			{
				curroot = (depth1-depth2)/2;
				depth = depth1 - curroot;
			}
			else
			{
				curroot = (depth1+depth2)/2-1;
				depth = depth2 - (depth2-depth1)/2;
			}
		}
		else
		{
			curroot = 0;
			depth = 1;
		}
		if (h-depth <= 3)
		{
			for (i=1;i<=3;i++)
			{
				if (!asked[ans[curroot][i]])
				{
					bfsans(ans[curroot][i]);
					goto start;
				}
			}
		}
		else
		while (h-depth>3)
		{
			curroot = findfather(curroot);
			depth ++;
		}
		for (i=1;i<=3;i++)
		{
			if (!asked[ans[curroot][i]])
			{
				bfsans(ans[curroot][i]);
				goto start;
				break;
			}
		}
	}
	return 0;
}
