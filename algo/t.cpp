#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

struct TrieNode {
    TrieNode* c[255];
    int count;
};

void addT(TrieNode *t, string str) {
    TrieNode *tmp;
    tmp = t;
    for (int i=0;i<str.length();i++) {
        char ch = str[i];
        cout<<ch<<endl;
        if (tmp->c[ch]) {
            tmp = tmp->c[ch];
            continue;
        }
        tmp->c[ch] = new TrieNode;
        tmp = tmp->c[ch];
        for (int j=0;j<255;j++) {
            tmp->c[j] = NULL;
        }
        tmp->count = 0;
    }
    tmp->count ++;
}

void printAll(TrieNode *t, string curstr) {
    if (t == NULL) return;
    if (t->count > 0) {
        cout<<curstr<<' '<<t->count<<endl;
    }
    for (int i=0;i<255;i++) {
        if (t->c[i]) {
            printAll(t->c[i], curstr + (char)i);
        }
    }
}

int main()
{
    vector<string> strs = {
        "asdfasd",
        "aaaa",
        "abcd",
        "abd",
        "bda",
        "bdaa"
    };
    TrieNode *t = new TrieNode;
    t->count = 0;
    for (int i=0;i<255;i++) {
        t->c[i] = NULL;
    }
    for (int i=0;i<strs.size();i++) {
        string str = strs[i];
        addT(t,str);
    }
    printAll(t,"");
    return 0;
}
