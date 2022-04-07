#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
const int N = 2e5+10;
typedef long long LL;
LL tr1[N], tr2[N];
int n,q;
int lowbit(int x){return x&(-x);}
void add(LL tr[], int x, int val){
    for(int i = x; i <= n; i += lowbit(i)) tr[i] += val;
}
LL sum(LL tr[], int x){
    LL res = 0;
    for(int i = x; i; i -= lowbit(i)) res += tr[i];
    return res;
}
LL pre_sum(int x){
    return sum(tr1,x)*(x+1) - sum(tr2,x);
}
int a[N];
void sol(){
    //int n, q;
    cin>>n>>q;
    For(i,1,n)cin>>a[i];
    sort(a+1,a+1+n);
    LL ans = 0;
    while(q--){
        int l, r;
        cin>>l>>r;
        add(tr1,l,1), add(tr2,l,l*1);
        add(tr1,r+1,-1), add(tr2,r+1,-(r+1)*1);
       // cout<<"pre[l]:"<<pre_sum(l)<<" pre[r]:"<<pre_sum(r)<<endl;
    }
    vector<LL>v;
    For(i,1,n){
        v.pb(pre_sum(i) - pre_sum(i-1));
        //cout<<v[i-1]<<endl;
    }
    sort(ALL(v));
   // reverse(ALL(v));
    fori(i,0,n)ans += v[i]*a[i+1];
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio();
    sol();
    return 0;
}