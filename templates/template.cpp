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
        initialize(initial,1,l,r);
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
        if (lazy[node]) {
            tree[node] += (cr-cl+1)*lazy[node];
            if (cr>cl) {
                lazy[node*2] += lazy[node];
                lazy[node*2+1] += lazy[node];
            }
            lazy[node] = 0;
        }
        if ((cl == left) && (cr == right)) {
            tree[node] += (cr-cl+1) * value;
            if (cr>cl) {
                lazy[node*2] += value;
                lazy[node*2+1] += value;
            }
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
        add(left-l,right-l,value,1,0,r-l);
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
        return query(left-l,right-l,1,0,r-l);
    }
};

template<class T> class MaxMinSegTree {
public:
    vector<T> treeMax,treeMin;
    vector<T> lazy;
    int l;
    int r;
    MaxMinSegTree(int left, int right) {
        l = left;
        r = right;
        treeMax.clear();
        treeMin.clear();
        lazy.clear();
        treeMax.resize((r-l+1)*2+10,0);
        treeMin.resize((r-l+1)*2+10,0);
        lazy.resize((r-l+1)*2+10,0);
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
        if (lazy[node]) {
            treeMax[node] += lazy[node];
            treeMin[node] += lazy[node];
            if (cr>cl) {
                lazy[node*2] += lazy[node];
                lazy[node*2+1] += lazy[node];
            }
            lazy[node] = 0;
        }
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
        if (lazy[node]) {
            treeMax[node] += lazy[node];
            treeMin[node] += lazy[node];
            if (cr>cl) {
                lazy[node*2] += lazy[node];
                lazy[node*2+1] += lazy[node];
            }
            lazy[node] = 0;
        }
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

/*Convert LCA to RMQ.*/
class LCA {
public:
    vector<vector<int>> t;
    vector<int> heights;
    vector<int> f;
    void euler(int node, int h) {
        heights.push_back(h);
        for (auto it=t[node].begin();it<t[node].end();it++) {
            if (!f[*it]) {
                f[*it] = heights.size()-1;
                euler(*it,h+1);
                heights.push_back(h);
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
    return 0;
}