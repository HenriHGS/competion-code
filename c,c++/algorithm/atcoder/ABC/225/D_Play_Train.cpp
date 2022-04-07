#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
const int N = 1e5+10;
int L[N], R[N];
int main(){
    ios::sync_with_stdio(0);
    int n, m; cin>>n>>m;
    For(i,1,n) L[i] = R[i] = i;
    while(m--){
        int op; cin>>op;
        if(op == 1){
            int x, y; cin>>x>>y;
            R[x] = y, L[y] = x;
        }else if(op == 2){
            int x, y; cin>>x>>y;
            R[x] = x, L[y] = y;
        }else {
            int x; cin>>x;
            vector<int>fro, bac;
            int a = x;
            while(L[a] != a){
                a = L[a];
                fro.push_back(a);
            }
            reverse(fro.begin(),fro.end());
            int b = x;
            fro.pb(x);
            while(R[b] != b){
                b = R[b];
                bac.pb(b);
            }
          //  cout<<"xxxx:"<<endl;
           cout<<(fro.size() + bac.size())<<' ';
            for(auto x: fro) cout<<x<<' ';
            for(auto x: bac) cout<<x<<' ';
            cout<<endl;
        }
    }
    return 0;
}