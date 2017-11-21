#include "bits/stdc++.h"
using namespace std;

int n;

bool curcount[27];

vector<string> ansstring;

bool tmpcount[27];

int main()
{
	cin>>n;
	int i,j,k;
	string str;
	for (i=0;i<n;i++)
	{
		cin>>str;
		if (str.length() >= 27)
		{
			printf("NO\n");
			return 0;
		}
		memset(tmpcount,0,sizeof(tmpcount));
		for (j=0;j<str.length();j++)
		{
			if (tmpcount[str[j]-'a'])
			{
				printf("NO\n");
				return 0;
			}
			tmpcount[str[j]-'a'] = true;
		}
		if (ansstring.size() == 0)
		{
			ansstring.push_back(str);
			for (j=0;j<str.length();j++)
			{
				curcount[str[j]-'a'] = true;
			}
			continue;
		}
		bool foundrep = false;
		for (j=0;j<26;j++)
		{
			if (tmpcount[j] && curcount[j])
			{
				foundrep = true;
				break;
			}
		}
		if (!foundrep)
		{
			ansstring.push_back(str);
			for (j=0;j<str.length();j++)
			{
				curcount[str[j]-'a'] = true;
			}
			continue;
		}
		bool foundsub = false;
		for (j=0;j<ansstring.size();j++)
		{
			if (ansstring[j].find(str) != string::npos)
			{
				foundsub = true;
				break;
			}
		}
		if (foundsub)
		{
			continue;
		}
		string tmpstr = str;
		for (j=0;j<ansstring.size();j++)
		{
			bool found = false;
			for (k=0;k<ansstring[j].length();k++)
			{
				if (ansstring[j][k] == str[0])
				{
					found = true;
					break;
				}
			}
			if (!found) continue;
			int l = 0;
			bool success = false;
			while (ansstring[j][k+l] == str[l])
			{
				if (k+l == ansstring[j].length()-1)
				{
					success = true;
					break;
				}
				l++;
			}
			if (!success)
			{
				printf("NO\n");
				return 0;
			}
			tmpstr = "";
			for (l=0;l<k;l++)
			{
				tmpstr += ansstring[j][l];
			}
			tmpstr += str;
			ansstring.erase(ansstring.begin()+j);
			str = tmpstr;
			break;
		}

		for (j=0;j<ansstring.size();j++)
		{
			bool found = false;
			for (k=0;k<ansstring[j].length();k++)
			{
				if (ansstring[j][k] == str.back())
				{
					found = true;
					break;
				}
			}
			if (!found) continue;
			int l = 0;
			bool success = false;
			while (ansstring[j][k-l] == str[str.length()-l-1])
			{
				if (k-l == 0)
				{
					success = true;
					break;
				}
				l++;
			}
			if (!success)
			{
				printf("NO\n");
				return 0;
			}
			for (l=k+1;l<ansstring[j].length();l++)
			{
				tmpstr += ansstring[j][l];
			}
			str = tmpstr;
			ansstring.erase(ansstring.begin()+j);
			break;
		}
		ansstring.push_back(str);
		memset(curcount,0,sizeof(curcount));
		for (j=0;j<ansstring.size();j++)
		{
			for (k=0;k<ansstring[j].length();k++)
			{
				if (curcount[ansstring[j][k]-'a'])
				{
					printf("NO\n");
					return 0;
				}
				curcount[ansstring[j][k]-'a'] = true;
			}
		}
	}
	sort(ansstring.begin(),ansstring.end());
	for (i=0;i<ansstring.size();i++)
	{
		cout<<ansstring[i];
	}
	cout<<endl;
	return 0;
}
