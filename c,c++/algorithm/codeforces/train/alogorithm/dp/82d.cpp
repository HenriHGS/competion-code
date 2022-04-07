#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define mp make_pair
#define pb push_back
#define mst(x,a) memset(x,a,sizeof(x))
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
using namespace std;
typedef long long LL;
typedef pair<int,int>pa;
const int N = 1e3+10;
const int inf = 0x3f3f3f3f;
LL dp[N][N];
int w[N];
struct opt{
    int i, j, k;
} path[N][N];

int main(){
    int n;
    scanf("%d", &n);
    For(i,1,n)scanf("%d", w + i);//cin>>w[i];
    /*
    For(i,1,n) printf("%d ", w[i]);
    puts("");
    */
    w[++n] = 0;
    mst(dp,0x3f);
    dp[0][1] = 0;
    for(int i = 1; i <= n/2; i ++ ){
        int a = i<<1, b = a + 1;
        for(int j = 1; j < a; j ++ ){
            //chose a, b(j)
            if(dp[i-1][j] + (LL)max(w[a],w[b]) < dp[i][j]){
                dp[i][j] = dp[i-1][j] + (LL)max(w[a], w[b]);
                path[i][j] = (opt){a,b,j}; 
            }
            //chose a, j(b)
            if(dp[i-1][j] + (LL)max(w[a], w[j]) < dp[i][b]){
                dp[i][b] = dp[i-1][j] + (LL)max(w[a], w[j]);
                path[i][b] = (opt){a,j,j};
            }
            //chose b, j(a)
            if(dp[i-1][j] + (LL)max(w[b], w[j]) < dp[i][a]){
                dp[i][a] = dp[i-1][j] + (LL)max(w[b], w[j]);
                path[i][a] = (opt){b,j,j};
            }
        }
    }
    int tur = n/2, unsele = n;
    printf("%lld\n", dp[tur][unsele]);
    vector<pa>ans;
    while(path[tur][unsele].i){
        int a, b;
        a = path[tur][unsele].i;
        if(a > n) a = inf;
        b = path[tur][unsele].j;
        if(b > n) b = inf;
       // if(a > b) swap(a,b);
        ans.pb({a,b});
        //ans.pb({a,inf});
        unsele = path[tur][unsele].k;
        tur--;
    }
    reverse(ans.begin(),ans.end());
    for(int i = 0; i < ans.size(); i ++ ){
        if(ans[i].first != inf) printf("%d ", ans[i].first);
        if(ans[i].second != inf) printf("%d", ans[i].second);
        puts("");   
    }
    return 0;
}