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

string name[20];

int t;
int n,m;

int belong[200];

int possible[200][20];

string message[200];

int update()
{
	int change = 1;
	int i,j,k;
	while (change)
	{
		change = 0;
		for (i=0;i<m;i++)
		{
			int sum = 0;
			int pos = 0;
			for (j=0;j<n;j++)
			{
				sum += possible[i][j];
				if (possible[i][j]) pos = j;
			}
			if (sum == 0) return -1;
			if ((sum == 1) && (belong[i] == -1))
			{
				belong[i] = pos;
				change = 1;
			}
			if ((i>0) && (belong[i] >= 0))
			{
				if (possible[i-1][belong[i]])
				{
					possible[i-1][belong[i]] = 0;
					change = 1;
				}
			}
			if ((i<m-1) && (belong[i] >= 0))
			{
				if (possible[i+1][belong[i]])
				{
					possible[i+1][belong[i]] = 0;
					change = 1;
				}
			}
		}
	}
	for (i=1;i<m;i++)
	{
		if ((belong[i-1] == belong[i]) && (belong[i] >= 0)) return -1;
	}
	return 0;
}

int dfs(int d)
{
	if (d >= m)
	{
		return 1;
	}
	if (belong[d] >= 0) return dfs(d+1);
	if (update() == -1) return -1;
	int i,j;
	for (i=0;i<n;i++)
	{
		if (possible[d][i])
		{
			int tmp[20];
			memcpy(tmp,possible[d],sizeof(tmp));
			for (j=0;j<n;j++)
			{
				possible[d][j] = 0;
			}
			possible[d][i] = 1;
			belong[d] = i;
			int res = dfs(d+1);
			if (res == 1) return 1;
			belong[d] = -1;
			memcpy(possible[d],tmp,sizeof(tmp));
		}
	}
	return -1;
}

bool isletter(char ch)
{
	if ((ch>='A') && (ch <= 'Z')) return true;
	return false;
}

bool isdigit(char ch)
{
	if ((ch >= '0') && (ch <= '9')) return true;
	return false;
}

int main()
{
	cin>>t;
	int i,j,k;
	while (t--)
	{
		cin>>n;
		for (i=0;i<n;i++)
		{
			cin>>name[i];
		}
		cin>>m;
		for (i=0;i<m;i++)
		{
			char ch;
			belong[i] = -1;
			string curstr;
			string curname;
			curname.clear();
			cin>>ch;
			while (ch != ':')
			{
				if (isletter(ch) || isdigit(ch) || (ch == '?'))
				curname += ch;
				cin>>ch;
			}
			if (curname != "?")
			{
				for (j=0;j<n;j++)
				{
					if (curname == name[j])
					{
						belong[i] = j;
						for (k=0;k<n;i++)
						{
							possible[i][k] = 0;
						}
						possible[i][j] = 1;
						break;
					}
				}
				continue;
			}
			getline(cin,curstr);
			message[i] = curstr;
			for (j=0;j<n;j++)
			{
				if (curstr.find(name[j]) != string::npos)
				{
					possible[i][j] = 0;
				}
				else
				{
					possible[i][j] = 1;
				}
			}
		}
		if (update() == -1)
		{
			printf("Impossible\n");
		}
		else
		if (dfs(0) == -1)
		{
			printf("Impossible\n");
		}
		else
		for (i=0;i<m;i++)
		{
			cout<<name[belong[i]]<<':'<<message[i]<<endl;
		}
	}
	return 0;
}
