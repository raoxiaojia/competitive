#include "bits/stdc++.h"

using namespace std;

vector<long long> csize;

const int transmute[4] = {0,2,3,1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    long long n;

    long long x = 1;
    long long acc = 0;
    for (int i=0;i<29;i++) {
        csize.push_back(acc+x);
        acc += x;
        x *= 4;
    }
   // cout<<csize.back()<<endl;
    cin>>t;
    while (t--) {
        cin>>n;
        if (n<=3) {
            cout<<n<<endl;
            continue;
        }
        long long pnum = (n-1)/3+1;
        long long pindex = n-(pnum-1)*3;
        long long cluster = 0;
        for (int i=0;i<csize.size();i++) {
            if (csize[i] >= pnum) {
                cluster = i;
                break;
            }
        }
        long long cindex = (pnum - csize[cluster-1]-1);
        long long a = (((long long) 1)<<(2*cluster)) + cindex;

        vector<long long> t4;
        while (cindex) {
            t4.push_back(cindex%4);
            cindex /= 4;
        }
        long long b = (((long long)1)<<(2*cluster+1));
        long long mult = 1;
        for (int i=0;i<t4.size();i++) {
            t4[i] = transmute[t4[i]];
            b += t4[i] * mult;
            mult *= 4;
        }
        long long c = a^b;
        if (pindex == 1) {
            cout<<a<<endl;
        }
        else if (pindex == 2) {
            cout<<b<<endl;
        }
        else if (pindex == 3) {
            cout<<c<<endl;
        }

    }
    return 0;
}