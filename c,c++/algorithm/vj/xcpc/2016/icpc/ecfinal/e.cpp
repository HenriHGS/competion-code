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

int n;
void sol(){
    #define ldb long double
    scanf("%d", &n);
    vector<ldb> v;
    For(i,1,n){
        ldb a, b; scanf("%llf:%llf",&a,&b);
        v.pb((a/(a+b)));
    }
    int ans = 0;
    ldb sum = 0;
    sort(v.begin(),v.end());
    fori(i,0,sz(v)){
        sum += v[i];
        if(sum < 1.0)ans++;
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