#include <iostream>
#include <map>
#include <vector>
using namespace std;
map<pair<int,int>,int> exists;
const int N = 1e4 + 10;
int c[N], ans[N];
int main(){
    int n, I, h, m; cin>>n>>I>>h>>m;
    c[1] = h;
    for(int i = 1; i <= m; i ++ ) {
        int a, b; cin>>a>>b;
        if(a == b) continue;
        if(exists.count(make_pair(a,b))) continue;
        if(a > b) swap(a,b);
        exists[make_pair(a,b)] = 1;
        int len = a - b - 1;
        if(len) c[a + 1] += -1, c[b] -= -1;
    }
    for(int i = 1; i <= n; i ++ ) {
        c[i] += c[i-1];
        cout<<c[i]<<endl;
    }
    return 0;
}