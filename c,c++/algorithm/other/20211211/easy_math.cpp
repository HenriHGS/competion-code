#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
#define sz(a) (int)a.size()
#define ALL(a) a.begin(), a.end()
#define mst(x,a) memset(x,a,sizeof(x))
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define db double
#define endl '\n' 
#define debug(a) cout << #a << ": " << a << endl
using namespace std;
typedef long long LL;
typedef long long ll;
typedef unsigned long long ULL;
const int maxn = 100000 + 6;

int k[maxn], b[maxn];
int n,m,p;
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tt; 
    cin>>tt;
    auto check = [&](ll x){
        int cnt = 0;
        for(int i = 1; i <= n; i ++ ){
            ll y = k[i]*x + b[i];
            if(y >= m) cnt++;
            if(cnt >= p) return true;
        }
        return false;
    };
    while(tt--){
        cin>>n>>p>>m;        
        For(i,1,n) cin>>k[i]>>b[i];
        ll L = 1, R = 1e14, ans = 1;
        while(L <= R){
            ll mid = (L + R)>>1;
            if(check(mid)) ans = mid, R = mid - 1;
            else L = mid + 1;
        }
        cout<<ans<<endl;
    }
    return 0;
}