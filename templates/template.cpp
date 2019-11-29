#include <bits/stdc++.h>

using namespace std;

template<class T> class SumSegTree {
public:
    vector<T> tree;
    vector<T> lazy;
    int l;
    int r;
    SumSegTree(int left, int right, T defaultVal) {
        l = left;
        r = right;
        tree.clear();
        lazy.clear();
        tree.resize((r-l+1)*2+10,defaultVal);
        lazy.resize((r-l+1)*2+10,defaultVal);
    }
    SumSegTree(int left, int right, T defaultVal, vector<T> initial) {
        l = left;
        r = right;
        tree.clear();
        lazy.clear();
        tree.resize((r-l+1)*2+10,defaultVal);
        lazy.resize((r-l+1)*2+10,defaultVal);
        initialize(initial,0,l,r);
    }
    void initialize(const vector<T> &initial,int node, int cl, int cr) {
        if (cl == cr) {
            tree[node] = initial[l];
            return ;
        }
        int mid=(cl+cr)/2;
        initialize(initial,node*2,cl,mid);
        initialize(initial,node*2+1,mid+1,cr);
        tree[node] = tree[node*2] + tree[node*2+1];
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

template<class T> class MaxSegTree {
public:
    vector<T> tree;
    vector<T> lazy;
    int l;
    int r;
    T minVal;
    MaxSegTree(int left, int right, T defaultVal) {
        l = left;
        r = right;
        minVal = defaultVal;
        tree.clear();
        lazy.clear();
        tree.resize((r-l+1)*2+10,defaultVal);
        lazy.resize((r-l+1)*2+10,defaultVal);
    }
    MaxSegTree(int left, int right, T defaultVal, vector<T> initial) {
        l = left;
        r = right;
        minVal = defaultVal;
        tree.clear();
        lazy.clear();
        tree.resize((r-l+1)*2+10,defaultVal);
        lazy.resize((r-l+1)*2+10,defaultVal);
        initialize(initial,0,l,r);
    }
    void initialize(const vector<T> &initial,int node, int cl, int cr) {
        if (cl == cr) {
            tree[node] = initial[l];
            return ;
        }
        int mid=(cl+cr)/2;
        initialize(initial,node*2,cl,mid);
        initialize(initial,node*2+1,mid+1,cr);
        tree[node] = max(tree[node*2], tree[node*2+1]);
    }

    void update(int left, int right, T value, int node, int cl, int cr) {
        if ((cl == left) && (cr == right)) {
            lazy[node] = value;
            return;
        }
        int mid = (cl+cr)/2;
        if (right <= mid) {
            update(left,right,value,node*2,cl,mid);
        } else if (left > mid) {
            update(left,right,value,node*2+1,mid+1,cr);
        } else {
            update(left,mid,value,node*2,cl,mid);
            update(mid+1,right,value,node*2+1,mid+1,cr);
        }
    }
    void update(int left, int right, T value) {
        update(left-l,right-l,value,0,0,r-l);
    }
    T query(int left, int right, int node, int cl, int cr) {
        if (lazy[node] != minVal) {
            tree[node] = max(lazy[node],tree[node]);
            if (cr>cl) {
                lazy[node*2] = lazy[node];
                lazy[node*2+1] = lazy[node];
            }
            lazy[node] = minVal;
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
            return max(query(left,mid,node*2,cl,mid), query(mid+1,right,node*2+1,mid+1,cr));
        }
    }
    T query(int left, int right) {
        return query(left-l,right-l,0,0,r-l);
    }
};

/*Convert LCA to RMQ.*/
class LCA {
public:
    vector<vector<int>> t;
    vector<int> heights;
    vector<int> f;
    euler(int node, int h) {
        heights.push(h);
        for (auto it=t[node].begin();it<t[node].end();it++) {
            if (!f[*it]) {
                f[*it] = heights.size()-1;
                euler(*it);
                heights.push(h);
            }
        }
    }
    LCA(vector<vector<int>> tree, int root) {
        t = tree;
        heights.clear();
        f.clear();
        f.resize(tree.size());
        euler(root,1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    SumSegTree<pair<int,int>> t;
}