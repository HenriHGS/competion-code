#include <map>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
#define pb push_back
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
typedef long long ll;
const ll limit = 2e9;
int main(){
    int tt; cin>>tt;
    while(tt--){
       // map<vector<int>,int> ma;
        vector<int> a(3);
        fori(i,0,3) cin>>a[i];
        ll ans = limit;
        auto check = [&](int a, int b)->ll{
            int mi = -1;
            if(a%3 != b%3) return mi;
            mi = (max(b,a) - min(b,a)) + min(a,b);
            return mi;
        };
        fori(i,0,3) fori(j,0,3) if(i!= j && check(a[i],a[j])!= -1) ans = min(ans,check(a[i],a[j]));
        cout<<(ans == limit?-1:ans)<<endl;
        /* do{
            sort(a.begin(), a.end());
            if(ma.count(a)){
                ok = false;
                break;
            }
            if(a[1] == a[2]){
                ans += a[1];
                break;
            }
            ma[a] = 1;
            int k =  (a[1] - a[0])/3;
            ans += k;
            a[1] -= k, a[2] -= k;
            a[0] += 2*k;
            while(a[0] < a[1]){
                a[0] += 2;
                ans++;
                a[1] --; a[2] --;
            }
            if(a[1] == a[0]){
                ans += a[1];
                ok = true;
                break;
            }
        }while(1);
        if(ok)cout<<ans<<endl;
        else cout<<-1<<endl;
    } */
    }
    return 0;
}