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

int pos[200000];

int min(int x,int y)
{
	return x<y?x:y;
}
int max(int x,int y)
{
	return x>y?x:y;
}

int main()
{
	int n;
	cin>>n;
	int i;
	for (i=0;i<n;i++)
	{
		cin>>pos[i];
	}
	cout<<pos[1]-pos[0]<<' '<<pos[n-1]-pos[0]<<endl;
	for (i=1;i<n-1;i++)
	{
		printf("%d %d\n",min(pos[i]-pos[i-1],pos[i+1]-pos[i]),max(pos[i]-pos[0],pos[n-1]-pos[i]));
	}
	printf("%d %d\n",pos[n-1]-pos[n-2],pos[n-1]-pos[0]);
	return 0;
}
