#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <cmath>
#include <cstring>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
#define sz(a) (int)a.size()
#define ALL(a) a.begin(), a.end()
#define mst(x,a) memset(x,a,sizeof(x))
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
//#define DEBUG
#define db double
//#define endl '\n'
#define debug(a) cout << #a << ": " << a << endl
using namespace std;
typedef long long LL;
typedef long long ll;
typedef unsigned long long ULL;
const LL INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int mod = 1e9+7;
typedef pair<int,int>pa;
typedef pair<ll,ll>pai;
typedef pair<db,db> pdd;
const db eps = 1e-6;
const db pi = acos(-1.0);

template<typename T1, typename T2> void ckmin(T1 &a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> void ckmax(T1 &a, T2 b) { if (a < b) a = b; }
int read() {
    int x = 0, f = 0; char ch = getchar();
    while (!isdigit(ch)) f |= ch == '-', ch = getchar();
    while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
    return f ? -x : x;
}
template<typename T> void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x >= 10) print(x / 10);
    putchar(x % 10 + '0');
}
template<typename T> void print(T x, char let) {
    print(x), putchar(let);
}
template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

const int maxn = 200000 + 5;

#define ls u<<1
#define rs u<<1|1
struct Node{
    int l, r;
    int sum, lazy;
}tr[maxn<<2];
const int initVal = (1<<30) - 1;
void build(int u, int l, int r){
    #ifdef DEBUG
    cout<<l<<' '<<r<<endl;
    #endif
    tr[u] = {l,r,initVal,initVal};
    if(l == r) return ;
    else {
        int mid = l+r >>1;
        build(ls,l,mid); build(rs,mid+1,r);
    }
}
void pushdown(int u){
    if(tr[u].lazy != initVal){
        int lazy = tr[u].lazy;
        tr[ls].lazy = lazy; tr[rs].lazy = lazy;
        tr[ls].sum &= lazy, tr[rs].sum &= lazy;
        tr[u].lazy = initVal;
    }
}/*
void pushup(int u){
    tr[u].sum =
} */
void mody(int u, int l, int r, int val){
    if(l <= tr[u].l && tr[u].r <= r){
        tr[u].sum &= val;
        tr[u].lazy = val;
    }else {
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if(l <= mid) mody(ls,l,r,val);
        if(r > mid) mody(rs,l,r,val);
    }
}
int qury(int u, int l, int r){
    if(l <= tr[u].l && tr[u].r <= r){
        return tr[u].sum;
    }else{
        pushdown(u);
        int mid = tr[u].l + tr[u].r>>1;
        if(l <= mid) return qury(ls,l,r);
        else return qury(rs,l,r);
    }
}
vector<int> lx;
pa line[maxn];
int a[maxn];
int q2[maxn];
void init(){
    q2[0] = 1;
    fori(i,1,maxn) q2[i] = 1ll*q2[i-1]*2%mod;
}
void sol(){
    lx.clear();
    int n, m; cin>>n>>m;
    build(1,1,n);
    For(i,1,m){
        int l, r, x;
        cin>>l>>r>>x;
        lx.push_back(l);
        lx.push_back(r);
        mody(1,l,r,x);
    }
    #ifdef DEBUG
    cout<<"ok1"<<endl;
    #endif
    //lx.push_back(1);
    lx.push_back(n);
    sort(ALL(lx));
    lx.erase(unique(ALL(lx)),lx.end());
    int l = 1, r;
    fori(i,0,lx.size()){
        r = lx[i];
        int val = qury(1,l,r);
        //cout<<"l,r,val:  "<<l<<' '<<r<<' '<<val<<endl;
        For(j,l,r) a[j] = val;
        l = lx[i]+1;
    }
    #ifdef DEBUG
    cout<<"ok2"<<endl;
    #endif
    int res = 0;
    l = 1, r;
    for(int k = 0; k < 30; k ++ ){
        int cnt[2]{};
        For(i,1,n) cnt[(a[i]>>k)&1]++;
        //if(k==1)cout<<cnt[1]<<endl;
        if(cnt[1])res += 1ll*(q2[cnt[1]] - q2[cnt[1]-1] + mod) %mod * q2[cnt[0]]  % mod * (1<<k) % mod;
        res %= mod;
    }
    cout<<res<<endl;
}



int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tt; cin>>tt;
    init();
    while(tt--)
        sol();
    return 0;
}
