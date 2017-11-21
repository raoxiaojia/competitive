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

int main()
{
	int n;
	FILE * pFile = fopen('test.in','w');
	fprintf(pFile,"%d\n",100000);
	for (i=0;i<25000;i++)
	{
		fprintf(pFile,"%c\n",'L');
		fprintf(pFile,"%c\n",'R');
		fprintf(pFile,"%c\n",'D');
		fprintf(pFile,"%c\n",'U');
	}
	close(pFile);
	return 0;
}
