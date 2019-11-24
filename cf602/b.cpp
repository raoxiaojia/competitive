#include "bits/stdc++.h"

using namespace std;

int n,m;

struct Query {
    int a,b,id;
    bool operator < (const Query& rhs) const
    {
        return ((a < rhs.a) || ((a==rhs.a) && (b<rhs.b)));
    }
};

struct Num {
    int key;
    int pos;
    bool operator < (const Num& rhs) const
    {
        return ((key > rhs.key) || ((key == rhs.key) && (pos < rhs.pos)));
    }
};

vector<int> oria;
vector<Num> a;
priority_queue<Num> pqa;
vector<Query> q;

struct Node {
    Node* left, *right;
    int l;
    int r;
    int size;
};

void insert(Node* node, int x) {
    int mid = (node->l+node->r)/2;
    node->size ++;
    if (node->l == node->r) return;
    if (x<=mid) {
        if (!node->left) {
            Node *c = new Node();
            c->l = node->l;
            c->r = mid;
            c->size = 0;
            c->left = NULL;
            c->right = NULL;
            node->left = c;
        }
        insert(node->left, x);
    } else {
        if (!node->right) {
            Node *c = new Node();
            c->l = mid+1;
            c->r = node->r;
            c->size = 0;
            c->left = NULL;
            c->right = NULL;
            node->right = c;
        }
        insert(node->right, x);
    }
}

int find(Node* node, int x) {
    if (node->l == node->r) return node->l;
    cout<<node->l<<' '<<node->r<<' '<<node->size<<' '<<x<<' '<<node->left<<' '<<node->left<<endl;
    if (!node->left) return find(node->right,x);
    if (!node->right) return find(node->left,x);
    int lsize = node->left->size;
    if ((lsize >= x)) {
        return find(node->left, x);
    }
    return find(node->right, x-lsize);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin>>n;
    int i,j,k;
    for (i=0;i<n;i++) {
        cin>>j;
        Num tmp;
        tmp.key = j;
        tmp.pos = i;
        a.push_back(tmp);
        oria.push_back(j);
    }
    cin>>m;
    for (i=0;i<m;i++) {
        int a,b;
        cin>>a>>b;
        Query tmp;
        tmp.a = a;
        tmp.b = b;
        tmp.id = i;
        q.push_back(tmp);
    }
    sort(q.begin(),q.end());
    sort(a.begin(),a.end());
    Node *stree = new Node();
    stree->left = NULL;
    stree->right = NULL;
    stree->l = 0;
    stree->r = n+4;
    stree->size = 0;
    int tsize = 0;
    int ans[200005];
    memset(ans,0,sizeof(ans));
    for (i=0;i<m;i++) {
        while (tsize < q[i].a) {
            insert(stree,a[tsize].pos);
            tsize ++;
        }
        ans[q[i].id] = oria[find(stree,q[i].b)];
    }
    for (i=0;i<m;i++) {
        //printf("%d\n",ans[i]);
        cout<<ans[i]<<endl;
    }
}