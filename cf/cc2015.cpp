#include <iostream>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

const int alphabetsize = 26;

struct NODE{
    NODE *son[alphabetsize];
    int endsize;
}root;

int n;

int ans = 0;

void add(NODE node,string str)
{
    int i,j;
    for (i=0;i<str.length();i++)
    {
        if (node.son[str[i]-'a'] == NULL)
        {
            node.son[str[i]-'a'] = new NODE;
            for (j=0;j<alphabetsize;j++)
            {
                node.son[str[i]-'a']->son[j] = NULL;
            }
            node.son[str[i]-'a']->endsize = 0;
        }
        node = *node.son[str[i]-'a'];
    }
    node.endsize ++;
}

void search(NODE node,string str)
{
    int i;
    for (i=0;i<str.length();i++)
    {
        if (node.son[str[i]-'a'] == NULL) return;
        node = *node.son[str[i]-'a'];
    }
    node.endsize --;
    ans ++;
}

int main() {
    cin>>n;
    int i,j,k,x;
    x = 0;
    for (i=0;i<alphabetsize;i++)
    {
        root.son[i] = NULL;
    }
    root.endsize = 0;
    for (i=0;i<n;i++)
    {
        string str;
        cin>>str;
        string str2 = str;
        reverse(str2.begin(),str2.end());
        if (str2 == str) {x++; continue;}
        add(root,str);
        search(root,str2);
        cout<<ans<<endl;
    }
    if (ans*2+x != n) cout<<-1<<endl;
    else cout<<ans<<endl;
    return 0;
}
