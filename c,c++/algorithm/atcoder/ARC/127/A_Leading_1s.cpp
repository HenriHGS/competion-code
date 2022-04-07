#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
#include <cmath>
#define debug(a) cout<<#a<<":"<<a<<endl
using namespace std;
const int N = 1e5+10;
typedef long long ll;
int cal(int x){
    string s = to_string(x);
    int n = s.size();
    int res = 0;
    for(int i = 0; i < n; i ++ ){
        if(s[i] != '1') return res;
        res ++;
    }
    return res;
}
ll sol(ll x){
    //ll x; cin>>x;
    string s = to_string(x);
    int n = s.size();
    s = " "+ s;
    //cout<<s<<endl;
    ll ans = 0;
   // for(int i = 1; i <= n; i ++ ) s[i] -= '0';
  // debug(x);
  // debug(s);
  // debug(n);
    for(int i =1; i <= n; i ++ ){
        int limit = (i == 1);
        for(int j = i; j <= n; j ++ ){
            if(!limit) {
                ll add = (j - i + 1);
                if(j + 1 <= n) add *= 9;
                if(j + 2 <= n) add *= (ll)pow(10,n - j - 1);
                ans += add;
            }else if(s[j] > '1'){
                if(j > i){
                    int up  = s[j] - '0';
                    for(int k = 0; k <= up; k ++ ){
                        ll add = (j - i);
                        if(k == 1){
                            add++;
                            if(j + 1 <= n) add *= 9;
                            if(j + 2 <= n) add *= (ll)pow(10,n - j - 1);
                            //ans += add;
                        }else if(k == up){
                            ll mul = 0;
                            if(j + 1 <= n) mul = stoll(s.substr(j+1));
                            mul++;
                            add *= mul;
                        }else {
                            add *= (ll)pow(10,n-j);
                        }
                        ans += add;
                      //  cout<<"add = "<<add<<endl;
                    }    
                }else {
                    ll add = 1;
                    if(j + 1 <= n) add *= 9;
                    if(j + 2 <= n) add *= (ll)pow(10,n - j - 1);
                    ans += add;
                }
                limit = 0;
            }else{
                if(s[j] == '1'){
                    if(j != 1)ans += 1ll*(j - i + 1 - 1)*ll(pow(10,n-j));//0
                    if(j == n) ans+=(j - i + 1);
                }else {
                    ll add = 0;
                    if(j + 1 <= n) add = stoll(s.substr(j+1));
                    add++;
                    ans += 1ll*(j - i + 1 - 1)*add;
                    break;
                }
            } 
        //    cout<<ans<<' ';
        }
      //  cout<<" i = "<< i << " "<< ans<<endl;
    }
 //   cout<<ans<<endl;
    return ans;
}
void bf(){
    int ans = 0;
    for(int i = 1; i <= 1000; i ++ ){
        ans += cal(i);
        if(ans != sol(i)) cout<<i<<" sol(i) = "<<sol(i)<<" "  << ans<<endl;
    }
}
int main(){
    bf();
     ll x; cin>>x;
    string s = to_string(x);
    int n = s.size();
    s = " "+ s;
    //cout<<s<<endl;
    ll ans = 0;
   // for(int i = 1; i <= n; i ++ ) s[i] -= '0';
  // debug(x);
  // debug(s);
  // debug(n);
    for(int i =1; i <= n; i ++ ){
        int limit = (i == 1);
        for(int j = i; j <= n; j ++ ){
            if(!limit) {
                ll add = (j - i + 1);
                if(j + 1 <= n) add *= 9;
                if(j + 2 <= n) add *= (ll)pow(10,n - j - 1);
                ans += add;
            }else if(s[j] > '1'){
                if(j > i){
                    int up  = s[j] - '0';
                    for(int k = 0; k <= up; k ++ ){
                        ll add = (j - i);
                        if(k == 1){
                            add++;
                            if(j + 1 <= n) add *= 9;
                            if(j + 2 <= n) add *= (ll)pow(10,n - j - 1);
                            //ans += add;
                        }else if(k == up){
                            ll mul = 0;
                            if(j + 1 <= n) mul = stoll(s.substr(j+1));
                            mul++;
                            add *= mul;
                        }else {
                            add *= (ll)pow(10,n-j);
                        }
                        ans += add;
                      //  cout<<"add = "<<add<<endl;
                    }    
                }else {
                    ll add = 1;
                    if(j + 1 <= n) add *= 9;
                    if(j + 2 <= n) add *= (ll)pow(10,n - j - 1);
                    ans += add;
                }
                limit = 0;
            }else{
                if(s[j] == '1'){
                    if(j != 1)ans += 1ll*(j - i + 1 - 1)*ll(pow(10,n-j));//0
                    if(j == n) ans+=(j - i + 1);
                }else {
                    ll add = 0;
                    if(j + 1 <= n) add = stoll(s.substr(j+1));
                    add++;
                    ans += 1ll*(j - i + 1 - 1)*add;
                    break;
                }
            } 
          //  cout<<ans<<' ';
        }
      //  cout<<" i = "<< i << " "<< ans<<endl;
    }
    cout<<ans<<endl; 
    return 0;
}
/*
12 sol(i) = 6 5
13 sol(i) = 7 6
14 sol(i) = 8 7
15 sol(i) = 9 8
16 sol(i) = 10 9
17 sol(i) = 11 10
18 sol(i) = 12 11
19 sol(i) = 13 12
112 sol(i) = 31 29
113 sol(i) = 33 31
114 sol(i) = 35 33
115 sol(i) = 37 35
116 sol(i) = 39 37
117 sol(i) = 41 39
118 sol(i) = 43 41
119 sol(i) = 45 43
0 3  i = 1 3
4  i = 2 4
4
*/