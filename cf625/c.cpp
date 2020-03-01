#include "bits/stdc++.h"

using namespace std;

class Monster{
public:
    long long x,y,z;
    Monster(long long x1,long long y1,long long z1) {
        x = x1;
        y = y1;
        z = z1;
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
        initialize(initial, 1, l, r-l);
    }
    void initialize(const vector<T> &initial,int node, int cl, int cr) {
        if (cl == cr) {
            treeMax[node] = initial[cl];
            treeMin[node] = initial[cl];
            return ;
        }
        int mid=(cl+cr)/2;
        initialize(initial,node*2,cl,mid);
        initialize(initial,node*2+1,mid+1,cr);
        if (treeMax[node*2] > treeMax[node*2+1]) {
            treeMax[node] = treeMax[node*2]+lazy[node*2];
        } else {
            treeMax[node] = treeMax[node*2+1];
        }
        if (treeMin[node*2] < treeMin[node*2+1]) {
            treeMin[node] = treeMin[node*2]+lazy[node*2];
        } else {
            treeMin[node] = treeMin[node*2+1];
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
        } else {
            treeMax[node] = treeMax[node*2+1]+lazy[node*2+1];
        }
        if (treeMin[node*2] + lazy[node*2] < treeMin[node*2+1] + lazy[node*2+1]) {
            treeMin[node] = treeMin[node*2]+lazy[node*2];
        } else {
            treeMin[node] = treeMin[node*2+1]+lazy[node*2+1];
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
            return make_pair(treeMax[node],-1);
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

bool cmp(const Monster lhs, const Monster rhs) {
    return (lhs.x < rhs.x);
}

long long weapon[1000005];
long long armor[1000005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,p;
    vector<Monster> monster;
    cin>>n>>m>>p;
    for (int i=0;i<n;i++) {
        long long x,y;
        cin>>x>>y;
        if (!weapon[x]) {
            weapon[x] = y;
        } else {
            weapon[x] = min(weapon[x],y);
        }
    }
    for (int i=0;i<m;i++) {
        long long x,y;
        cin>>x>>y;
        if (!armor[x]) {
            armor[x] = y;
        } else {
            armor[x] = min(armor[x],y);
        }
    }
    for (int i=0;i<p;i++) {
        long long x,y,z;
        cin>>x>>y>>z;
        monster.emplace_back(x,y,z);
    }
    sort(monster.begin(),monster.end(),cmp);
    int curcost = 2147483647;
    long long minweaponcost = 2147483647;
    for (int i=1000000;i>=0;i--) {
        if (weapon[i]) {
            minweaponcost = min(minweaponcost, weapon[i]);
            if (curcost < weapon[i]) {
                weapon[i] = curcost;
            } else {
                curcost = weapon[i];
            }
        }
    }
    curcost = 2147483647;
    int lastpos = 1000000;
    int lastcost = 2147483647;
    for (int i=1000000;i>=0;i--) {
        if (armor[i]) {
            if (curcost < armor[i]) {
                armor[i] = curcost;
            } else {
                curcost = armor[i];
            }
            lastpos = i;
            lastcost = armor[i];
        } else {
            armor[i] = lastcost;
        }
    }
    for (int i=0;i<=999999;i++) {
        armor[i] = -armor[i+1];
    }
    armor[1000000] = -2147483647;
    vector<long long> varmor(armor,armor + sizeof(armor)/sizeof(armor[0]));
    MaxMinSegTree<long long> stree(0,1000005,varmor);
    long long ans = -29999999999;
    int mpos = 0;
    for (int i=0;i<=1000000;i++) {
        if (weapon[i]) {
            while (monster[mpos].x < i && mpos < p) {
                stree.add(monster[mpos].y,1000000,monster[mpos].z);
                mpos ++;
            }
            auto smax = stree.queryMax(0,1000000);
        //    cout<<smax.first<<' '<<weapon[i]<<' '<<i<<' '<<ans<<endl;
            ans = max(smax.first - weapon[i],ans);
        }
    }
    ans = max(ans,-minweaponcost+armor[0]);
    cout<<ans<<endl;
    return 0;
}