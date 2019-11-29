#include <bits/stdc++.h>

using namespace std;

template<class T> class SegTree {
public:
    vector<T> tree;
    vector<T> lazy;
    int l;
    int r;
    SegTree(int left, int right, T defaultVal) {
        l = left;
        r = right;
        tree.clear();
        lazy.clear();
        tree.resize((r-l+1)*2+10,defaultVal);
        lazy.resize((r-l+1)*2+10,defaultVal);

    }
    void add(int left, int right, T value, int node, int cl, int cr) {
        if ((cl == left) && (cr == right)) {
            lazy[node] += value;
            return;
        }
        int mid = (cl+cr)/2;
        if (right <= mid) {
            add(left,right,value,node*2,cl,mid);
        } else if (left > mid) {
            add(left,right,value,node*2+1,mid+1,cr);
        } else {
            add(left,mid,value,node*2,cl,mid);
            add(mid+1,right,value,node*2+1,mid+1,cr);
        }
    }
    void add(int left, int right, T value) {
        add(left-l,right-l,value,0,0,r-l);
    }
    T query(int left, int right, int node, int cl, int cr) {
        if (lazy[node]) {
            tree[node] += lazy[node]*(cr-cl+1);
            if (cr>cl) {
                lazy[node*2] += lazy[node];
                lazy[node*2+1] += lazy[node];
            }
            lazy[node] = 0;
        }
        if ((left == cl) && (right == cr)) {
            return tree[node];
        }
        int mid = (cl+cr)/2;
        if (right <= mid) {
            return query(left,right,node*2,cl,mid);
        } else if (left > mid) {
            return query(left,right,node*2+1,mid+1,cr);
        } else {
            return query(left,mid,node*2,cl,mid) + query(mid+1,right,node*2+1,mid+1,cr);
        }
    }
    T query(int left, int right) {
        return query(left-l,right-l,0,0,r-l);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    SegTree<pair<int,int>> t;
    int n,m;
    cin>>n>>m;
}