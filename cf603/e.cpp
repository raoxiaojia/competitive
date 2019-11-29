#include <bits/stdc++.h>

using namespace std;

template<class T> class SumSegTree {
public:
    vector<T> treeMax,treeMin;
    vector<T> lazy;
    int l;
    int r;
    SumSegTree(int left, int right, T defaultVal) {
        l = left;
        r = right;
        treeMax.clear();
        treeMin.clear();
        lazy.clear();
        treeMax.resize((r-l+1)*4+10,0);
        treeMin.resize((r-l+1)*4+10,0);
        lazy.resize((r-l+1)*4+10,defaultVal);
    }
    void add(int left, int right, T value, int node, int cl, int cr) {
        if (lazy[node]) {
            if (cr>cl) {
                lazy[node*2] += lazy[node];
                lazy[node*2+1] += lazy[node];
            }
            treeMax[node] += lazy[node];
            treeMin[node] += lazy[node];
            lazy[node] = 0;
        }
        if ((cl == left) && (cr == right)) {
            if (cr>cl) {
                lazy[node*2] += value;
                lazy[node*2+1] += value;
            }
            treeMax[node] += value;
            treeMin[node] += value;
            return;
        }
        if (cl == cr) return;
        int mid = (cl+cr)/2;
        if (right <= mid) {
            add(left,right,value,node*2,cl,mid);
            treeMax[node] = max(treeMax[node*2]+lazy[node*2],treeMax[node*2+1]+lazy[node*2+1]);
            treeMin[node] = min(treeMin[node*2]+lazy[node*2],treeMin[node*2+1]+lazy[node*2+1]);
        //    cout<<node<<' '<<treeMax[node]<<' '<<treeMin[node]<<endl;
        } else if (left > mid) {
            add(left,right,value,node*2+1,mid+1,cr);
            treeMax[node] = max(treeMax[node*2]+lazy[node*2],treeMax[node*2+1]+lazy[node*2+1]);
            treeMin[node] = min(treeMin[node*2]+lazy[node*2],treeMin[node*2+1]+lazy[node*2+1]);
          //  cout<<node<<' '<<treeMax[node]<<' '<<treeMin[node]<<endl;
        } else {
            add(left,mid,value,node*2,cl,mid);
            add(mid+1,right,value,node*2+1,mid+1,cr);
            treeMax[node] = max(treeMax[node*2]+lazy[node*2],treeMax[node*2+1]+lazy[node*2+1]);
            treeMin[node] = min(treeMin[node*2]+lazy[node*2],treeMin[node*2+1]+lazy[node*2+1]);
         //   cout<<node<<' '<<treeMax[node]<<' '<<treeMin[node]<<endl;
        }
    }
    void add(int left, int right, T value) {
        add(left-l,right-l,value,1,0,r-l);
    }
    T queryMax(int left, int right, int node, int cl, int cr) {
        if ((left == cl) && (right == cr)) {
            return treeMax[node];
        }
        int mid = (cl+cr)/2;
        if (right <= mid) {
            return queryMax(left,right,node*2,cl,mid);
        } else if (left > mid) {
            return queryMax(left,right,node*2+1,mid+1,cr);
        } else {
            return max(queryMax(left,mid,node*2,cl,mid), queryMax(mid+1,right,node*2+1,mid+1,cr));
        }
    }
    T queryMin(int left, int right, int node, int cl, int cr) {
        if ((left == cl) && (right == cr)) {
            return treeMin[node];
        }
        int mid = (cl+cr)/2;
        if (right <= mid) {
            return queryMin(left,right,node*2,cl,mid);
        } else if (left > mid) {
            return queryMin(left,right,node*2+1,mid+1,cr);
        } else {
            return min(queryMin(left,mid,node*2,cl,mid), queryMin(mid+1,right,node*2+1,mid+1,cr));
        }
    }
    T queryMax(int left, int right) {
        return queryMax(left-l,right-l,1,0,r-l);
    }
    T queryMin(int left, int right) {
        return queryMin(left-l,right-l,1,0,r-l);
    }
};

char actual[1000100];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    string str;
    cin>>str;
    int maxrange = 0;
    int curpos = 0;
    for (int i=0;i<n;i++) {
        if (str[i] == 'R') curpos ++;
        else if (str[i] == 'L') curpos = max(curpos-1,0);
        else if ((str[i] == '(') || (str[i] == ')')) {
            maxrange = max(maxrange,curpos);
        }
    }
    maxrange += 100005;
    SumSegTree<int> t(0,maxrange,0);
    curpos = 0;
    int prevans = 0;
    int total = 0;
    for (int i=0;i<n;i++) {
        if (str[i] == 'R') {
            curpos ++;
            cout<<prevans<<' ';
        }
        else if (str[i] == 'L') {
            curpos = max(curpos-1,0);
            cout<<prevans<<' ';
        }
        else if ((str[i] == '(') || (str[i] == ')')) {
            if (actual[curpos] == str[i]) {
                cout<<prevans<<' ';
                continue;
            }
            if (str[i] == '(') {
                total ++;
                t.add(curpos+1,maxrange,1);
            } else {
                total --;
                t.add(curpos+1,maxrange,-1);
            }
            if (actual[curpos] == '(') {
                total --;
                t.add(curpos+1,maxrange,-1);
            } else if (actual[curpos] == ')') {
                total ++;
                t.add(curpos+1,maxrange,1);
            }
            actual[curpos] = str[i];
            if ((total == 0) && (t.queryMin(0,maxrange) == 0)) {
                prevans = t.queryMax(0,maxrange);
            } else {
                prevans = -1;
            }
            cout<<prevans<<' ';
        } 
        else if ((actual[curpos] == '(') || (actual[curpos] == ')' )) {
            if (actual[curpos] == '(') {
                total --;
                t.add(curpos+1,maxrange,-1);
            } else {
                total ++;
                t.add(curpos+1,maxrange,1);
            }
            actual[curpos] = 'x';
            if ((total == 0) && (t.queryMin(0,maxrange) == 0)) {
                prevans = t.queryMax(0,maxrange);
            } else {
                prevans = -1;
            }
            cout<<prevans<<' ';
        } else {
            actual[curpos] = 'x';
            cout<<prevans<<' ';
        }
    }
    return 0;
}