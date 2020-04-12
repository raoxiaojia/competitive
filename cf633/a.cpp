#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while (t--) {
        int n;
        cin>>n;
        long long prevmax = -2147483647;
        long long maxdiff = 0;
        for (int i=0;i<n;i++) {
            long long x;
            cin>>x;
            if (x>prevmax) {
                prevmax = x;
            } 
            else if (x+maxdiff < prevmax) {
                maxdiff = prevmax-x;
            }
        }
        int ans = 0;
        while (maxdiff) {
            ans ++;
            maxdiff >>= 1;
        }
        cout<<ans<<endl;
    }
    return 0;
}