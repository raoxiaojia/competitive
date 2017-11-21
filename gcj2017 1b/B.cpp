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

int n;

int checker[300];

void printcom(int num,char c1,char c2)
{
	int i;
	for (i=0;i<num;i++)
	{
		printf("%c%c",c2,c1);
		checker[c1]++;
		checker[c2]++;
	}
}

void print2cans(int d1,int d2,int com1,int com2,char c1,char c2,char cc1,char cc2)
{
	int i,j,k;
	for (i=0;i<d1-1;i++)
	{
		printf("%c%c",c1,c2);
		checker[c1]++;
		checker[c2]++;
	}
	printf("%c",c1);
	printcom(com1,c1,cc1);
	printf("%c",c2);
	printcom(com2,c2,cc2);
	checker[c1]++;
	checker[c2]++;
}

void printans(int d1,int d2,int d3,int com1,int com2,int com3,char c1,char c2,char c3,char cc1,char cc2,char cc3)
{
	int ex = d2+d3-d1;
	int i,j,k;
	if (d3 == 0)
	{
		print2cans(d1,d2,com1,com2,c1,c2,cc1,cc2);
		return;
	}
	if (d2 == 0)
	{
		print2cans(d1,d3,com1,com3,c1,c3,cc1,cc3);
		return;
	}
	int p1,p2,p3;
	p1 = d1;
	p2 = d2;
	p3 = d3;
	for (i=0;i<ex;i++)
	{
		printf("%c",c1);
		p1--;
		if (p1 == 0) printcom(com1,c1,cc1);
		printf("%c",c2);
		p2--;
		if (p2 == 0) printcom(com2,c2,cc2);
		printf("%c",c3);
		p3--;
		if (p3 == 0) printcom(com3,c3,cc3);
		checker[c1]++;
		checker[c2]++;
		checker[c3]++;
	}
	for (i=0;i<d2-ex;i++)
	{
		printf("%c",c1);
		p1--;
		if (p1 == 0) printcom(com1,c1,cc1);
		printf("%c",c2);
		p2--;
		if (p2 == 0) printcom(com2,c2,cc2);
		checker[c1]++;
		checker[c2]++;
	}
	for (i=0;i<d3-ex;i++)
	{
		printf("%c",c1);
		p1--;
		if (p1 == 0) printcom(com1,c1,cc1);
		printf("%c",c3);
		p3--;
		if (p3 == 0) printcom(com3,c3,cc3);
		checker[c1]++;
		checker[c3]++;
	}
}

int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	cin>>t;
	int i,j,k;
	for (i=0;i<t;i++)
	{
		memset(checker,0,sizeof(checker));
		int r,o,y,g,b,v;
		cin>>n>>r>>o>>y>>g>>b>>v;
		if ((o>b) || (g>r) || (v>y))
		{
			printf("Case #%d: IMPOSSIBLE\n",i+1);
			continue;
		}
		if ((o==b) && (b>0))
		{
			if (n>o+b) printf("Case #%d: IMPOSSIBLE\n",i+1);
			else
			{
				printf("Case #%d: ",i+1);
				for (j=0;j<o;j++)
				{
					printf("OB");
				}
				printf("\n");
			}
			continue;
		}
		if ((g==r) && (r>0))
		{
			if (n>g+r) printf("Case #%d: IMPOSSIBLE\n",i+1);
			else
			{
				printf("Case #%d: ",i+1);
				for (j=0;j<g;j++)
				{
					printf("GR");
				}
				printf("\n");
			}
			continue;
		}
		if ((v==y) && (y>0))
		{
			if (n>v+y) printf("Case #%d: IMPOSSIBLE\n",i+1);
			else
			{
				printf("Case #%d: ",i+1);
				for (j=0;j<v;j++)
				{
					printf("VY");
				}
				printf("\n");
			}
			continue;
		}
		int rb = b-o;
		int ry = y-v;
		int rr = r-g;
		if ((rb>ry+rr)||(ry>rb+rr)||(rr>rb+ry))
		{
			printf("Case #%d: IMPOSSIBLE\n",i+1);
			continue;
		}
		printf("Case #%d: ",i+1);
		if ((rb>=rr) && (rb>=ry))
		{
			printans(rb,rr,ry,o,g,v,'B','R','Y','O','G','V');
		}
		else
		if ((rr>=rb) && (rr>=ry))
		{
			printans(rr,rb,ry,g,o,v,'R','B','Y','G','O','V');
		}
		else
		{
			printans(ry,rr,rb,v,g,o,'Y','R','B','V','G','O');
		}
		printf("\n");
		fprintf(stderr,"%d %d %d %d %d %d\n",checker['R'],checker['O'],checker['Y'],checker['G'],checker['B'],checker['V']);
	}
	return 0;
}
