#include <cstdio>
#include <cstring>
#include <assert.h>
#include <iostream>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
const int N = 1e5+10;
struct Node{
    int l, r;
    int lazy, sum;
} tr[26][N<<2];
char s[N];
int n, m;
#define ls u<<1
#define rs u<<1|1
void pushup(int x, int u){
    tr[x][u].sum = tr[x][ls].sum + tr[x][rs].sum;
}
void pushdown(int x, int u){
    if(tr[x][u].lazy != -1){
        auto& l = tr[x][ls], &r = tr[x][rs];
        int& lazy = tr[x][u].lazy;
        l.lazy = lazy, r.lazy = lazy;
        l.sum = (l.r - l.l + 1)*lazy;
        r.sum = (r.r - r.l + 1) * lazy;
        //l.sum += lazy; r.sum += lazy;
        //l.lazy += lazy, r.lazy += lazy;
        lazy = -1;
    }
}
void build(int x, int u, int l, int r){
    tr[x][u] = {l,r,-1};
    if(l == r) tr[x][u].sum = (x == (s[l]-'a')); 
    else {
        int mid = l + r >> 1;
        build(x,ls,l,mid);
        build(x,rs,mid+1,r);
        pushup(x,u);
    }
}
void mody(int x, int u, int l, int r, int v){
    auto & t = tr[x][u];
    if(l <= tr[x][u].l && tr[x][u].r <= r){
        t.lazy = v;
        t.sum = (t.r - t.l + 1) * v;
    }else {
        int mid = t.l + t.r >> 1;
        pushdown(x,u);
        if(l <= mid) mody(x,ls,l,r,v);
        if(r > mid) mody(x,rs,l,r,v);
        pushup(x,u);
    }
}
int qury(int x,int u,  int l, int r){
    if(l <= tr[x][u].l && tr[x][u].r <= r) return tr[x][u].sum;
    else {
        pushdown(x,u);
        int sum = 0;
        int mid = tr[x][u].l + tr[x][u].r >> 1;
        if(l <= mid) sum += qury(x,ls,l,r);
        if(r > mid) sum += qury(x,rs,l,r);
        return sum;
    }
}

int main(){
    freopen("input.txt","r", stdin);
    freopen("output.txt","w",stdout);
    scanf("%d %d", &n, &m);
    scanf("%s", (s+1));
    fori(x,0,26)build(x,1,1,n);
    while(m--){
        int l, r; scanf("%d %d", &l,&r);
        int cnt[26]{};
        int odd = 0, pos = -1;
        fori(x,0,26) {
            cnt[x] = qury(x,1,l,r);
            odd += cnt[x]&1;
            if(cnt[x]&1) pos = x;
        }
        if(odd>=2) continue;
        fori(x,0,26) mody(x,1,l,r,0);
        if(pos != -1) cnt[pos]--,mody(pos,1,l+r>>1,l+r>>1,1);
        int len = 0;
        fori(x,0,26) {
            if(cnt[x] == 0) continue;
            //cout<<"m:"<<m<<", x:"<<x<<endl;
           // assert(l+len <= l+len+cnt[x]/2 - 1);
            mody(x,1,l+len,l+len+cnt[x]/2 - 1,1);
             //assert(r-cnt[x]/2+1 - len <= r-len);
            mody(x,1,r-cnt[x]/2+1 - len,r-len,1);
            len += cnt[x]/2;
        }
        /*
        if(pos != -1) {
          //  cout<<"l:"<<l+len<<", r:"<<r-len<<endl;
            mody(pos,1,l+len,r-len,1); 
        }
        */
    }
    For(i,1,n)fori(x,0,26)if(qury(x,1,i,i)) printf("%c", x + 'a');
    return 0;
}