#include "bits/stdc++.h"

using namespace std;

vector<int> a;
long long len[800000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for (int i=0;i<n;i++) {
        int x;
        cin>>x;
        len[x-i+200000] += x;
    }
    long long ans = 0;
    for (int i=0;i<800000;i++) {
        ans = max(len[i],ans);
    }
    cout<<ans<<endl;
    return 0;
}