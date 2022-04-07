#include <cstdio>
#include <cstring>
using namespace std;
const int N = 1e5+10;
typedef long long ll;
struct Node{
    int len, fa,ch[26];
}node[N<<1];
int tot, last;
ll f[N<<1];

char s[N];
void insert(int c){
    int p = last, np = last = ++tot;
    node[np].len = node[p].len + 1;
    f[tot] = 1;
    for( ; p && !node[p].ch[c]; p = node[p].fa) node[p].ch[c] = np;
    if(!p) node[np].fa = 1;
    else {
        int q = node[p].ch[c];
        if(node[q].len == node[p].len + 1) node[np].fa = q;
        else {
            int nq = ++tot;
            node[nq] = node[q]; node[nq].len = node[p].len + 1;
            node[q].fa = node[np].fa = nq;
            for(; p && node[p].ch[c] == q; p = node[p].fa) node[p].ch[c] = nq;
        }
    }
}
int e[N<<3], h[N<<3], ne[N<<3], idx;
void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
void init(){
    memset(h,-1,sizeof h);
    for(int i = 0; i < tot; i ++ ) {
        f[i] = 0;
        memset(node[i].ch, 0, sizeof node[i].ch);
    }
    last = tot = 1;
}

ll ans = 0;
ll dp[N<<1];
ll dfs(int x){
    if(dp[x]) return dp[x];
    ll res = 1;
    for(int i = h[x]; ~i; i = ne[i] ){
        int j = e[i];
        res += dfs(j);
    }
    dp[x] = res;
    return res;
}
int main(){
    init();
    int n; scanf("%d", &n);
    scanf("%s", s);
    for(int i = 0; i < n; i ++ ) insert(s[i] - 'a');
   // for(int i = 1; i <= tot; i ++ ) add(node[i].fa, i);
   /* for(int x = 1; x <= tot; x ++ ) for(int i = 0; i < 26; i ++ ){
       if(!node[x].ch[i])continue;
        int j = node[x].ch[i];
        add(x,j);
       // res += dfs(j);
   } */
    for(int i = 1; i <= tot; i ++ ) ans += node[i].len - node[node[i].fa].len;
    printf("%lld\n",ans);
    return 0;
}