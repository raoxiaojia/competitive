#include <bits/stdc++.h>

using namespace std;

int n;
int x;

vector<long long> cost;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    int i,j,k;
    for (i=0;i<n;i++) {
        cin>>j;
        cost.push_back(j);
        if (j == -1) {
            x = i + 1;
        }
    }
    if (x == n) {
        cout<<0<<endl;
        return 0;
    }
    if (x >= n/2) {
        cout<<cost.back()<<endl;
        return 0;
    }
    int curbest = n/2;
    long long ans = cost.back();
    cost.pop_back();
    multiset<long long> bCost;
    while (curbest > x) {
        for (i=0;i<curbest;i++) {
            bCost.insert(cost.back());
            cost.pop_back();
        }
        j = *(bCost.begin());
        ans += j;
        auto del = bCost.find(j);
        bCost.erase(del);
        curbest /= 2;
    }
    cout<<ans<<endl;
    return 0;
}