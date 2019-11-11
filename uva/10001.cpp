#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
vector<vector<int> > boxes;
vector<int> ans;
vector<int> prec;

int n,m;

bool operator< (const vector<int> lhs, const vector<int> rhs) {
    for (int i=0;i<lhs.size();i++) {
        if (lhs[i] > rhs[i]) return false;
    }
    return true;
}

void printsol(int cur) {
    if (prec[cur]) {
        printsol(prec[cur]);
    }
    cout<<cur<<' ';
}

void dfs(int cur, int curlen, int p){
    if (ans[cur] >= curlen) return;
    ans[cur] = curlen;
    prec[cur] = p;
    for (int i=1;i<=n;i++) {
        if (i==cur) continue;
        if (boxes[cur] < boxes[i]) {
            
            dfs(i,curlen+1,cur);
        }
    }
}

int main() {
    while (cin>>n>>m) {
        vector<int> tmp;
        boxes.clear();
        boxes.push_back(tmp);
        for (int i=0;i<n;i++) {
            vector<int> box;
            for (int j=0;j<m;j++) {
                int tmp;
                cin>>tmp;
                box.push_back(tmp);
            }
            sort(box.begin(),box.end());
            boxes.push_back(box);
        }
        ans.clear();
        prec.clear();
        ans.resize(n+1);
        prec.resize(n+1);
        int best,besti;
        best = 0;
        for (int i=1;i<=n;i++) {
            if (!ans[i]) {
                dfs(i,1,0);
            }
        }
        for (int i=1;i<=n;i++) {
            if (ans[i] > best) {
                best = ans[i];
                besti = i;
            }
        }
        cout<<best<<endl;
        printsol(besti);
        cout<<endl;
    }
    return 0;
}
