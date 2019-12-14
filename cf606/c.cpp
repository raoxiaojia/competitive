#include <bits/stdc++.h>

using namespace std;

unordered_map<int, int> m;

void next(int &i, int &j, int r, int c) {
    if (i+1<r && j+1<c) {
        i++;
        j++;
        return;
    }
    if (i+1<r) {
        i++;
        j=0;
        return;
    }
    i = 0;
    j = (j+c-(r-2))%c;
}

bool ok(int lim) {
    auto it = m.begin();
    int cur = 0;
    while (it != m.end()) {
        if (it->second > lim) {
            cur += lim;
        } else {
            cur += it->second;
        }
        it++;
    }
    if (cur >= lim*lim) return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for (int i=0;i<n;i++) {
        int j;
        cin>>j;
        auto k = m.find(j);
        if (k != m.end()) {
            k->second ++;
        } else {
            m.insert({j,1});
        }
    }
    
    int low = 1;
    int high = (int)sqrt(n)+1;
    while (low<high) {
        int mid = (low+high)/2;
        if (ok(mid)) {
            low = mid+1;
        } else {
            high = mid;
        }
    }

    while (!ok(high)) high--;

    int lb = 0;
    auto it = m.begin();
    int totalCount = 0;
    int overNum = 0;
    while (it != m.end()) {
        if (it->second > high) {
            overNum ++;
        } else {
            totalCount += it->second;
        }
        if ((it->second > lb) && (it->second <= high)) {
            lb = it->second;
        }
        it++;
    }

    if (!lb) {
        lb = high;
    }

    int bestr = lb;
    for (int i=lb+1;i<=high;i++) {
        if (totalCount/i*i+overNum*i > totalCount/bestr*bestr+overNum*bestr) {
            bestr = i;
        }
    }

    int bestc = totalCount/bestr+overNum;

    cout<<totalCount/bestr*bestr+overNum*bestr<<endl;
    cout<<bestr<<' '<<bestc<<endl;
    vector<vector<int>> ans;
    for (int i=0;i<bestr;i++) {
        vector<int> tmp;
        for (int j=0;j<bestc;j++) {
            tmp.push_back(0);
        }
        ans.push_back(tmp);
    }
    it = m.begin();
    int a=0;
    int b=0;
    while (it != m.end()) {
        if (it->second >= bestr) {
            for (int k=0;k<bestr;k++) {
                //cout<<a<<' '<<b<<' '<<it->first<<endl;
                ans[a][b] = it->first;
                if (a+1<bestr) {
                    a++;
                    b = (b+1)%bestc;
                } else {
                    a=0;
                    b = (b+bestc-(bestr-2))%bestc;
                }
                //next(a,b,bestr,bestc);
            }
            it->second = 0;
        }
        it++;
    }
    it = m.begin();
    while (it != m.end()) {
        while (it->second) {
            ans[a][b] = it->first;
            it->second --;
            if (a+1<bestr) {
                a++;
                b = (b+1)%bestc;
            } else {
                a=0;
                b = (b+bestc-(bestr-2))%bestc;
            }
            //next(a,b,bestr,bestc);
        }
        it++;
    }

    for (int i=0;i<bestr;i++) {
        for (int j=0;j<bestc;j++) {
            cout<<ans[i][j]<<' ';
        }
        cout<<endl;
    }


    return 0;
}