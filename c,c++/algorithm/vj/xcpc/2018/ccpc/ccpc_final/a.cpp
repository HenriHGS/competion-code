#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define mp make_pair
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 1e5+10;
typedef pair<int,int> PII;
void sol(){
    int n, m; scanf("%d %d", &n, &m);
    vector<PII> v(n);
    fori(i,0,n) scanf("%d", &v[i].fi);
    fori(i,0,n) scanf("%d", &v[i].se);
    sort(v.begin(),v.end());
    int ans = 0;
    fori(i,0,n){
        if(m >= v[i].se){
            m -= v[i].se;
            ans++;
        }else break;
    }
    printf("%d\n", ans);
}
int cas;
int main(){
    int tt; scanf("%d", &tt);
    while(tt--){
        printf("Case %d: ",++cas);
        sol();
    }
    return 0;
}