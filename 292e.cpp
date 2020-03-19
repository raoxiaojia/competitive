#include "bits/stdc++.h"

using namespace std;

template<class T> class UpdateSegTree {
public:
    vector<T> tree;
    vector<bool> uniform;
    int l;
    int r;
    UpdateSegTree(int left, int right, T defaultVal) {
        l = left;
        r = right;
        tree.clear();
        uniform.clear();
        tree.resize((r-l+1)*4+5,defaultVal);
        uniform.resize((r-l+1)*4+5,true);
    }
    UpdateSegTree(int left, int right, T defaultVal, vector<T> initial) {
        l = left;
        r = right;
        tree.clear();
        uniform.clear();
        tree.resize((r-l+1)*4+5,defaultVal);
        uniform.resize((r-l+1)*4+5,true);
        initialize(initial,1,0,r-l);
    }
    void initialize(const vector<T> &initial,int node, int cl, int cr) {
        if (cl == cr) {
            tree[node] = initial[l];
            uniform[node] = true;
            return ;
        }
        int mid=(cl+cr)/2;
        initialize(initial,node*2,cl,mid);
        initialize(initial,node*2+1,mid+1,cr);
        tree[node] = 0;
        uniform[node] = false;
    }
    void propagate(int node, int cl, int cr) {
        if (cr>cl) {
            tree[node*2] = tree[node];
            uniform[node*2] = true;
            tree[node*2+1] = tree[node];
            uniform[node*2+1] = true;
        }
    }
    void update(int left, int right, T value, int node, int cl, int cr) {
        if ((cl == left) && (cr == right)) {
            tree[node] = value;
            uniform[node] = true;
            return;
        }
        if (uniform[node]) {
            propagate(node,cl,cr);
        }
        uniform[node] = false;
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
        update(left-l,right-l,value,1,0,r-l);
    }
    T query(int x, int node, int cl, int cr) {
        if (uniform[node]) {
            return tree[node];
        }
        int mid = (cl+cr)/2;
        if (x <= mid) {
            return query(x,node*2,cl,mid);
        } else {
            return query(x,node*2+1,mid+1,cr);
        }
    }
    T query(int x) {
        return query(x-l,1,0,r-l);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,m;

    cin>>n>>m;

    vector<int> a(n);
    vector<int> b(n);

    UpdateSegTree<pair<int,int>> stree(1,n,make_pair(-1,-1));

    for (int i=0;i<n;i++) {
        cin>>a[i];
    }
    for (int i=0;i<n;i++) {
        cin>>b[i];
    }

    for (int i=0;i<m;i++) {
        int op;
        cin>>op;
        if (op == 1) {
            int x,y,z;
            cin>>x>>y>>z;
            stree.update(y,y+z-1,make_pair(x,y));
        } else {
            int x;
            cin>>x;
            auto val = stree.query(x);
            if (val.first == -1) {
                cout<<b[x-1]<<endl;
            } else {
                int pos = val.first + (x-val.second);
                cout<<a[pos-1]<<endl;
            }
        }
    }

    return 0;
}