#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#define pb push_back
#define sz(a) (int)a.size()
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
const int N = 3e5+10;
typedef long long ll;
ll a[N], b[N];
int n, k;
bool check(int x){
    int j = 1;
    For(i,1,x) b[i] = 0;
    int res = 1;
    For(i,1,n){
        if(a[i]/2 >= b[j]) b[j++] = a[i];
        if(j == x + 1){
            j = 1;
            res++;
        }
        if(res > k) return true;
    }
    return false;
}
void sol(){
    scanf("%d %d", &n, &k);
    For(i,1,n) scanf("%lld", &a[i]);
    sort(a + 1, a + 1 +n);
    int l = 1, r = n, ans = 0;
    while(l <= r){
        int mid = l + r >> 1;
        if(check(mid)) l = mid + 1, ans = max(ans,mid);
        else r = mid - 1;
    }
    printf("%d\n", ans);
}
int main(){
    int tt; scanf("%d", &tt);
    int cas = 0;
    while(tt--){
        printf("Case #%d: ", ++cas);
        sol();
    }
    return 0;
}