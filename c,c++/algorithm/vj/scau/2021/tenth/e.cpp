#include <cstdio>
#include <algorithm>
#include <set>
#include <iostream>
#include <queue>
#include <cmath>
#define fi first
#define se second
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
const int N = 4e5+10;
struct Node{
    int l, r;
    int mx, tag;
} tr[N<<2];
struct Pawn{
    int cur, x, y;
    bool operator < (const Pawn&a)const{
        if(cur != a.cur) return cur < a.cur;
        if(x != a.x) return x < a.x;
        return y < a.y;
    }
};
#define ls u<<1
#define rs u<<1|1
void pushup(int u){
    tr[u].mx = max(tr[ls].mx,tr[rs].mx);
}
void pushdown(int u){
    if(tr[u].tag){
        tr[ls].mx += tr[u].tag;
        tr[rs].mx += tr[u].tag;
        tr[ls].tag+= tr[u].tag;
        tr[rs].tag+= tr[u].tag;
        tr[u].tag = 0;
    }
}
void build(int u, int l, int r){
    if(l >= r){
        tr[u] = {l,r,l};
       // cout<<l<<' '<<r << 
    }else {
        int mid = l + r >>1;
        tr[u] = {l,r};
        build(ls,l,mid);
        build(rs,mid+1,r);
        pushup(u);
    }
}
void update(int u, int l, int r, int v){
    if(l <= tr[u].l && tr[u].r <= r){
        tr[u].mx += v;
        tr[u].tag += v;
        return ;
    }else {
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if(l <= mid)update(ls,l,r,v);
        if(r > mid) update(rs,l,r,v);
        pushup(u);
        return ;
    }
}
int query(int u, int l, int r){
    if(l <= tr[u].l && tr[u].r <= r){
        return tr[u].mx;
    }else {
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        int mx = 0;
        if(l <= mid) mx = max(mx, query(ls,l,r));
        if(r > mid) mx = max(mx, query(rs,l,r));
        return mx;
    }
}
int n, k, m;
void sol(){
    scanf("%d%d%d", &n, &k, &m);
    //cout<<n <<' '<<  m<<' ' << k<<endl;
    set<Pawn> S;
    build(1,1,2*n);
   // For(i,1,2*n)update(1,i,i,i);
    while(m--){
        int x, y;
        scanf("%d%d", &x, &y);
        int cur = y + abs(x-k);
        if(S.count({cur,x, y})){
            S.erase({cur, x, y});
            update(1, 1, cur, -1);
        }else {
            S.insert({cur, x, y});
            update(1, 1, cur, 1);
        }
        if(S.empty()){
            printf("0\n"); 
        }else {
            int val = S.rbegin()->cur;
            printf("%d\n", max(0, query(1,0,val) - n-1));
        }
    }
}
int main(){
    sol();
    return 0;
}