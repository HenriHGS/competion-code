#include <cstdio>
#include <iostream>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
typedef long long LL;
const int N = 2e6;
struct Node{
    int l, r;
    LL sum;
}tr[N<<2];
int a[N];
#define ls u<<1
#define rs u<<1|1
void pushup(int u){
    tr[u].sum = tr[ls].sum + tr[rs].sum;
}
void build(int u, int l, int r){
    if(l==r){
        tr[u] = {l,r, a[l]};
        return ;
    }
    else {
        tr[u] = {l,r};
        int mid = l + r >> 1;
        build(ls, l, mid);
        build(rs, mid + 1, r);
        pushup(u);
    }
}
int rev[N];//标记区间是否翻转
int n, q;
void mody(int u, int x, int v, int depth, int l, int r){
    if(l == r && l == x){
        //cout<<l << ' ' << r << ' '<<tr[u].sum<<endl;
        tr[u].sum = v;
    }else {
        int mid = l + r >> 1;
        if(x <= mid) mody((ls) + (rev[depth] == 1),x,v, depth - 1, l, mid);
        if(x > mid) mody((rs) - (rev[depth] == 1),x,v, depth - 1, mid+1, r);
        pushup(u);
      //  cout<<l << ' ' << r << ' '<<tr[u].sum<<endl;
    }
}
LL query(int u, int l, int r, int depth, int rl, int rr){
    if(l <= rl && rr <= r) {
     //   cout<<rl << ' ' << rr << ' '<<tr[u].sum << ' ' << u<<endl;
        return tr[u].sum;
    }
    else {
        int mid = rl + rr >> 1;
        LL ans = 0;
        if(l <= mid) ans += query((ls) + (rev[depth] == 1), l, r, depth - 1, rl, mid);
        if(r > mid) ans += query((rs) - (rev[depth] == 1), l, r, depth - 1, mid + 1, rr);
       // cout<<rl<<' '<< rr << ' '<<ans<<endl;
        return ans;
    }
}
void sol(){
    scanf("%d%d", &n, &q);
    For(i,1,1<<n){
        scanf("%d", a+i);
    }
    build(1, 1, 1<<n);
    while(q--){
        int op;
        scanf("%d", &op);
       // cout<<op<<endl;
        if(op == 1){
            int x, k;
            scanf("%d%d", &x, &k);
           // cout<<op << ' '<< x<< ' '<<k<<endl;
         //  cout<<"debug"<<endl;
            mody(1,x,k, n, 1, 1<<n);
          //  cout<<"end"<<endl;
        }else if(op == 2){
            int k;
            scanf("%d", &k);
            For(i,0,k)rev[i] ^= 1;
        }else if(op == 3){
            int k;
            scanf("%d", &k);
            rev[k+1] ^= 1;
        }else {
            int l, r;
            scanf("%d%d", &l, &r);
          //  cout<<"debug2"<<endl;
            printf("%lld\n", query(1,l,r, n, 1, 1<<n));
           // cout<<"end2"<<endl;
        }
    }
}
int main(){
    sol();
    return 0;
}