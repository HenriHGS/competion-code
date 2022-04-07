#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
typedef long long ll;
const int mod = 1000000007;
//              000000000
int qpow(int a, int k, int p){
    int res = 1;
    while(k){
        if(k&1) res = (ll)a*res%p;
        a = (ll)a*a%p;
        k>>=1;
    }
    return res;
}
int main(){
    ios::sync_with_stdio(0);
    int tt;
    cin>>tt;
    while(tt--){
        int n;
        cin>>n;
        int ans = 1;
        int pre = 0;
        string s;
        cin>>s;
        int cnt = 1;
        for(int i = 0; i < s.size(); i ++ ){
            if(i && s[i] == s[i-1]){
                cnt++;
            }else {
                
                    if(pre == 0&&i){
                        if(cnt == 0) cnt = 1;
                        ans = (ll)ans*qpow(2,cnt-1,mod);
                        pre = 1;
                }cnt = 1;
            }
            
        }
        if(pre == 0){
                        if(cnt == 0) cnt = 1;
                        ans = (ll)ans*qpow(2,cnt-1,mod);
                        pre = 1;
                }
        cout<<ans<<endl;
    }
    return 0;
}

