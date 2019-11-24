#include "bits/stdc++.h"

using namespace std;

int main() {
    int t;
    cin>>t;
    while (t) {
        t--;
        int k,n;
        int i,j;
        cin>>n>>k;
        string str;
        cin>>str;
        vector<pair<int,int>> ans(0);
        for (i=0;i<k-1;i++) {
            if (str[i*2] == ')') {
                ans.emplace_back(i*2+1,i*2+1);
            }
            if (str[i*2+1] == '(') {
                ans.emplace_back(i*2+2,i*2+2);
            }
        }
        int remCount = (n-(k-1)*2)/2;
        for (int i=0;i<remCount;i++) {
            if (str[(k-1)*2+i] == ')') {
                ans.emplace_back((k-1)*2+i+1,(k-1)*2+i+1);
            }
            if (str[(k-1)*2+i+remCount] == '(') {
                ans.emplace_back((k-1)*2+remCount+i+1,(k-1)*2+remCount+i+1);
            }
        }
        cout<<ans.size()<<endl;
        for (auto it=ans.begin();it<ans.end();it++) {
            cout<<it->first<<' '<<it->second<<endl;
        }
    }
    return 0;
}