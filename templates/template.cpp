#include <bits/stdc++.h>

using namespace std;

// safe hash for anti-hacking.
// usage: unordered_map<T1, T2, custom_hash> hashmap;
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

// segment tree related
template<class T> class SegTree {
public:
    vector<T> tree;
    int l;
    int r;
    SegTree(int left, int right) {
        l = left;
        tree.reserve((r-l)*2+10);
        fill(tree.begin(),tree.end(),0);
    }
    void update(int left, int right, T value, int node, int cl, int cr) {
        if ((cl == left) && (cr == right)) {
            tree[node] += value;
            return;
        }
        mid = (cl+cr)/2;
        if (right <= mid) {
            update(left,right,value,node*2);
        } else if (left > mid) {
            update(left,right,value,node*2+1);
        } else {
            update(left,mid,value,node*2);
            update(mid+1,right,value,node*2+1);
        }
    }
    void update(int left, int right, T value) {
        update(left,right,value,0,l,r);
    }
    T query(int left, int right, int node, int cl, int cr) {
        T ret = tree[node]*(right-left+1);
        mid = (cl+cr)/2;
        if (right <= mid) {
            update(left,right,value,node*2);
        } else if (left > mid) {
            update(left,right,value,node*2+1);
        } else {
            update(left,mid,value,node*2);
            update(mid+1,right,value,node*2+1);
        }
    }
    T query(int left, int right) {
        return query(left,right,0,l,r);
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}