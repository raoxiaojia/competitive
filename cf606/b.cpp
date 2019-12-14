#include <bits/stdc++.h>

using namespace std;

vector<int> f;

int find(int x) {
    if (f[x] == x) {
        return x;
    }
    int fx = find(f[x]);
    f[x] = fx;
    return fx;
}

void uni(int a, int b) {
    int fa = find(a);
    int fb = find(b);
    if (rand()%2) f[fa] = fb;
    else f[fb] = fa;
}

int ca[200005];
int cb[200005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while (t) {
        t--;
        int n,m,a,b;
        cin>>n>>m>>a>>b;
        vector<vector<int>> g;
        f.clear();
        for (int i=0;i<n+1;i++) {
            vector<int> tmp;
            g.push_back(tmp);
            f.push_back(i);
        }
        for (int i=0;i<m;i++) {
            int j,k;
            cin>>j>>k;
            g[j].push_back(k);
            g[k].push_back(j);
            if ((j != a) && (j != b) && (k != a) && (k != b)) {
                uni(j,k);
            }
        }
        for (int i=0;i<g[a].size();i++) {
            ca[find(g[a][i])] = t+10;
        }
        for (int i=0;i<g[b].size();i++) {
            cb[find(g[b][i])] = t+10;
        }
        long long oa,ob;
        oa = 0;
        ob = 0;
        for (int i=1;i<=n;i++) {
            if ((i == a) || (i == b)) continue;
            int fa = find(i);
            if ((ca[fa] == t+10) && (cb[fa] != t+10)) oa ++;
            if ((ca[fa] != t+10) && (cb[fa] == t+10)) ob ++;
        }
        cout<<oa*ob<<endl;
    }
    return 0;
}