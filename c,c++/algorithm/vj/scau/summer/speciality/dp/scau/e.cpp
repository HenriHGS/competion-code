#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) For(i,x,y-1)

const int N = 3e5+10;
int dp[N][30];
char s[N];
int n, m;
bool limit = false;
vector<int>e[N];
int vis[N];
bool st[N];

int dfs(int x, int alp){
    if(limit) return 0;
    if(dp[x][alp] != -1) return dp[x][alp];
    dp[x][alp] = (alp == s[x]);
    st[x] = 1;
    int& res = dp[x][alp];
    for(auto j: e[x]){
        if(st[j]){
            limit = 1;
            return 0;
        }
        res = max(res,(alp == s[x]) + dfs(j,alp));//res = max(res,dfs(j,k) + add);
    }
    st[x] = 0;
    return res;
}

int main(){
    memset(dp,-1,sizeof dp);
    scanf("%d%d",&n,&m);
    scanf("%s", s + 1);
    For(i,1,m){
        int a, b;
        scanf("%d%d",&a,&b);
        if(a == b) limit = true;
        else e[a].push_back(b);
    }
    if(limit){
        printf("-1\n");
        return 0;
    }
    For(i,1,n)s[i] -= 'a';
    int ans = 0;
    fori(j,0,26)For(i,1,n){
        dfs(i,j);
        ans = max(ans,dp[i][j]);
        /*
        if(dp[i][j] == 7){
            printf("char:%c node:%d\n",(char)(j+'a'),i);
        }
        */
        if(limit){
            printf("-1\n");
            return 0;
        }
    }
    printf("%d\n", ans);
    return 0;
}