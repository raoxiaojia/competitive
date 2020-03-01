#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,k;
    cin>>n>>m;
    vector<vector<int>> g(n+1);
    vector<vector<int>> gf(n+1);
    for (int i=0;i<m;i++) {
        int u,v;
        cin>>u>>v;
        g[v].push_back(u);
        gf[u].push_back(v);
    }
    cin>>k;
    vector<int> path;
    for (int i=0;i<k;i++) {
        int x;
        cin>>x;
        path.push_back(x);
    }
    deque<int> q;
    vector<int> dist(n+1);
    q.push_back(path.back());
    dist[path.back()] = 1;
    while (q.size()) {
        int x = q.front();
        for (auto& v: g[x]) {
            if (!dist[v]) {
                dist[v] = dist[x] + 1;
                q.push_back(v);
            }
        }
        q.pop_front();
    }
    int ansmin = 0;
    int ansmax = 0;
    for (int i=1;i<k;i++) {
        if (dist[path[i]] != dist[path[i-1]]-1) {
            ansmin ++;
            ansmax ++;
            continue;
        }
        for (auto& v:gf[path[i-1]]) {
            if (v != path[i] && dist[v] == dist[path[i-1]] - 1) {
                ansmax ++;
                break;
            }
        }
    }
    cout<<ansmin<<' '<<ansmax<<endl;
    return 0;
}