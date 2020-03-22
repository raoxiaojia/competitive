#include <bits/stdc++.h>

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
        tree.resize((r-l+1)*4+10,defaultVal);
        lazy.resize((r-l+1)*4+10,defaultVal);
    }
    SumSegTree(int left, int right, T defaultVal, vector<T> initial) {
        l = left;
        r = right;
        tree.clear();
        lazy.clear();
        tree.resize((r-l+1)*4+10,defaultVal);
        lazy.resize((r-l+1)*4+10,defaultVal);
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
    void propagate(int node, int cl, int cr) {
        tree[node] += (cr-cl+1)*lazy[node];
        if (cr>cl) {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
    void add(int left, int right, T value, int node, int cl, int cr) {
        if (lazy[node]) {
            propagate(node,cl,cr);
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
            propagate(node,cl,cr);
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
        treeMax.resize((r-l+1)*4+10,0);
        treeMin.resize((r-l+1)*4+10,0);
        lazy.resize((r-l+1)*4+10,0);
        if (recordPos) {
            maxPos.clear();
            minPos.clear();
            maxPos.resize((r-l+1)*4+10,0);
            minPos.resize((r-l+1)*4+10,0);
        }
    }
    MaxMinSegTree(int left, int right, vector<T> initial, bool recordPos = false) {
        l = left;
        r = right;
        treeMax.clear();
        treeMin.clear();
        withPos = recordPos;
        lazy.clear();
        treeMax.resize((r-l+1)*4+10,0);
        treeMin.resize((r-l+1)*4+10,0);
        lazy.resize((r-l+1)*4+10,0);
        if (recordPos) {
            maxPos.clear();
            minPos.clear();
            maxPos.resize((r-l+1)*4+10,0);
            minPos.resize((r-l+1)*4+10,0);
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
            if (withPos) maxPos[node] = maxPos[node*2];
        } else {
            treeMax[node] = treeMax[node*2+1];
            if (withPos) maxPos[node] = maxPos[node*2+1];
        }
        if (treeMin[node*2] < treeMin[node*2+1]) {
            treeMin[node] = treeMin[node*2]+lazy[node*2];
            if (withPos) minPos[node] = minPos[node*2];
        } else {
            treeMin[node] = treeMin[node*2+1];
            if (withPos) minPos[node] = minPos[node*2+1];
        }
    }

    void propagate(int node, int cl, int cr) {
        treeMax[node] += lazy[node];
        treeMin[node] += lazy[node];
        if (cr>cl) {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }

    void add(int left, int right, T value, int node, int cl, int cr) {
        if (lazy[node]) {
            propagate(node,cl,cr);
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
            if (withPos) maxPos[node] = maxPos[node*2];
        } else {
            treeMax[node] = treeMax[node*2+1]+lazy[node*2+1];
            if (withPos) maxPos[node] = maxPos[node*2+1];
        }
        if (treeMin[node*2] + lazy[node*2] < treeMin[node*2+1] + lazy[node*2+1]) {
            treeMin[node] = treeMin[node*2]+lazy[node*2];
            if (withPos) minPos[node] = minPos[node*2];
        } else {
            treeMin[node] = treeMin[node*2+1]+lazy[node*2+1];
            if (withPos) minPos[node] = minPos[node*2+1];
        }
    }
    void add(int left, int right, T value) {
        add(left-l,right-l,value,1,0,r-l);
    }
    pair<T,int> queryMax(int left, int right, int node, int cl, int cr) {
        if (lazy[node]) {
            propagate(node,cl,cr);
        }
        if ((left == cl) && (right == cr)) {
            if (withPos) return make_pair(treeMax[node],maxPos[node]+l);
            else return make_pair(treeMax[node],0);
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
            propagate(node,cl,cr);
        }
        if ((left == cl) && (right == cr)) {
            if (withPos) return make_pair(treeMin[node],maxPos[node]+l);
            return make_pair(treeMin[node],0);
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

class Dinic {
public:
    vector<unordered_map<int,long long>> cap;
    vector<unordered_map<int,long long>> f;
    vector<unordered_map<int,long long>> res;
    int n;
    int src;
    int dst;
    vector<int> levelGraph;
    vector<int> augmentingPath;
    long long inf = (1<<50);
    Dinic(vector<unordered_map<int,long long>> c, int s, int t) {
        cap = c;
        src = s;
        dst = t;
        inf = inf;
        n = cap.size();
        levelGraph.clear();
        levelGraph.resize(n);
        f.resize(n);
    }

    long long findAugmentingPath(int cur, long long curCap) {
        if (cur == dst) return curCap;
        for (auto& x:res[cur]) {
            if (levelGraph[x.first] == levelGraph[cur] + 1) {
                augmentingPath.push_back(x.first);
                bool ret = findAugmentingPath(x.first,min(curCap,x.second));
                if (ret) return curCap;
                augmentingPath.pop_back();
            }
        }
        return -1;
    }

    vector<unordered_map<int,long long>> getMaxFlow() {
        res = cap;
        while (1) {
            levelGraph.clear();
            levelGraph.assign(n,0);
            levelGraph[src] = 1;
            deque<int> q;
            q.push_back(src);
            while (q.size()) {
                int node = q.front();
                for (auto& x:cap[node]) {
                    if (!levelGraph[x.first] && res[node].find(x.first) != res[node].end() && res[node][x.first] > 0) {
                        levelGraph[x.first] = levelGraph[node] + 1;
                        q.push_back(node);
                    }
                }
                q.pop_front();
            }
            if (!levelGraph[dst]) break;
            while (1) {
                augmentingPath.clear();
                augmentingPath.push_back(src);
                int augCap = findAugmentingPath(src,inf);
                if (augCap < 0) {
                    break;
                }
                for (int i=0;i<augmentingPath.size()-1;i++) {
                    res[augmentingPath[i]][augmentingPath[i+1]] = res[augmentingPath[i]][augmentingPath[i+1]] - augCap;
                    res[augmentingPath[i+1]][augmentingPath[i]] = res[augmentingPath[i+1]][augmentingPath[i]] + augCap;
                    f[augmentingPath[i]][augmentingPath[i+1]] = f[augmentingPath[i]][augmentingPath[i+1]] + augCap;
                    f[augmentingPath[i+1]][augmentingPath[i]] = f[augmentingPath[i+1]][augmentingPath[i]] - augCap;
                }
            }
        }
        return f;
    }

};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}