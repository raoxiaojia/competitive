#include "bits/stdc++.h"

using namespace std;

int teams[200000];

int loss;

int dac(int l, int r) {
    if (r-l > 4) {
        int mid = (l+r)/2;
        int lx = dac(l,mid);
        int rx = dac(mid+1,r);
        if (lx > rx) {
            int t = lx;
            lx = rx;
            rx = t;
        }
        if (lx == 2) {
            return 2;
        }
        if (lx == 1) {
            if (rx == 2) {
                loss ++;
                return 2;
            }
            loss += 3;
            return 2;
        }
        if (rx == 2) {
            loss += 3;
            return 1;
        }
        if (rx == 1) {
            return 1;
        }
        if (rx == 0) {
            loss += 6;
            return 0;
        }
    }
    int cnt = 0;
    for (int i=l;i<=r;i++) {
        cnt += teams[i];
    }
    if (teams[i] == 0) return 0;
    if (teams[i] == 1) return 1;
    return 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    for (int i=0;i<k;i++) {
        int x;
        cin>>x;
        teams[x] = 1;
    }
    if (k == 0) {
        cout<<0<<endl;
        return 0;
    }
    dac(1,(1<<n));
    return 0;
}