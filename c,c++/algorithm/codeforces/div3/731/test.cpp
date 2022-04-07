# include <bits/stdc++.h>
using namespace std;
const int N  = 5e5+10;
typedef long long LL;

LL w[N];
int n, m;
struct Node{
    int l,r;
    LL sum;
    LL d;
} tr[N<<2];

LL gcd(LL a, LL b){return b?gcd(b,a%b):a;}

void pushup(Node&u, Node& l, Node& r){
    u.sum = l.sum + r.sum;
    u.d = gcd(l.d,r.d);
}
void pushup(int u){
    pushup(tr[u],tr[u<<1],tr[u<<1|1]);    
}

void build(int u, int l, int r){
    if(l==r) tr[u]={l,l,w[r]-w[r-1],w[r]-w[r-1]};
    else {
        tr[u]={l,r};
        int mid= l+r>>1;
        build(u<<1,l,mid);
        build(u<<1|1,mid+1,r);
        pushup(u);
    }
}
void mody(int u, int x, LL v){
    if(tr[u].l==x && tr[u].r==x){
        tr[u] = {x,x,tr[u].sum+v,tr[u].d+v};
    }else {
        int mid = tr[u].l+tr[u].r>>1;
        if(x<=mid)mody(u<<1,x,v);
        else mody(u<<1|1,x,v);
        pushup(u);
    }
}
Node quary(int u, int l, int r){
    if(l<=tr[u].l && tr[u].r<=r) return tr[u];
    else {
        int mid = tr[u].l+tr[u].r>>1;
        if(r<=mid) return quary(u<<1,l,r);
        else if(l>mid) return quary(u<<1|1,l,r);
        else {
            auto left = quary(u<<1,l,r);
            auto right = quary(u<<1|1,l,r);
            Node tree;
            pushup(tree,left, right);
            return tree;
        }
    }
}
int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1;i <= n; i ++ )scanf("%lld", w+i);
    build(1,1,n);
    while(m -- ){
        char op[2];
        int l, r;
        LL d;
        scanf("%s%d%d",op, &l, &r);
        if(*op=='Q'){
            auto left = quary(1,1,l);
            auto right = quary(1,l+1,r);
            printf("%lld\n", abs(gcd(left.sum, right.d) ) );
            //数学意义上的gcd为正
        }else {
            scanf("%lld", &d);
            mody(1,l,d);
            if(r+1<=n)mody(1,r+1,-d);
            //差分修改的时候不能超过范围，不然没有意义。
        }
    }
    return 0;
}