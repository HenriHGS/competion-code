#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define sz(a) a.size()
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) For(i,x,y-1)
#define pb push_back

const int N = 5e4+10;
int siz[N];
int n;
//vector<int>e[N],v[N];
int h[N], e[N*2], idx, ne[N*2];
void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
int fa[N], ans[N], tot;
int ans_mx = 1e9;
int dfs(int x, int f){
    siz[x] = 1;
    fa[x] = f;
    int sum = 0, mx = 0;
    //fori(i,0,sz(e[x])){//for(int j: e[x]){
    for(int i = h[x]; ~i; i = ne[i]){    
        int j = e[i];
        if(j != f){
            siz[x] += dfs(j,x);
            sum += siz[j];
            mx = max(mx,siz[j]);
        }
    }
    mx = max(mx,n - sum - 1);
    if(mx < ans_mx){
        ans_mx = mx; tot = 0;
        ans[tot++] = x;
    }
    else if(mx == ans_mx){
        ans[tot++] = x;
    }
    //;v[mx].pb(x);
    return siz[x];
}
int main(){
    memset(h,-1,sizeof h);
    scanf("%d", &n);//cin>>n;
    For(i,1,n-1){
        int a,b;
        scanf("%d%d",&a,&b);//cin>>a>>b;
        add(a,b);//e[a].pb(b);
        add(b,a);//e[b].pb(a);
    }
    dfs(1,-1);
    /*
    For(i,1,n){
        if(sz(v[i]) == 0)continue;
        else {
          //  auto& vv = v[i];
            sort(v[i].begin(),v[i].end());
            fori(j,0,sz(v[i]))printf("%d ",v[i][j]);//cout<<v[i][j]<<' ';
            return 0;
        }
    }
    */
   sort(ans,ans+tot);
   fori(i,0,tot)printf("%d ",ans[i]);
    return 0;
}