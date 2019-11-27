#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin>>n;
    while (n) {
        n--;
        long long a,b;
        cin>>a>>b;
        long long ans = 0;
        if (b%a == 0) {
            cout<<(long long)(b/a)*(b/a)*a<<endl;
            continue;
        }
        long long low = b/a;
        long long lowCount = a-b%a;
        long long high = b/a+1;
        long long highCount = b%a;
        cout<<low*low*lowCount+high*high*highCount<<endl;
    }
    return 0;
}