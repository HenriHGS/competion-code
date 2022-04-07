#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <set>
using namespace std;
const int N = 1<<20;
typedef long long ll;
ll a[N];
void test(){
    set<int> S;
    S.insert(1);
    S.insert(2);
    S.insert(3);
    auto it = S.lower_bound(4);
    if(it == S.end()) cout<<"OK"<<endl;
}
int main(){
    ios::sync_with_stdio(0);
    //test();
    int q; cin>>q;
    set<int> S;
    for(int i = 0; i < N; i ++ )a[i] = -1, S.insert(i);
    while(q--){
        ll type, x;
        cin>>type>>x;
        int h = x % N;
        if(type == 1){
            auto it = S.lower_bound(h);
            if(it == S.end()){
                it = S.begin();
                int pos = *it;
                S.erase(it);
                a[pos] = x;
            }else {
                int pos = *it;
                S.erase(it);
                a[pos] = x;
            }
        }else cout<<a[h]<<endl;
    }
    return 0;
}