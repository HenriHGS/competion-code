#include <cstdio>
#include <cstring>
#include <cmath>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
const int N = 1e6+10;
struct Node{
    int len, fa;
    int ch[26];
} node[N<<1];
typedef long long ll;
int f[N<<1];
int last, tot;
void init(){
    tot = 1;
    last = 1;
    For(i,0,tot) f[i] = 0,memset(node[i].ch, 0, sizeof node[i].ch);
}
ll ans;
void insert(int c){
    int p = last,  np = last =  ++tot;
    node[np].len = node[p].len + 1;
    f[tot] = 1;
    for(; p && !node[p].ch[c]; p = node[p].fa) node[p].ch[c] = np;
    if(!p) node[np].fa = 1;
    else {
        int q = node[p].ch[c];
        if(node[q].len == node[p].len + 1) node[np].fa = q;
        else{
            int nq = ++tot;
            node[nq] = node[q]; node[nq].len = node[p].len + 1;
            node[q].fa = node[np].fa = nq;
            for(; p &&  node[p].ch[c] == q; p = node[p].fa) node[p].ch[c] = nq;
        }
    }
}
char s[N];
int h[N<<1], e[N<<1], ne[N<<1], idx;
void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
void dfs(int x){
    for(int i = h[x]; ~i; i = ne[i]){
        int j = e[i];
        dfs(j);
        f[x] += f[j];
    }
    if(f[x] > 1) ans = max(ans, 1ll*f[x] * node[x].len);
}
int main(){
    last = ++tot;
    memset(h,-1,sizeof h);
    scanf("%s", &s);
    int len = strlen(s);
    fori(i,0,len){
        insert(s[i] - 'a');
    }
    For(i,1,tot) add(node[i].fa, i);
    dfs(1);
    printf("%lld\n", ans);
    return 0;
}