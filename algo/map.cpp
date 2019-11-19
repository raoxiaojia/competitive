#include <map>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    map<int,string> worklist;
    worklist.emplace(5,"PHD");
    worklist.emplace(4,"Google");
    worklist.emplace(3,"others");
    worklist.emplace(6,"onion");
    while(worklist.size()){
        int maxkey = worklist.rbegin()->first;
        cout<<maxkey<<worklist.rbegin()->second<<endl;
        worklist.erase(maxkey);
    }
    return 0;
}
