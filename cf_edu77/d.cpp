#include <bits/stdc++.h>

using namespace std;

int m,n,k,t;

vector<int> agi;

struct Trap {
    int l,r,key;
    bool operator < (const Trap& str) const
    {
        return (key < str.key);
    }
};

vector<Trap> traps;

int jump[230000];

bool ok(int b) {
    memset(jump,0,sizeof(jump));
    for (int i=0;i<k;i++) {
        if (traps[i].key > b) {
            if (jump[traps[i].l-1] < traps[i].r) {
                jump[traps[i].l-1] = traps[i].r;
            }
        }
    }
    int i=0;
    int time = 0;
    int jumpUntil = 0;
    while (time<=t && i<=n) {
        //cout<<b<<' '<<i<<' '<<time<<' '<<jumpUntil<<endl;
        if (jump[i] > jumpUntil) {
            jumpUntil = jump[i];
        }
        if (i < jumpUntil) {
            i++;
            time+=3;
        } else {
            i++;
            time++;
        }
    }
    if (time > t) return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>m>>n>>k>>t;
    int low = 333333;
    int high = -1;
    for (int i=0;i<m;i++) {
        int j;
        cin>>j;
        agi.push_back(j);
        if (j>high) high = j;
        if (j<low) low = j;
    }
    for (int i=0;i<k;i++) {
        int l,r,key;
        cin>>l>>r>>key;
        Trap tmp;
        tmp.l = l;
        tmp.r = r;
        tmp.key = key;
        traps.push_back(tmp);
    }
    if (t > 3*n+1) {
        cout<<m<<endl;
        return 0;
    }
    high ++;
    int reallow = low;
    int realhigh = high;
    sort(agi.begin(),agi.end());
    sort(traps.begin(),traps.end());
    while (low<high) {
        int mid = (low+high)/2;
        if (ok(mid)) {
            high = mid;
        } else {
            low = mid+1;
        }
    }
    int ans = high;
    if (ok(high-1)) high--;
    int realans = 0;
    for (int i=0;i<m;i++) {
        if (agi[i] >= ans) {
            realans ++;
        }
    }
    cout<<realans<<endl;
    return 0;
}