#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

void qsort(int a[], int l, int r){
    if (r<=l) return;
    int h = l;
    int t = r;
    int mid = (l+r)/2;
    int x = a[mid];
    while (h<t) {
        while (h<t && a[h] < x) {
            h++;
        }
        while (h<t && a[t] > x) {
            t--;
        }
        if (h<=t) {
            int tmp = a[h];
            a[h] = a[t];
            a[t] = tmp;
            h++;
            t--;
        }
    }
    if (t>l) qsort(a,l,t);
    if (h<r) qsort(a,h,r);
}

vector<int> merge(vector<int> a, vector<int> b) {
    vector<int> c(0);
    int i=0;
    int j=0;
    while (i<a.size() && j<b.size()){
        if (a[i]<b[j]) {
            c.push_back(a[i]);
            i++;
        } else {
            c.push_back(b[j]);
            j++;
        }
    }
    while (i<a.size()) {
        c.push_back(a[i]);
        i++;
    }
    while (j<b.size()) {
        c.push_back(b[j]);
        j++;
    }
    return c;
}

struct HTCell {
    vector< pair<int,int> > kvpair;
};

vector<HTCell> ht(3);

int main()
{
    int a[9] = {1,3,3,4,3,4,7,-1,3};
    for (int i=0;i<9;i++)
    {
        int hvalue = (a[i]+102)%3;
        ht[hvalue].kvpair.emplace_back(hvalue,a[i]);
    }
    for (int i=0;i<3;i++) {
        for (int j=0;j<ht[i].kvpair.size();j++){
            cout<<ht[i].kvpair[j].first<<' '<<ht[i].kvpair[j].second<<endl;
        }
    }
    qsort(a,0,8);
    for (int i=0;i<9;i++) cout<<a[i]<<endl;
    vector<int> ax(0);
    for (int i=0;i<9;i++) ax.push_back(a[i]);
    sort(ax.begin(),ax.end());
    for (int i=0;i<9;i++) cout<<ax[i]<<endl;
}
