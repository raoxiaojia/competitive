#include <vector>
#include <iostream>

using namespace std;

typedef vector<int> vi;

vector<vi> g;
vi maxdist;

void dfs(int cur,int curdist) {
    if (maxdist[cur] >= curdist) {
        return;
    }
    maxdist[cur] = curdist;
    for (auto it=g[cur].begin();it<g[cur].end();it++)
    {
        dfs(*it,curdist+1);
    }
}

int main()
{
    int n;
    cin>>n;
    int caseid = 0;
    while (n) {
        caseid ++;
        g.clear();
        g.resize(n+1);
        maxdist.clear();
        maxdist.resize(n+1);
        for (auto it=g.begin();it<g.end();it++) {
            it->clear();
        }
        int s;
        cin>>s;
        int p,q;
        cin>>p>>q;
        while (p && q) {
            g[p].push_back(q);
            cin>>p>>q;
        }
        maxdist[s] = -1;
        dfs(s,0);
        int ans,dst;
        ans = -1;
        for (int i=0;i<maxdist.size();i++) {
            if (maxdist[i] > ans) {
                ans = maxdist[i];
                dst = i;
            }
        }
        cout<<"Case "<<caseid<<": The longest path from "<<s<<" has length "<<ans<<", finishing at "<<dst<<"."<<endl<<endl;
        cin>>n;
    }
    return 0;

}
