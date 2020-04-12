#include "bits/stdc++.h"

using namespace std;

struct Node {
    int a, b;
    bool c0;
    vector<int> child;
    int parent;
    bool isleaf;
    int depth;
    int leafcount;
};

vector<Node> tree; 
vector<vector<int>> g;

void dfs(int x, int d) {
    tree[x].depth = d;
    if (g[x].size() == 1) {
        tree[x].isleaf = true;
    } else {
        tree[x].isleaf = false;
    }
    int lcount = 0;
    for (int i=0;i<g[x].size();i++) {
        if (g[x][i] == tree[x].parent) continue;
        tree[x].child.push_back(g[x][i]);
        tree[g[x][i]].parent = x;
        dfs(g[x][i], d+1);
        if (tree[g[x][i]].isleaf) {
            lcount ++;
        }
    }
    tree[x].leafcount = lcount;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for (int i=0;i<n;i++)  {
        vector<int> tmp;
        g.push_back(tmp);
        Node tmp2;
        tree.push_back(tmp2);
    }
    for (int i=0;i<n-1;i++) {
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int root = 0;
    for (int i=0;i<n;i++) {
        if (g[i].size() > 1) {
            root = i;
            break;
        }
    }

    tree[root].isleaf = false;
    tree[root].parent = -1;
    dfs(root,0);
    int ansmin, ansmax;
    ansmax = n-1;

    bool oddl = false;
    bool evenl = false;

    for (int i=0;i<n;i++) {
        if (tree[i].isleaf) {
            if (tree[i].depth & 1) {
                oddl = true;
            } else {
                evenl = true;
            }
        }
        if (tree[i].isleaf) continue;
        if (tree[i].leafcount > 1) {
            ansmax -= (tree[i].leafcount-1);
        }
    }
    if (oddl && evenl) {
        ansmin = 3;
    } else {
        ansmin = 1;
    }

    cout<<ansmin<<' '<<ansmax<<endl;

    return 0;
}