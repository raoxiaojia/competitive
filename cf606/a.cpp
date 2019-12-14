#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while (t) {
        t--;
        string str;
        cin>>str;
        vector<int> ans;
        for (int i=0;i+4<str.length();i++) {
            if ((str[i] == 't') && (str[i+1] == 'w') && (str[i+2] == 'o') && (str[i+3] == 'n') && (str[i+4] == 'e')) {
                str[i+2] = 'z';
                ans.push_back(i+3);
            }
        }
        for (int i=0;i+2<str.length();i++) {
            if ((str[i] == 't') && (str[i+1] == 'w') && (str[i+2] == 'o')) {
                ans.push_back(i+2);
            }
            if ((str[i] == 'o') && (str[i+1] == 'n') && (str[i+2] == 'e')) {
                ans.push_back(i+2);
            }
        }
        cout<<ans.size()<<endl;
        for (int i=0;i<ans.size();i++) {
            cout<<ans[i]<<' ';
        }
        cout<<endl;
    }
    return 0;
}