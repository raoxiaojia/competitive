#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while (t) {
        t--;
        int r,g,b;
        cin>>r>>g>>b;
        for (int i=0;i<3;i++) {
            if (r<g) swap(r,g);
            if (g<b) swap(g,b);
        }
        if (r>g+b) {
            cout<<g+b<<endl;
        } else {
            cout<<(r+g+b)/2<<endl;
        }
    }
    return 0;
}