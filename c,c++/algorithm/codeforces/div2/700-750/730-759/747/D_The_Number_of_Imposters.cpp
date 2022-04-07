#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i <= (y); i ++ )
#define pb push_back
using namespace std;
const int N = 2e5+10, M = 1e6+10;
int vis[N];
bool vise[M];
int cur[N], h[N], ne[M], idx, e[M], w[M];
int du[N], out[N];
void add(int a, int b, int c){
    w[idx] = c;
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
int n, m;
int cnt = 0, tot = 0, cc_cnt;
void init(){
   // cc_cnt = idx = 0;
   // For(i,0,m) vise[i] = 0;
    For(i,0,n) {
        vis[i] = h[i] = -1;//  out[i] = du[i] = 0;
    }
    idx = 0;
}
//char s[N];
//const char tp[2][N] = {"imposter", "crewmate"};
const string tp[2] = {"imposter", "crewmate"};


bool dfs(int x, int col, int fa){
    if(vis[x] == -1){
        if(col == 0) cnt++;
        tot++;
    }
    vis[x] = col;
    for(int& i = cur[x]; ~i; i = ne[i]){
        int j = e[i];
        if(vis[j] == -1) {
            if(!dfs(j, col^w[i],x)) return false;
        }
        else if( (col^w[i]) != vis[j]) return false;
       // else if(!dfs(j, col^w[i],x)) return false;
    }
    return true;
}

void sol(){
    cin>>n>>m;//scanf("%d %d", &n, &m);
    init();
    int ans = 0;
    bool ok = true;
    
    string s;
    For(i,1,m) {
        int a, b, c; cin>>a>>b>>s;//scanf("%d %d %s", &a, &b, &s);
        c = s==tp[0]?1:0;
        add(a,b,c); add(b,a,c);
       // du[b]++; out[a]++;
    }
    For(i,1,n) cur[i] = h[i];
    //int add = 0;
    /* For(i,1,n) if(out[i])
    For(i,1,n)
        if(du[i] == 0){
            tot = 0; cnt = 0;
            ok &= dfs(i, 0);
            ans += max(cnt, tot - cnt);
        } */
    For(i,1,n) 
        if(vis[i] == -1){
            cnt = 0; tot = 0;
            ok &= dfs(i,0,-1);
            ans += max(cnt, tot - cnt);
        }

    if(!ok) cout<<"-1\n";// puts("-1");
    else {
        cout<<ans<<endl;
    }
}
int main(){
    ios::sync_with_stdio(0);
    int tt; cin>>tt;//scanf("%d", &tt);
    while(tt--) sol();
    return 0;
}