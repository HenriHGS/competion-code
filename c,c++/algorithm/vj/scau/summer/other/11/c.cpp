#include <cstdio>
#include <vector>
using namespace std;

#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
#define sz(s)
#define pb push_back

const int N = 1e5+10;
vector<int>fa[N];
int age[N], vis[N], pos[N], chg[N];
int mi = 110;
int n, m, q;
void dfs(int x){
  //  printf("%d ", x);
    if(vis[x]) return;
    vis[x] = 1;
    for(auto j: fa[x]){
        mi = min(age[chg[j]],mi);
        dfs(j);
    }
}
int main(){
    scanf("%d%d%d",&n,&m,&q);
    For(i,1,n)scanf("%d", age+i), pos[i] = i;
    For(i,1,m){
        int x, y;
        scanf("%d%d",&x,&y);
        fa[y].pb(x);
    }
    while(q--){
        int x,y;
        char s[10];
        scanf("%s", s);
        if(s[0] == 'T'){
            scanf("%d%d", &x, &y);
            swap(pos[x],pos[y]);
        }
        else {
            scanf("%d", &x);
            For(i,1,n) vis[i] = 0, chg[pos[i]] = i;
            mi = 110;
            //("trace: ");
            dfs(pos[x]);
           // puts("");
            if(mi == 110)printf("*\n");
            else printf("%d\n",mi);
        }
    }
    return 0;
}
/*
7 8 9
21 33 33 18 42 22 26
1 2
1 3
2 5
3 5
3 6
4 6
4 7
6 7
P 7
T 4 2
P 7
P 5
T 1 4
P 7
T 4 7
P 2
P 6
*/