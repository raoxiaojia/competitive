#include <bits/stdc++.h>

using namespace std;

int f[30];

int find(int x) {
    if (f[x] == x) return x;
    int fx = find(f[x]);
    f[x] = fx;
    return fx;
}

void uni(int a,int b) {
    int fa = find(a);
    int fb = find(b);
    f[fb] = fa;
}

int used[30];

int appeared[30];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    string str;
    for (int i=0;i<26;i++) {
        f[i] = i;
    }
    for (int i=0;i<n;i++) {
        cin>>str;
        appeared[str[0]-'a'] = 1;
        for (int i=1;i<str.length();i++) {
            uni(str[0]-'a',str[i]-'a');
            appeared[str[i]-'a'] = 1;
        }
    }
    int ans = 0;
    for (int i=0;i<26;i++) {
        if ((i == find(i)) && appeared[i]) {
            used[i] = 1;
            ans ++;
        }
    }
    cout<<ans<<endl;
    return 0;
}