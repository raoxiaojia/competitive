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
        int str[20];
        memset(str,0,sizeof(str));
        int ans = 0;
        for (int i=0;i<n;i++) {
            cin>>str[i];
        }
        for (int i=0;i<n;i++) {
            vector<int> found[10];
            for (int j=0;j<10;j++) {
                found[j].clear();
            }
            for (int j=0;j<n;j++) {
                if (str[i]/10 == str[j]/10) {
                    found[str[j]%10].push_back(j);
                }
            }
            for (int j=0;j<10;j++) {
                while (found[j].size()>1) {
                    for (int k=0;k<10;k++) {
                        if (found[k].size() == 0) {
                            str[found[j].back()] = str[found[j].back()]/10*10+k;
                            found[k].push_back(j);
                            found[j].pop_back();
                            ans ++;
                            break;
                        }
                    }
                }
            }
        }
        cout<<ans<<endl;
        for (int i=0;i<n;i++) {
            if (str[i] == 0) {
                cout<<"0000"<<endl;
                continue;
            }
            int j = str[i];
            while (j<1000) {
                cout<<0;
                j *= 10;
            }
            cout<<str[i]<<endl;
        }

    }
    return 0;
}