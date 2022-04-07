#include <cstdio>
#include <cstring>
#include <assert.h>
#include <iostream>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
const int N = 5e5+10;
struct Node{
    int fa, len;
    int ch[2];
} node[N<<1];
int tot = 1, last = 1;
void init(){
    For(i,1,tot) {
        auto& ch = node[i].ch;
        memset(ch, 0, sizeof ch);
    }
    tot = last = 1;
}
int siz[N];
void extend(int c){
    //以下是1，2，3，4，5，。。。链的部分
    int p = last, np = last = ++tot;
    node[np].len = node[p].len+1;
    //
    for(; p && !node[p].ch[c]; p = node[p].fa) node[p].ch[c] = np;
    //通过前面的后缀 指向当前这个点(即连接蓝边)
    if(!p) node[np].fa = 1;
    else {
        int q = node[p].ch[c];
        if(node[q].len == node[p].len + 1) node[np].fa = q;
        else {
            int nq = ++tot;
            node[nq] = node[q], node[nq].len = node[p].len + 1;
            node[q].fa = node[np].fa = nq;
            for(; p && node[p].ch[c] == q; p = node[p].fa) node[p].ch[c] = nq;
        }
    }
}
int n;
char s[N];
typedef long long ll;
ll ans = 0;
struct Tnode{
    int l, r;
    int mx, cnt;
    friend Tnode operator + (const Tnode& a, const Tnode& b){
        Tnode c; c.mx = max(a.mx, b.mx), c.cnt = 0;
        /* if(a.l == a.r && a.l == 0){
            cout<<"a.mx:";
            cout<<a.mx;
            cout<<",b.mx:"<<b.mx<<endl;
        } */
        if(c.mx == a.mx) c.cnt += a.cnt;
        if(c.mx == b.mx) c.cnt += b.cnt;
        c.l = a.l, c.r = b.r;
        return c;
    }
};
int pre[N];
namespace segtree{
    #define ls u<<1
    #define rs u<<1|1
    Tnode tr[N<<2];
    void build(int u, int l, int r){
     //   printf("l = %d, r = %d\n",l, r);
        if(l == r){
            tr[u] = {l,l,pre[l],1};
        }else {
            int mid = l + r >>1;
            build(ls,l,mid); build(rs,mid+1,r);
            tr[u] = tr[ls] + tr[rs];
        }
    }
    Tnode qury(int u, int l, int r){
        if(l > tr[u].r || r < tr[u].l) return Tnode{10,10,-N-5,1};
        if(l <= tr[u].l && tr[u].r <= r) return tr[u];
        Tnode res = qury(ls, l, r) + qury(rs, l, r);
		/* cout<<"res.cnt = "<<res.cnt<<endl;
        cout<<"res.l: "<<res.l<<", res.r = "<<res.r<<endl; */
		return res;
    }
}
using namespace segtree;
int top = 0;
int stk[N];
int main(){
    init();
    scanf("%d%s",&n, (s+1));
    For(i,1,n) pre[i] = pre[i-1] + (s[i] == '(' ? -1: 1);
   // assert(0);
    build(1,0,n-1);
    //assert(0);
    stk[0] = 0;
    For(i,1,n) {
        if(s[i] == '(') stk[++top] = i;
        else if(top) top--;
        extend(s[i] == ')');
        int f = node[last].fa;
        int r = node[last].len - node[f].len;
        int l = stk[top] + 1;
      //  cout<<l<<' '<<r<<endl;
        if(l <= r){
            Tnode res = qury(1,l - 1,r - 1);
            if(res.mx == pre[i]) {
                ans += res.cnt;
                if( res.mx == pre[i] ) {
				//ans += p.cnt;
				/* cout<<l<<' '<<r<<endl;
				cout<<"i:"<<i<<", p.mx = "<<res.mx<<", p.cnt"<<res.cnt<<endl; */
                }
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}
/*
1 2
i:2, p.mx = 0, p.cnt1
1 2
i:4, p.mx = 0, p.cnt1
1 2
i:6, p.mx = 0, p.cnt1
1 2
i:8, p.mx = 0, p.cnt1
1 2
i:10, p.mx = 0, p.cnt1
5
*/
