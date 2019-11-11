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

const int hashmod = 1999993;

int h[2000000];

string st[2000000];

const int hdigit[32] = 
{
	401981,1042949,1173829,820213,1148857,400067,1110881,1192571,1043839,1074923,
	324889,879331,1087019,21737,843607,900037,70003,100931,254249,266671,
	310361,351851,393571,495211,530393,
	610661,645893,700883,796699,1044479,
	904931,1239803
	
};

int hash2(string str)
{
	int i;
	long long res = 0;
	for (i=0;i<str.length();i++)
	{
		res += (long long ) ((str[i]-'a'+1) * (str[i]-'a'+1)+1)*hdigit[i];
		res %= hashmod;
	}
	return res;
}

int main()
{
	int n;
	string str;
	cin>>n;
	while (n--)
	{
		cin>>str;
		int x = hash2(str);
		if (h[x] == 0)
		{
			printf("OK\n");
			st[x] = str;
			h[x] ++;
		}
		else
		{
			if (st[x] == str)
			{
				cout<<st[x]<<h[x]<<endl;
				h[x] ++;
			}
			else
			{
				while (h[x]>0)
				{
					x++;
					x%=hashmod;
					if (st[x] == str)
					{
						cout<<st[x]<<h[x]<<endl;
						h[x] ++;
						break;
					}
				}
				if (h[x] == 0)
				{
					st[x] = str;
					h[x] ++;
					printf("OK\n");
				}
			}
		}
	}
	return 0;
}
