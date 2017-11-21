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

int board[100][100];

const int dir[4][2] = 
{
	{1,0},
	{0,1},
	{1,1},
	{1,-1}
};

int main()
{
	string str[4];
	int i,j,k;
	for (i=0;i<4;i++) cin>>str[i];
	for (i=0;i<4;i++)
	{
		for (j=0;j<4;j++)
		{
			board[i+10][j+10] = str[i][j];
		}
	}
	for (i=10;i<14;i++)
	{
		for (j=10;j<14;j++)
		{
			if (board[i][j] == '.')
			{
				for (k=0;k<4;k++)
				{
					if ((board[i-dir[k][0]][j-dir[k][1]] == 'x') && (board[i-2*dir[k][0]][j-2*dir[k][1]] == 'x'))
					{
						printf("YES\n");
						return 0;
					}
					if ((board[i-dir[k][0]][j-dir[k][1]] == 'x') && (board[i+dir[k][0]][j+dir[k][1]] == 'x'))
					{
						printf("YES\n");
						return 0;
					}
					if ((board[i+dir[k][0]][j+dir[k][1]] == 'x') && (board[i+2*dir[k][0]][j+2*dir[k][1]] == 'x'))
					{
						printf("YES\n");
						return 0;
					}
				}
			}
		}
	}
	printf("NO\n");
	return 0;
}
