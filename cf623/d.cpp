#include "bits/stdc++.h"

using namespace std;

bool cmp(const pair<int,int>& lhs, const pair<int,int>& rhs) {
    return lhs.second < rhs.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,k;
    int g[100][100];
    vector<pair<int,int>> turnCost[100][100];
    cin>>n>>k;
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            cin>>g[i][j];
        }
    }
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            for (int k=0;k<n;k++) {
                if (k == i || k == j) continue;
                turnCost[i][j].push_back(make_pair(k,g[i][k]+g[k][j]));
            }
            sort(turnCost[i][j].begin(),turnCost[i][j].end(),cmp);
        }
    }
    int ans = 2147483647;
    if (k == 2) {
        cout<<turnCost[0][0][0].second<<endl;
        return 0;
    }
    for (int a=0;a<n;a++) {
        if (k == 4) {
            int tmp = 0;
            auto it = turnCost[0][a].begin();
            while (it != turnCost[0][a].end() && (it->first == a || it->first == 0)) it++;
            if (it == turnCost[0][a].end()) continue;
            tmp += it->second;
            it = turnCost[a][0].begin();
            while (it != turnCost[a][0].end() && (it->first == a || it->first == 0)) it++;
            if (it == turnCost[a][0].end()) continue;
            tmp += it->second;
            ans = min(ans,tmp);
            continue;
        }
        for (int b=0;b<n;b++) {
            if (k == 6) {
                int tmp = 0;
                auto it = turnCost[0][a].begin();
                while (it != turnCost[0][a].end() && (it->first == a || it->first == 0 || it->first == b)) it++;
                if (it == turnCost[0][a].end()) continue;
                tmp += it->second;
                it = turnCost[a][b].begin();
                while (it != turnCost[a][b].end() && (it->first == a || it->first == 0 || it->first == b)) it++;
                if (it == turnCost[a][b].end()) continue;
                tmp += it->second;
                it = turnCost[b][0].begin();
                while (it != turnCost[b][0].end() && (it->first == a || it->first == 0 || it->first == b)) it++;
                if (it == turnCost[b][0].end()) continue;
                tmp += it->second;
                ans = min(ans,tmp);
                continue;
            }
            for (int c=0;c<n;c++) {
                if (k == 8) {
                    int tmp = 0;
                    auto it = turnCost[0][a].begin();
                    while (it != turnCost[0][a].end() && (it->first == a || it->first == 0 || it->first == b || it->first == c)) it++;
                    if (it == turnCost[0][a].end()) continue;
                    tmp += it->second;
                    it = turnCost[a][b].begin();
                    while (it != turnCost[a][b].end() && (it->first == a || it->first == 0 || it->first == b || it->first == c)) it++;
                    if (it == turnCost[a][b].end()) continue;
                    tmp += it->second;
                    it = turnCost[b][c].begin();
                    while (it != turnCost[b][c].end() && (it->first == a || it->first == 0 || it->first == b || it->first == c)) it++;
                    if (it == turnCost[b][c].end()) continue;
                    tmp += it->second;
                    it = turnCost[c][0].begin();
                    while (it != turnCost[c][0].end() && (it->first == a || it->first == 0 || it->first == b || it->first == c)) it++;
                    if (it == turnCost[c][0].end()) continue;
                    tmp += it->second;
                    ans = min(ans,tmp);
                    continue;
                }
                for (int d=0;d<n;d++) {
                    int tmp = 0;
                    auto it = turnCost[0][a].begin();
                    while (it != turnCost[0][a].end() && (it->first == a || it->first == 0 || it->first == b || it->first == c || it->first == d)) it++;
                    if (it == turnCost[0][a].end()) continue;
                    tmp += it->second;
                    it = turnCost[a][b].begin();
                    while (it != turnCost[a][b].end() && (it->first == a || it->first == 0 || it->first == b || it->first == c || it->first == d)) it++;
                    if (it == turnCost[a][b].end()) continue;
                    tmp += it->second;
                    it = turnCost[b][c].begin();
                    while (it != turnCost[b][c].end() && (it->first == a || it->first == 0 || it->first == b || it->first == c || it->first == d)) it++;
                    if (it == turnCost[b][c].end()) continue;
                    tmp += it->second;
                    it = turnCost[c][d].begin();
                    while (it != turnCost[c][d].end() && (it->first == a || it->first == 0 || it->first == b || it->first == c || it->first == d)) it++;
                    if (it == turnCost[c][d].end()) continue;
                    tmp += it->second;
                    it = turnCost[d][0].begin();
                    while (it != turnCost[d][0].end() && (it->first == a || it->first == 0 || it->first == b || it->first == c || it->first == d)) it++;
                    if (it == turnCost[d][0].end()) continue;
                    tmp += it->second;
                    ans = min(ans,tmp);
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}