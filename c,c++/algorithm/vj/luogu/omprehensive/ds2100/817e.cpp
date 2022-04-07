#include <cstdio>
#include <cstring>
#define mst(x,a) memset(x,a,sizeof x)
#define For(i,xy) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
typedef long long LL;
typedef long long ll;
const int M = 30;
const int sigma_size = 2, N = 1e5+10, maxnode = 32*N;
int tr[maxnode][sigma_size];
int cnt[maxnode];
int tot;
void init(){
    tot = 1;
    mst(tr,0);
    mst(cnt,0);
}
void add(int x, int v){
    int p = 1;
    bool c;
    for(int i = 1<<30; i; i >>= 1){
        c = i&x;
        if(!tr[p][c]) tr[p][c] = ++tot;
        cnt[p] += v;
        p = tr[p][c];
       // cnt[p] += v;
    }
    cnt[p] += v;
}
//分类讨论一下
int ask(int x, int l){
    bool cp, cl;
    int p = 1;
    int res = 0;
    for(int i = 1<<30; i; i >>=1){
        cp = x&i, cl = l&i;
        if(cl) {
            res += cnt[tr[p][cp]];
            p = tr[p][cp^1];
        }else p = tr[p][cp];
    }
    return res;
}
int main(){
    init();
    int q;
    scanf("%d", &q);
    while(q--){
        int op, x, l;
        scanf("%d %d", &op, &x);
        if(op == 1) add(x,1);
        else if(op == 2) add(x,-1);
        else {
            scanf("%d", &l);
            printf("%d\n", ask(x,l));
        }
    }
    return 0;
}
/*
4
1 72
3 55 8
1 67
3 92 73
*/