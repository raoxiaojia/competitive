#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin>>n;
    while (n) {
        n--;
        int a,b;
        cin>>a>>b;
        if ((a+b)%3 != 0) {
            cout<<"NO"<<endl;
        } else if (a*2<b) {
            cout<<"NO"<<endl;
        } else if (b*2<a) {
            cout<<"NO"<<endl;
        } else cout<<"YES"<<endl;
    }
    return 0;
}