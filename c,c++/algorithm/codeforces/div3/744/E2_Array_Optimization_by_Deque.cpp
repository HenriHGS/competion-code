#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#define mp make_pair
#define pb push_back
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
const int N = 2e5+10;
int n, m;
int a[N];
int tr[N];
int lowbit(int x){return x&(-x);}
void add(int x, int v){
    for(int i = (x); i <= m; i += lowbit(i)) tr[i] += v;
}
int sum(int x){
    int res = 0;
    for(int i = x; i ; i -= lowbit(i)) res += tr[i];
    return res;
}
int sum(int l, int r){
    return sum(r) - sum(l-1);
}
//int ans[N];
deque<int> ans;

int lx[N];
void sol(){
    cin>>n;
    For(i,1,n) cin>>a[i], lx[i] = a[i];
    sort(lx +1, lx+1+n); 
    m = unique(lx+1,lx+1+n) - (lx+1);
    For(i,1,n){
        tr[i] = 0;
        a[i] = lower_bound(lx+1,lx+1+m, a[i]) - lx;
    }
    ll ans = 0;
    For(i,1,n){
       // cout<<a[i]<<endl;
        ans += min(sum(a[i] - 1), sum(a[i] + 1, m));
      //  cout<<"sum1" << sum(a[i] - 1)<<" sum2:"<<sum(a[i] + 1, m)<<endl;
        add(a[i],1);
    }
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(0);
    int tt;
    cin>>tt;
    while(tt--) sol();
    return 0;
}