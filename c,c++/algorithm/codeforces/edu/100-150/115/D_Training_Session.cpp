#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <map>
#define pb push_back
#define debug(a) cout<<#a<<":"<<a<<endl
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
const int N = 2e5+10;
typedef long long ll;
vector<int> e1[N], e2[N];
map<int,int> ma[N];
void sol(){
    int n; cin>>n;
    For(i,1,n) ma[i].clear(), e1[i].clear(), e2[i].clear();
    vector<int> top(n+1), difc(n+1);
    For(i,1,n){
        int t, d; cin>>t>>d;
        top[t]++, difc[d]++;
        e1[t].pb(d);
        e2[d].pb(t);
        ma[d][t]++;
    }
    //cn3
    ll ans = 1ll*n*(n-1)*(n-2)/3/2;
    //debug(ans);
    For(i,1,n){
        if(top[i] <= 1) continue;
        int oth = n - top[i];
        //cal2
        ll sub = 0;
       // cout<<"topic:"<<i<<endl;
        for(auto d: e1[i]){
          //  cout<<"cur:"<<d<<",siz = "<<ma[d].size()<<endl;
            int siz = ma[d].size();
            sub += (siz - 1);
        }
        ll tot = top[i];
        ll cn = (tot)*(tot-1)/2;
       // debug(cn);
        sub *= (tot-1);
        ans -= sub;
        //cal3
       // if(top[i] <= 2) continue;
      //  ans -= (tot)*(tot-1)*(tot-2)/2/3;
    }
    /* For(i,1,n){
        ll tot = difc[i];
        if(difc[i] <= 1) continue;
        int oth = n - difc[i];
        ans -= (tot)*(tot-1)/2*oth;

        //这里肯定可以满足
      //  if(tot <= 2) continue;
     //   ans -= (tot)*(tot-1)*(tot-2)/2/3;
        //cal3
    } */
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(0);
    int tt; cin>>tt;
    while(tt--) sol();
    return 0;
}