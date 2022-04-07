#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define sz(a) (int)a.size()
#define pb push_back
#define fori(i,x,y) for(int i =(x); i < (y); i ++ )
#define For(i,x,y) for(int i = (x); i <= (y); i ++ ) 
using namespace std;
typedef long long ll;
const int N = 1e5+10;
struct Node{
    int len, fa;
    int ch[26];
}node[N<<1];
struct Node1{
    int len, fa;
    int id;
};
int f[N<<1];
int last, tot;
vector<Node1> bb[N];
int n;
char s[N];ll dp[N<<1], ans;
void init(){
    ans = 0;
    scanf("%s", s+1); n = strlen(s+1);
    For(i,0,n) bb[i].clear();
    For(i,0,tot) {
        dp[i] = f[i] = 0;
        auto& ch = node[i].ch; memset(ch,0, sizeof ch);
    }
    last = tot = 1;
}
void insert(int x){
    int p = last, np = last = ++tot;
    node[np].len = node[p].len + 1;
    f[tot] = 1;
    for(; p && !node[p].ch[x]; p = node[p].fa) node[p].ch[x] = np;
    if(!p) node[np].fa = 1;
    else {
        int q = node[p].ch[x];
        if(node[q].len == node[p].len + 1) node[np].fa = q;
        else {
            int nq = ++tot;
            node[nq] = node[q], node[nq].len = node[p].len + 1;
            node[q].fa = node[np].fa = nq;
            for(; p && node[p].ch[x] == q; p = node[p].fa) 
                node[p].ch[x] = nq;
        }
    }
}
void sol(){
    init();
    For(i,1,n) insert(s[i] - 'a');
    For(i,1,tot) {
        int len = node[i].len;
        Node1 pp = {node[i].len, node[i].fa, i};
        bb[len].pb(pp);
    }
    for(int i = n; i >= 1; i -- ){
        for(auto nn: bb[i]){
            int fa = nn.fa;
            int u = nn.id;
            f[fa] += f[u];
            ans += 1ll*f[u]*f[u]*(node[u].len - node[node[u].fa].len);
        }
    }
    printf("%lld\n", ans);
}
int main(){
    int tt; scanf("%d", &tt);
    while(tt--) sol();
    return 0;
}