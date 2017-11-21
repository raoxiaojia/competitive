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

vector<int> x;

int main()
{
	int n,h;
	cin>>n>>h;
	double avgarea = (double)h/2.0/n;
	for (int i=1;i<n;i++)
	{
		double tmp = avgarea*i;
		double ans = sqrt(tmp/avgarea/n)*h;
		printf("%.12lf ",ans);
	}
	printf("\n");
	return 0;
}
