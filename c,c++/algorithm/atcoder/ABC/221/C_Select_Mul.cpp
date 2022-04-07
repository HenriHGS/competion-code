#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <numeric>
#include <algorithm>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(0);
    ll ans = 0;
    string d; cin>>d;
    int p[10];
    int tot = d.size();
    iota(p,p+tot,0);
    do{
        string t = "";
        fori(i,0,tot) t += d[p[i]];
        fori(i,0,tot-1){
            string ta, tb;
            ta = t.substr(0,i+1);
            tb = t.substr(i+1);
            int a = stoi(ta), b = stoi(tb);
            ta = to_string(a), tb = to_string(b);
            if(ta.size() + tb.size() != tot || !a || !b) continue;
           // cout<<a<<' '<<b<<endl;
            ans = max(ans,1ll*a*b);
        }
    }while(next_permutation(p,p+tot));
    cout<<ans<<endl;
    return 0;
}