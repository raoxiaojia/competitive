#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b) {
    return a%b == 0? b : gcd(b,a%b);
}

int main() {
    int n;
    cin>>n;
    while (n) {
        n--;
        long long a,b,k;
        cin>>a>>b>>k;
        if (a == b) {
            cout<<"OBEY"<<endl;
            continue;
        }
        long long g = gcd(a,b);
        a /= g;
        b /= g;
        if (a>b) {
            long long t=a;
            a = b;
            b = t;
        }
        if ((k-1)*a <= b-2) {
            cout<<"REBEL"<<endl;
        } else {
            cout<<"OBEY"<<endl;
        }
    }
    return 0;
}