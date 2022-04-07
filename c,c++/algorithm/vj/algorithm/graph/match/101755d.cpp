#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#define pb push_back
#define debug(a) cout<<#a<<":"<<a<<endl
using namespace std;
const int N = 310;
char s[N][N];
int f[N][N];
int n, k;
int n1, n2;
int match[N];
bool st[N];
int a[N], b[N], have[N];
int l[N], r[N];

typedef pair<int,int> PII;
vector<PII>ansp;
bool find(int x){
    for(int i = 1; i <= n2; i ++ ){
        int j = r[i];
        if(f[x][j] && !st[j]){
            st[j] = true;
            if(match[j] == 0 || find(match[j])){
                match[j] = x;
                return true;
            }
        }
    }
    return false;
}
int pre[N], S, T;
int d[N], q[N];
void bfs(){
    memset(d,-1,sizeof d);
    int tt = 0, hh = 0;
    q[0] = S;  d[S] = 0;
    while(hh <= tt){
        int t = q[hh++];
       // debug(t);
        for(int ver = 1; ver <= n; ver ++ ){
            if(d[ver] == -1 && s[t][ver]){
                d[ver] = d[t] + 1;
                pre[ver] = t;
                if(ver == T) return;
                q[++tt] = ver;
            }
        }
    }
}
int ans[N], tot;
void trace(){
    tot = 0;
    for(int i = T; i != S; i = pre[i]){
        ans[tot++] = i;
        if(have[i]){
            for(int j = tot - 2; j >= 0; j--) ansp.pb({ans[j+1], ans[j]});
            //printf("%d %d\n", ans[j+1], ans[j]);
            tot = 1;
            ans[0] = i;
        }
    }
   // debug(tot);
  //  for(int i = 0; i < tot; i ++ )cout<<ans[i]<<' ';
   // puts("");
    ans[tot++] = S;
    for(int j = tot - 2; j >= 0; j--)ansp.pb({ans[j+1], ans[j]});
    // printf("%d %d\n", ans[j+1], ans[j]);
}
int main(){
    scanf("%d %d", &n, &k);
    bool ok = true;
    for(int i = 1; i <= k; i ++ ){
        scanf("%d", a + i);
        have[a[i]] = 1;
    }
    for(int i = 1; i <= k; i ++ ){
        scanf("%d", b + i);
        if(have[b[i]]) have[b[i]] = 0;
        else r[++n2] = b[i];
    }
    for(int i = 1; i <= k; i ++ ){
        if(have[a[i]]) l[++n1] = a[i], have[a[i]] = 0;
        else have[a[i]] = 1;
    }
    //floyd
    for(int i = 1; i <= n; i ++ ) scanf("%s", s[i]+1);
    for(int i = 1; i <= n; i ++ ) for(int j = 1; j <= n; j ++ ) s[i][j] -= '0', f[i][j] = s[i][j];
    for(int k = 1; k <= n; k ++ )for(int i = 1; i <= n; i ++ ) for(int j = 1; j <= n; j ++ ){
        f[i][j] |= f[i][k]&f[k][j];
    }
    
    //debug
    //cout<<"debug:f";
    //for(int i = 1; i <= n; i ++) for(int j = 1; j <= n; j ++ ) cout<<f[i][j]<<" \n"[j==n];
    //puts("");
    /* cout<<"n1:";
    for(int i = 1; i <= n1; i ++ ) cout<<l[i]<<' ';
    puts(" ");
    cout<<"n2:";
    for(int i = 1; i <= n2; i ++ ) cout<<r[i]<<' ';
    puts(""); */
    //
    int mx = 0;
    for(int i = 1; i <= n1; i ++ ){
        memset(st,0,sizeof st);
        if(find(l[i])) mx++;
    }
   // debug(n1);
    if(mx != n1){
        puts("NO");
        return 0;
    }
    puts("YES");
    memset(have,0,sizeof 0);
    for(int i = 1; i <= k; i ++ ) have[a[i]] = 1;
    for(int i = 1; i <= n2; i ++ ){
        S = match[r[i]], T = r[i];
        bfs(); trace();
      //  cout<<"trace1"<<endl;
        have[r[i]] = 1;
        have[S] = 0;
    }
    printf("%d\n", ansp.size());
    for(int i = 0; i < ansp.size(); i ++ ) printf("%d %d\n", ansp[i].first, ansp[i].second);
    return 0;
}