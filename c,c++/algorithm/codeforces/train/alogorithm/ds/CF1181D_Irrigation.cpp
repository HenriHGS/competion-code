#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <cctype>
#define x first
#define y second
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<ll,int> PII;
const int N = 5e5+10;

template<typename T> void read(T& x){
    char ch = getchar(); T f = 0; x = 0;
    while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
    while(isdigit(ch)) x = x*10 + ch - '0', ch = getchar();
}
template<typename T> void print(T x){
    if(x< 0) putchar('-'), x = -x;
    if(x >= 10) print(x/10);
    putchar(x%10 + '0');
}
template<typename T> void print(T x, char let){
    print(x), putchar(let);
}
int n, m, q;
int rk[N];

PII qury[N];
int ans[N];

set<int> S[N];

struct Tnode{
    int l, r;
    int sum;
}tr[N<<2];

#define ls u<<1
#define rs u<<1|1
void build(int u, int l, int r){
    tr[u] = {l,r,0};
    if(l == r) return;
    else {
        int mid = tr[u].l + tr[u].r >> 1;
        build(ls,l,mid); build(rs,mid+1,r);
    }
}
void pushup(int u){
    tr[u].sum = tr[ls].sum + tr[rs].sum;
}
void mody(int u, int x){
    if(tr[u].l == x && tr[u].r == x){
        tr[u].sum ++;
    }else {
        int mid = tr[u].l + tr[u].r >> 1;
        if(x <= mid) mody(ls,x);
        else mody(rs,x);
        pushup(u);
    }
}
int kth(int u,int k){
    if(tr[u].l == tr[u].r) return tr[u].l;
    if(tr[ls].sum < k) k-= tr[ls].sum;
    else return kth(ls,k);
    return kth(rs,k);
}
void merge(int i){
    for(auto x: S[i]) mody(1,x);
}
ll pre[N];
int main(){
    //ios::sync_with_stdio(0); cin.tie(0), cout.tie(0);
   // cin>>m>>n>>q;
    read(m), read(n), read(q);
    int mx = 0;
    for(int i = 1; i <= m; i ++ ){
        int x; read(x);//cin>>x;
        rk[x]++;
        mx = max(mx,rk[x]);
    }
    for(int i = 1; i <= q; i ++ ){
        ll k; read(k);//cin>>k;
        qury[i] = {k,i};
    }
    sort(qury + 1, qury + 1 + q);

    int mi = m;
    for(int i = 1; i <= n; i ++ ){
        S[rk[i]].insert(i);
        mi = min(mi, rk[i]);
    }

    for(int i = mi; i <= mx; i ++ ){
        if(i)pre[i] = pre[i-1];
        for(auto x: S[i]) pre[i] += i;
    }
    ll cur = m;
    int i = 1;
    const ll END = 1ll*mx*n;
    build(1,1,n);
    // cout<<"mi:"<<mi<<endl;
     //cout<<"mx:"<<mx<<endl;
    for(int d = mi; d <= mx; d ++ ){
        merge(d);
        //ll pre = 1ll*tr[1].sum * d, suf = min(END, 1ll*(d+1)*n);
        ll sum1 = 1ll*tr[1].sum * d + (m - pre[d]);
        ll sum2 = min(END, 1ll*(d+1)*(tr[1].sum + (pre[d + 1] - pre[d]) / (d+1))
        + (m - pre[d + 1]));
        //cout<<"sum1:"<<sum1<<"   sum2:"<<sum2<<endl;
        if(qury[i].x >= END) {
            //cout<<"xxxxx"<<endl;
            //cal
            continue;
        }
        while(i <= q && qury[i].x >= sum1 && qury[i].x <= sum2){
            ll kt = (qury[i].x - sum1)%tr[1].sum;
            if(kt == 0) kt = tr[1].sum;
           /*   if(qury[i].x == 186){
                //cout<<"sum1:"<<sum1<<endl;
                //cout<<"sum2:"<<sum2<<endl;
                cout<<"kt:"<<kt<<endl;
                cout<<"d:"<<d<<endl;
                cout<<"tr[1].sum:"<<tr[1].sum<<endl;
            }  */
            ans[qury[i].y] = kth(1,kt);
            i++;
        }
    }
    //cout<<"END:"<<END<<endl;
    while(i <= q){
       // cout<<"i:"<<i<<endl;
      // cout<<"qury[i].x"<<qury[i].x<<endl;
        ll kt = qury[i].x%n;
        if(kt == 0) kt = n;
        ans[qury[i].y] = kth(1,kt);
        i++;
    }
    for(int i = 1; i <= q; i ++) print(ans[i], " \n"[1]);
    return 0;
}
