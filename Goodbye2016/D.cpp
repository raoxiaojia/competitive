#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>

#define MAX 340

int board[MAX][MAX][8];

int tmpboard[MAX][MAX][8];

int used[MAX][MAX];

int dir[8][2] = 
{
	{0,1},
	{0,-1},
	{1,0},
	{-1,0},
	{1,1},
	{1,-1},
	{-1,1},
	{-1,-1}
};

using namespace std;

void explode(int x,int y,int k)
{
	switch(k)
	{
		case 0: tmpboard[x][y][4] = 1; tmpboard[x][y][6] = 1; break;
		case 1: tmpboard[x][y][5] = 1; tmpboard[x][y][7] = 1; break;
		case 2: tmpboard[x][y][4] = 1; tmpboard[x][y][5] = 1; break;
		case 3: tmpboard[x][y][6] = 1; tmpboard[x][y][7] = 1; break;
		case 4: tmpboard[x][y][0] = 1; tmpboard[x][y][2] = 1; break;
		case 5: tmpboard[x][y][1] = 1; tmpboard[x][y][2] = 1; break;
		case 6: tmpboard[x][y][0] = 1; tmpboard[x][y][3] = 1; break;
		case 7: tmpboard[x][y][1] = 1; tmpboard[x][y][3] = 1; break;
	}
}

int main()
{
	int n;
	int i,j,k,l;
	cin>>n;
	board[MAX/2][MAX/2][0] = 1;
	while (n)
	{
		n--;
		int t;
		cin>>t;
		for (i=0;i<MAX;i++)
		{
			for (j=0;j<MAX;j++)
			{
				for (k=0;k<8;k++)
				{
					if (board[i][j][k])
					{
						for (l=1;l<=t;l++)
						{
							used[i+dir[k][0]*l][j+dir[k][1]*l] = 1;
						}
						int cx,cy;
						cx = i+dir[k][0]*t;
						cy = j+dir[k][1]*t;
						explode(cx,cy,k);
					}
				}
			}
		}
		memcpy(board,tmpboard,sizeof(tmpboard));
		memset(tmpboard,0,sizeof(tmpboard));
	}
	int ans = 0;
	for (i=0;i<MAX;i++)
	{
		for (j=0;j<MAX;j++)
		{
			for (k=0;k<8;k++)
			{
				if (used[i][j] > 0)
				{
					ans ++;
					break;
				}
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
