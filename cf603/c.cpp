#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while (t) {
        t--;
        int n;
        cin>>n;
        int top = (int)(sqrt(n));
        vector<int> ans;
        ans.clear();
        for (int i=1;i<=top;i++) {
            ans.push_back((int)(n/i));
        }
        for (int i=n/(top+1);i>=0;i--) {
            ans.push_back(i);
        }
        sort(ans.begin(),ans.end());
        cout<<top+(int)(n/(top+1))+1<<endl;
        for (int i=0;i<ans.size();i++) {
            cout<<ans[i]<<' ';
        }
        cout<<endl;
    }
    return 0;
}