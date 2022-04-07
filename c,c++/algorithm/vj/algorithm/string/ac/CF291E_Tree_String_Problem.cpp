#include <cstdio>
#include <cstring>
#include <cctype>
#include <vector>
#include <string>
#include <iostream>
#define x first
#define y second
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
typedef long long ll;
const int maxn = 3e5 + 10;
const int mod1 = 1e9+7;
const int mod2 = 1e9+3;
const int q1 = 13331, q2 = 131;
//const int mod[2] = {int(1e9+7), int(1e9+9)};
//const int q[2] = {13331, 131};
typedef pair<ll,ll> PLL;
PLL ha[maxn][21], p[maxn];
int f[maxn][21], depth[maxn];
void init(){
    p[0].x = p[0].y = 1;
    fori(i,1,maxn){
        p[i].x = p[i-1].x * q1 % mod1;
        p[i].y = p[i-1].y * q2 % mod2;
    }
}
PLL get(string& s){
    PLL res = {0,0};
    for(auto ch: s){
        res.x = (res.x * q1 % mod1 + ch) % mod1;
        res.y = (res.y * q2 % mod2 + ch) % mod2;
    }
    return res;
}
int read(){
    char ch = getchar(); int f = 0, x = 0;
    while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
    while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    return f ? -x : x;
}
int n;
typedef pair<int,string> Edge;
vector<Edge> edge[maxn];
typedef pair<int,char> Edgec;
vector<Edgec> e[maxn];
int idx;
int toId[maxn]; bool vis[maxn];
void dfs1(int x, int pre){
    int cur;
    for(auto v: edge[x]){
        string& s = v.y;
        cur = pre;
        fori(i,0,s.size()){
            e[cur].push_back({ ++idx,s[i]});
            //printf("u = %d, v = %d\n", cur, idx);
            cur = idx;
        }
        //printf("x = %d\n",v.x);
        toId[v.x] = idx;
        vis[idx] = true;
        dfs1(v.x, idx);
    }
}
int tlen;
PLL modle;
int ans = 0;
bool match(int x){
    bool ok = true;
    int len = tlen;
    PLL res = {0,0};
    int curLen = 0;
    int pre = x;
    for(int k = 20; k >= 0; k -- ){
        if( (1 << k) <= len){
            len -= (1<<k);
            res.x = (res.x + ha[x][k].x * p[curLen].x % mod1) %mod1;
            res.y = (res.y + ha[x][k].y * p[curLen].y % mod2) % mod2; 
            curLen += (1<<k);
            x = f[x][k];
        }
    }
    /* if(vis[pre]){
        printf("vis[x] = %d\n", pre);
        printf("ha1 = %lld\n", res.x);
        printf("ha2 = %lld\n", res.y);
    } */
    ok &= res == modle;
    return ok;
}
void dfs2(int x, int dep){
    //depth[x] = dep;
    for(auto v: e[x]){
        char ch = v.y;
        int j = v.x;
      //  printf("j = %d\n", j);//cout<<"j:"<<j<<endl;
        depth[j] = dep + 1;
        f[j][0] = x;
        ha[j][0].x = ch;
        ha[j][0].y = ch;
        for(int k = 1; k <= 20; k ++ ){
            int anc = f[j][k-1];
            f[j][k] = f[anc][k-1];
            int len = depth[j] - depth[anc];
            ha[j][k].x = (ha[anc][k-1].x*p[len].x% mod1 + ha[j][k-1].x) % mod1;
            ha[j][k].y = (ha[anc][k-1].y*p[len].y%mod2 + ha[j][k-1].y) % mod2;
        }
        ans += match(j);
        dfs2(j,dep + 1);
    }
}
int main(){
    init();
    //n = read();
    ios::sync_with_stdio(0);
    cin>>n;
    For(i,2,n){
        int p; string s;
        cin>>p>>s;
        edge[p].push_back({i,s});
    }
    //toId[0] = 0; 0 好点默认是空出来的
    dfs1(1,0);
    //for(int i = 1; i <= n; i ++ )printf("toId[%d] = %d\n", i, toId[i] );
    string t; cin>>t;
    tlen = t.size();
    modle = get(t);
     /* printf("modle\n");
        printf("ha1 = %lld\n", modle.x);
        printf("ha2 = %lld\n", modle.y); */
    dfs2(0, 0);
    cout<<ans<<endl;
    return 0;
}