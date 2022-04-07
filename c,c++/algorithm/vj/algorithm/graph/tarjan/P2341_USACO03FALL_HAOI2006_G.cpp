#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define x first
#define y second
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
const int N =  1e4+10, M = 1e5+10;
int e1[M], e2[M], ne1[M], ne2[M], h1[N], h2[N], idx1, idx2; 
void add1(int a, int b){
    e1[idx1] = b, ne1[idx1] = h1[a], h1[a] = idx1++; 
}
void add2(int a, int b){
    e2[idx2] = b, ne2[idx2] = h2[a], h2[a] = idx2++;
}
int dfn[N], finish[N], dfs_clock;
//typedef pair<int,int>PII;
//PII p[N];
int ord[N<<1];
void dfs1(int x){
    if(dfn[x]) return;
    dfn[x] = ++dfs_clock;
    for(int i = h1[x]; ~i; i = ne1[i]){
        int j = e1[i];
        dfs1(j);
    }
    finish[x] = ++dfs_clock;//点的完成时间要不同
    ord[finish[x]] = x;
}
int scc_cnt = 0;
bool st[N];
int id[N], tot;
void dfs2(int x){
    if(st[x]) return ;
    tot++;
    st[x] = true;
    id[x] = scc_cnt;
    for(int i = h2[x]; ~i; i = ne2[i]){
        int j = e2[i];
        dfs2(j);
    }
}
int dout[N], siz[N];
int main(){
    memset(h1,-1,sizeof h2);
    memset(h2,-1,sizeof h2);
    idx1 = idx2 = 0;
    int n, m;
    scanf("%d %d", &n, &m);
    For(i,1,m){
        int a,b;
        scanf("%d %d", &a, &b);
        add1(a,b); add2(b,a);
    }
    For(i,1,n)dfs1(i);
  //  For(i,1,n)p[i] = {finish[i],i};
    //sort(p+1,p+1+n);
    memset(st,0,sizeof st);
    for(int i = n*2; i ; i -- ){
        if(ord[i] && !st[ord[i]]) tot = 0,scc_cnt++,dfs2(ord[i]), siz[id[ord[i]]] = tot;
    }
    //题目部分
    For(x,1,n){
        for(int i = h1[x]; ~i; i = ne1[i]){
            int j = e1[i];
            if(id[x] == id[j]) continue;
            dout[id[x]]++;
        }
    }
   // printf("id:");
  //  For(i,1,n) printf("%d ", id[i]);
  //  puts("");
    int sum = 0, zero = 0;
    For(i,1,scc_cnt) {
        if(dout[i]) continue;
        zero++;
        sum += siz[i];
        if(zero > 1) sum = 0;
    }
    printf("%d\n", sum);
    return 0;
}