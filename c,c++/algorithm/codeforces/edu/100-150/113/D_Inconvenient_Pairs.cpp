#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <iostream>
#define debug(a) cout<<#a<<":"<<a<<endl
#define fi first
#define se second
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
#define sz(a) (int)a.size()
#define pb push_back 
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
const int N = 3e5+10;
const int M =  1e6+10;
int idx, idy;
int dx[N], dy[N];
vector<int> posx[M], posy[M];
int linex[N], liney[N];
void solve(){
    idx = idy = 0;
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    unordered_map<int,int> x, y;
    For(i,1,n){
        int xx; scanf("%d", &xx);
        linex[i] = xx;
        x[xx] = 0; posx[xx].clear();
    }
    For(i,1,m){
        int yy; scanf("%d", &yy);liney[i] = yy;
        y[yy] = 0; posy[yy].clear();
    }
    ll ans = 1LL*k*(k-1)/2, sub = 0;
    int toty = 0;
    int cnt = 0;
    For(i,1,k){
        int xx, yy; scanf("%d %d", &xx, &yy);
        if(x.count(xx) && y.count(yy)){
            sub += k - 1;
            cnt++;
            //交
        }else if(x.count(xx)){
            //shu
            x[xx]++;
            dx[ ++idx ] = yy;
            posx[xx].push_back(yy);
        }else {
            //heng
            y[yy]++;
            dy[++idy] = xx;
            toty ++;
            posy[yy].pb(xx);
        }
    }
    sub -= 1LL*cnt*(cnt-1)/2;
    sort(dx + 1, dx + 1 + idx);
    sort(dy + 1, dy + 1 + idy);
    //debug(ans);
    //debug(sub);
    ll sum1 = 0;
    for(auto key: x){
        if(key.se == 0) continue;
        sub += 1LL*key.se*(key.se-1)/2;
        sub += 1LL*key.se*toty;
        sort(all(posx[key.fi]));
      //  cout<<"line: "<<key.fi<<", sub:"<<sub<<endl;
        for(auto yy: posx[key.fi]){
            int up = lower_bound(liney +1, liney + 1 + m,yy) - liney;
            int down = up - 1;
            int add2 = lower_bound(dx + 1, dx + 1 + idx, liney[up]) - dx;
            if(up == m + 1 ||  add2 == idx + 1) add2 = 0;
            else {
                int up2 = lower_bound(all(posx[key.fi]), liney[up]) - posx[key.fi].begin();
                add2 = idx - add2 + 1 - (sz(posx[key.fi])  - up2);
            }
            int add1 = lower_bound(dx +1, dx+1+idx, liney[down]) - dx;
           // if(dx[add1] > liney[down]) add1--;
           // else {
            {
                add1--;
                int down2 = lower_bound(all(posx[key.fi]), liney[down]) - posx[key.fi].begin();
                //if(posx[key.fi][down2] == yy) add1 -= (down2 - 1 + 1);
                //else add1 -= down2 + 1;
                add1 -= down2;
            }
           // printf("add1 = %d, add2 = %d\n", add1, add2);
            sum1 += add1 + add2;
        }
    }
    //debug(sub);
    ll sum2 = 0;
    for(auto key: y){
        if(key.se == 0) continue;
      //  debug(key.fi);
     //   debug(sub);
        sub += 1LL*key.se*(key.se-1)/2;
         sort(all(posy[key.fi]));
        for(auto xx: posy[key.fi]){
            int up = lower_bound(linex +1, linex + 1 + n,xx) - linex;
            int down = up - 1;
            int add2 = lower_bound(dy + 1, dy + 1 + idy, linex[up]) - dy;
         //   debug(add2);
            //debug(up);
            if(up == n + 1 || add2 == idy + 1) add2 = 0;
            else {
                int up2 = lower_bound(all(posy[key.fi]), linex[up]) - posy[key.fi].begin();
               // debug(up2);
                add2 = idy - add2 + 1;
                //debug(add2);
                add2 = add2 - (sz(posy[key.fi])  - up2);
            }
            int add1 = lower_bound(dy +1, dy+1+idy, linex[down]) - dy;
          //  if(dy[add1] > linex[down]) add1--;
            {
               // cout<<"down: "<<down<<endl;
                add1--;
                int down2 = lower_bound(all(posy[key.fi]), linex[down]) - posy[key.fi].begin();
                add1 -= down2;
            }
            //printf("add1 = %d, add2 = %d\n", add1, add2);
           // sub += add1 + add2;
            sum2 += add1 + add2;
        } 
    }
   // debug(sub);
    ans -= sub + sum2/2 + sum1/2;
    printf("%lld\n", ans);
}
int main(){
    int tt; scanf("%d", &tt);
    while(tt--) solve();
    return 0;
}