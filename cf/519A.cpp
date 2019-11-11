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

int tr(char ch)
{
	switch(ch)
	{
		case 'Q':case 'q': return 9; break;
		case 'R':case 'r': return 5; break;
		case 'B':case 'b': return 3; break;
		case 'N':case 'n': return 3; break;
		case 'P':case 'p': return 1; break;
	}
	return 0;
}

int main()
{
	char ch;
	int ans = 0;
	int count = 0;
	while (cin>>ch)
	{
		int x;
		if (isupper(ch)) x = 1;
		else x = -1;
		ans += x*tr(ch);
		if (ch >= ' ') count ++;
		if (count >= 64) break;
	}
	if (ans>0) printf("White\n");
	else if (ans<0) printf("Black\n");
	else printf("Draw\n");
	return 0;
}
