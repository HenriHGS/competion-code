#include <cstdio>
#include <cstring>
using namespace std;
const int N = 1e5+10, M = 4e5+10;
int e[M], ne[M], h[N], idx;
void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
int type;
int din[N], dout[N];
int n, m;

bool used[M];
int ans[M],cnt;
void dfs(int u){
    for(int i = h[u]; ~i; i = h[u]){
        h[u] = ne[i];
        if(used[i]) continue;
        
        int j = e[i];
        if(type==1)used[i^1] = 1;
        dfs(j);
        int t = i + 1;
        if(type == 1){
            t = i/2+1;
            if(i&1)t = -t;
        }
        ans[++cnt] = t;
    }
}
int main(){
    memset(h,-1,sizeof h);
    scanf("%d", &type);
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i ++ ){
        int a, b;
        scanf("%d %d", &a, &b);
        add(a,b);
        if(type == 1) add(b,a);
        din[b]++, dout[a]++;
    }
    bool ok1 = true, ok2 = true;
    for(int i = 1; i <= n; i ++ ){
        if(type == 1)ok1 &= (din[i] + dout[i])%2==0;
        else ok2 &= din[i] == dout[i];
    }
    if(!ok1||!ok2){
        puts("NO");
        return 0;
    }
    for(int i = 1; i <= n; i ++ ){
        if(h[i] != -1){
            dfs(i);
            break;
        }
    }
    if(cnt != m){
        puts("NO");
    }else {
        puts("YES");
        for(int i = cnt; i ; i -- ) printf("%d ", ans[i]);
    }
    return 0;
}