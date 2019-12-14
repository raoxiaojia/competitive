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
        initialize(initial,1,0,r-l);
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
    vector<T> maxPos, minPos;
    vector<T> lazy;
    int l;
    int r;
    bool withPos;
    MaxMinSegTree(int left, int right, bool recordPos = false) {
        l = left;
        r = right;
        withPos = recordPos;
        treeMax.clear();
        treeMin.clear();
        lazy.clear();
        treeMax.resize((r-l+1)*2+10,0);
        treeMin.resize((r-l+1)*2+10,0);
        lazy.resize((r-l+1)*2+10,0);
        if (recordPos) {
            maxPos.clear();
            minPos.clear();
            maxPos.resize((r-l+1)*2+10,0);
            minPos.resize((r-l+1)*2+10,0);
        }
    }
    MaxMinSegTree(int left, int right, vector<T> initial, bool recordPos = false) {
        l = left;
        r = right;
        treeMax.clear();
        treeMin.clear();
        withPos = recordPos;
        lazy.clear();
        treeMax.resize((r-l+1)*2+10,0);
        treeMin.resize((r-l+1)*2+10,0);
        lazy.resize((r-l+1)*2+10,0);
        if (recordPos) {
            maxPos.clear();
            minPos.clear();
            maxPos.resize((r-l+1)*2+10,0);
            minPos.resize((r-l+1)*2+10,0);
        }
        initialize(initial, 1, l, r-l);
    }
    void initialize(const vector<T> &initial,int node, int cl, int cr) {
        if (cl == cr) {
            treeMax[node] = initial[cl];
            treeMin[node] = initial[cl];
            if (withPos) {
                maxPos[node] = cl;
                minPos[node] = cl;
            }
            return ;
        }
        int mid=(cl+cr)/2;
        initialize(initial,node*2,cl,mid);
        initialize(initial,node*2+1,mid+1,cr);
        if (treeMax[node*2] > treeMax[node*2+1]) {
            treeMax[node] = treeMax[node*2]+lazy[node*2];
            maxPos[node] = maxPos[node*2];
        } else {
            treeMax[node] = treeMax[node*2+1];
            maxPos[node] = maxPos[node*2+1];
        }
        if (treeMin[node*2] < treeMin[node*2+1]) {
            treeMin[node] = treeMin[node*2]+lazy[node*2];
            minPos[node] = minPos[node*2];
        } else {
            treeMin[node] = treeMin[node*2+1];
            minPos[node] = minPos[node*2+1];
        }
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
        } else if (left > mid) {
            add(left,right,value,node*2+1,mid+1,cr);
        } else {
            add(left,mid,value,node*2,cl,mid);
            add(mid+1,right,value,node*2+1,mid+1,cr);
        }
        if (treeMax[node*2] + lazy[node*2] > treeMax[node*2+1] + lazy[node*2+1]) {
            treeMax[node] = treeMax[node*2]+lazy[node*2];
            maxPos[node] = maxPos[node*2];
        } else {
            treeMax[node] = treeMax[node*2+1]+lazy[node*2+1];
            maxPos[node] = maxPos[node*2+1];
        }
        if (treeMin[node*2] + lazy[node*2] < treeMin[node*2+1] + lazy[node*2+1]) {
            treeMin[node] = treeMin[node*2]+lazy[node*2];
            minPos[node] = minPos[node*2];
        } else {
            treeMin[node] = treeMin[node*2+1]+lazy[node*2+1];
            minPos[node] = minPos[node*2+1];
        }
    }
    void add(int left, int right, T value) {
        add(left-l,right-l,value,1,0,r-l);
    }
    pair<T,int> queryMax(int left, int right, int node, int cl, int cr) {
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
            if (withPos) return make_pair(treeMax[node],maxPos[node]-l);
            else return make_pair(treeMax[node],-1);
        }
        int mid = (cl+cr)/2;
        if (right <= mid) {
            return queryMax(left,right,node*2,cl,mid);
        } else if (left > mid) {
            return queryMax(left,right,node*2+1,mid+1,cr);
        } else {
            auto lMax = queryMax(left,mid,node*2,cl,mid);
            auto rMax = queryMax(mid+1,right,node*2+1,mid+1,cr);
            if (lMax.first > rMax.first) {
                return lMax;
            }
            return rMax;
        }
    }
    pair<T,int> queryMin(int left, int right, int node, int cl, int cr) {
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
            if (withPos) return make_pair(treeMin[node],maxPos[node]-l);
            return make_pair(treeMin[node],-1);
        }
        int mid = (cl+cr)/2;
        if (right <= mid) {
            return queryMin(left,right,node*2,cl,mid);
        } else if (left > mid) {
            return queryMin(left,right,node*2+1,mid+1,cr);
        } else {
            auto lMin = queryMin(left,mid,node*2,cl,mid);
            auto rMin = queryMin(mid+1,right,node*2+1,mid+1,cr);
            if (lMin.first < rMin.first) {
                return lMin;
            }
            return rMin;
        }
    }
    pair<T,int> queryMax(int left, int right) {
        return queryMax(left-l,right-l,1,0,r-l);
    }
    pair<T,int> queryMin(int left, int right) {
        return queryMin(left-l,right-l,1,0,r-l);
    }
};

/*Convert LCA to RMQ.*/
class LCA {
public:
    vector<vector<int>> t;
    vector<int> heights;
    vector<int> f;
    vector<int> nodes;
    MaxMinSegTree<int> *segtree;
    void euler(int node, int h) {
        heights.push_back(h);
        nodes.push_back(node);
        for (auto it=t[node].begin();it<t[node].end();it++) {
            if (!f[*it]) {
                f[*it] = heights.size()-1;
                euler(*it,h+1);
                heights.push_back(h);
                nodes.push_back(node);
            }
        }
    }
    LCA(vector<vector<int>> tree, int root) {
        t = tree;
        heights.clear();
        f.clear();
        f.resize(tree.size());
        euler(root,1);
        segtree = new MaxMinSegTree<int>(0,heights.size(),heights,true);
    }
    int query(int x, int y) {
        return nodes[segtree->queryMin(f[x],f[y]).second];
    }
};

/*max flow*/
class Dinic {
public:
    
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}