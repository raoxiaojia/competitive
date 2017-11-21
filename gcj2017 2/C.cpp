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

int t;

int r,c;

string grid[60];

vector<int> bpos,dpos;

//vertical=true,horizontal=false
short g[6000][6000],g2[6000][6000];

vector<int> adj[10000],adj2[10000];

int bcode[10000],dcode[10000];

//1 = true,-1 = false,0=unknown
int bstate[10000];

int mark[10000];

void addedge(int x,int y)
{
	g[x][y] = 1;
	adj[x].push_back(y);
}

int stack[100000];

int sd = 0;

int comp[10000];

int counter = 0;

void dfs1(int x)
{
	mark[x] = 1;
	for (int i=0;i<adj[x].size();i++)
	{
		if (!mark[adj[x][i]]) dfs1(adj[x][i]);
	}
	stack[sd] = x;
	sd ++;
}

void dfs2(int x)
{
	mark[x] = 1;
	for (int i=0;i<adj2[x].size();i++)
	{
		if (!mark[adj2[x][i]]) dfs2(adj2[x][i]);
	}
	comp[x] = counter;
}

void no(int x)
{
	printf("Case #%d: IMPOSSIBLE\n",x+1);
}

int main()
{
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	cin>>t;
	int i,j,k,l;
	for (l=0;l<t;l++)
	{
		memset(adj,0,sizeof(adj));
		memset(bcode,0,sizeof(bcode));
		memset(dcode,0,sizeof(dcode));
		memset(bstate,0,sizeof(bstate));
		memset(mark,0,sizeof(mark));
		memset(adj2,0,sizeof(adj2));
		bpos.clear();
		dpos.clear();
		cin>>r>>c;
		for (i=0;i<r;i++)
		{
			cin>>grid[i];
			for (j=0;j<c;j++)
			{
				if ((grid[i][j] == '-') || (grid[i][j] == '|'))
				{
					bpos.push_back(i*c+j);
					bcode[i*c+j] = bpos.size()-1;
				}
				if (grid[i][j] == '.')
				{
					dpos.push_back(i*c+j);
					dcode[i*c+j] = dpos.size()-1;
				}
			}
		}
		
		for (i=0;i<bpos.size();i++)
		{
			int cr = bpos[i]/c;
			int cc = bpos[i]%c;
			while (cr>0)
			{
				cr--;
				if ((grid[cr][cc] == '-') || (grid[cr][cc] == '|'))
				{
					bstate[i] = -1;
					bstate[bcode[cr*r+cc]] = -1;
				}
				if (grid[cr][cc] == '#') break;
			}
			cr = bpos[i]/c;
			while (cc>0)
			{
				cc--;
				if ((grid[cr][cc] == '-') || (grid[cr][cc] == '|'))
				{
					if ((bstate[i] == -1) || (bstate[bcode[cr*r+cc]] == -1))
					{
						no(l);
						goto next;
					}
					bstate[i] = 1;
					bstate[bcode[cr*r+cc]] = 1;
				}
				if (grid[cr][cc] == '#') break;
			}
		}
		
		for (i=0;i<dpos.size();i++)
		{

			int cr = dpos[i]/c;
			int cc = dpos[i]%c;
			int vb = -1,hb = -1;
			while (cr>0)
			{
				cr--;
				if ((grid[cr][cc] == '-') || (grid[cr][cc] == '|'))
				{
					//need vertical = true;
					if (bstate[bcode[cr*r+cc]] == 1) goto nextd;
					if (bstate[bcode[cr*r+cc]] == 0) vb = bcode[cr*r+cc];
					break;
				}
				if (grid[cr][cc] == '#')
				{
					break;
				}
			}
			cr = dpos[i]/c;
			while (cr<r-1)
			{
				cr++;
				if ((grid[cr][cc] == '-') || (grid[cr][cc] == '|'))
				{
					//need vertical = true;
					if (bstate[bcode[cr*r+cc]] == 1) goto nextd;
					if (bstate[bcode[cr*r+cc]] == 0) vb = bcode[cr*r+cc];
					break;
				}
				if (grid[cr][cc] == '#')
				{
					break;
				}
			}
			cr = dpos[i]/c;
			while (cc>0)
			{
				cc--;
				if ((grid[cr][cc] == '-') || (grid[cr][cc] == '|'))
				{
					if (bstate[bcode[cr*r+cc]] == -1) goto nextd;
					if (bstate[bcode[cr*r+cc]] == 0) hb = bcode[cr*r+cc];
					break;
				}
				if (grid[cr][cc] == '#')
				{
					break;
				}
			}
			cc = dpos[i]%c;
			while (cc<c-1)
			{
				cc++;
				if ((grid[cr][cc] == '-') || (grid[cr][cc] == '|'))
				{
					if (bstate[bcode[cr*r+cc]] == -1) goto nextd;
					if (bstate[bcode[cr*r+cc]] == 0) hb = bcode[cr*r+cc];
					break;
				}
				if (grid[cr][cc] == '#')
				{
					break;
				}
			}
			if ((vb == -1) && (hb == -1))
			{
				no(l);
				goto next;
			}
			if (vb == -1)
			{
				bstate[hb] = -1;
				continue;
			}
			if (hb == -1)
			{
				bstate[vb] = 1;
				continue;
			}
			addedge(vb+bpos.size(),hb+bpos.size());
			addedge(hb,vb);
nextd:;
		}
		
		for (i=0;i<bpos.size();i++)
		{
			if (bstate[i] == 1)
			{
				addedge(i+bpos.size(),i);
			}
			if (bstate[i] == -1)
			{
				addedge(i,i+bpos.size());
			}
		}	
		
		//2-sat
		for (i=1;i<=2*bpos.size();i++)
		{
			if (!mark[i]) dfs1(i);
		}
		
		memset(mark,0,sizeof(mark));
		for (i=1;i<=2*bpos.size();i++)
		{
			for (j=0;j<adj[i].size();j++)
			{
				k = adj[i][j];
				adj2[k].push_back(i);
				g2[k][i] = 1;
			}
		}
		
		counter = 0;
		while (sd > 0)
		{
			sd--;
			j = stack[sd];
			if (!mark[j])
			{
				counter++;
				dfs2(j);
			}
		}
		
		for (i=1;i<=bpos.size();i++)
		{
			if (comp[i] == comp[i+r*c])
			{
				no(l);
				goto next;
			}
			if (comp[i]<comp[i+r*c])
			{
				bstate[i] = -1;
			}
			else
			{
				bstate[i] = 1;
			}
		}
		
		printf("Case #%d: POSSIBLE\n",l+1);
		for (i=0;i<r;i++)
		{
			for (j=0;j<c;j++)
			{
				if ((grid[i][j] == '|') || (grid[i][j] == '-'))
				{
					if (bstate[bcode[i*r+j]] == 1) printf("|");
					else printf("-");
				}
				else
				{
					printf("%c",grid[i][j]);
				}
			}
			printf("\n");
		}
		
		
next:;
	}
	return 0;
}
