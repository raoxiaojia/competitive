#include "bits/stdc++.h"

using namespace std;

vector<int> cnt;
vector<int> cost;
vector<int> ind;

bool cmp(const int& lhs, const int& rhs) {
    return (cnt[lhs] < cnt[rhs]) || (cnt[lhs] == cnt[rhs] && cost[lhs]>cost[rhs]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for (int i=0;i<n;i++) {
        int x;
        cin>>x;
        cnt.push_back(x);
    }
    for (int i=0;i<n;i++) {
        int x;
        cin>>x;
        cost.push_back(x);
        ind.push_back(i);
    }
    sort(ind.begin(),ind.end(),cmp);
    int curCount = -1;
    int i=0;
    multiset<int> costSet;
    long long ans = 0;
    long long curTotalCost = 0;
    while (i<n) {
       // printf("%d %d %d %d %d %d\n",i,cnt[ind[i]],cost[ind[i]],curTotalCost, curCount,costSet.size());
        if (curCount == -1) {
            curCount = cnt[ind[i]];
            costSet.insert(cost[ind[i]]);
            curTotalCost += cost[ind[i]];
            i++;
            continue;
        }
        if (curCount == cnt[ind[i]]) {
            costSet.insert(cost[ind[i]]);
            curTotalCost += cost[ind[i]];
            i++;
            continue;
        }
        curTotalCost -= *(costSet.rbegin());
        ans += curTotalCost;
        costSet.erase(costSet.find(*(costSet.rbegin())));
        curCount ++;
        if (costSet.empty()) {
            curCount = -1;
            curTotalCost = 0;
            continue;
        }
    }
    while (!costSet.empty()) {
        curTotalCost -= *(costSet.rbegin());
        ans += curTotalCost;
        costSet.erase(costSet.find(*(costSet.rbegin())));
    }
    cout<<ans<<endl;
    return 0;
}