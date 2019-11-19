#include <iostream>
#include <cstdlib>

using namespace std;

void qsort(int a[], int l, int r) {
    int i = l;
    int j = r;
    int mid = (i+j)/2;
    int x = a[mid];
    while (i<j) {
        while (i<j && a[i] < x) i++;
        while (i<j && a[j] > x) j--;
        if (i<=j) {
            int tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
            i++;
            j--;
        }
    }
    if (l<j) qsort(a,l,j);
    if (i<r) qsort(a,i,r);
}

int main(){
    int a[5] = {3,2,1,4,5};
    qsort(a,0,4);
    for (int i=0;i<5;i++) cout<<a[i]<<endl;
    return 0;
}
