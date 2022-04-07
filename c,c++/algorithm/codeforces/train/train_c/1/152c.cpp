#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long LL;
const int mod = 1e9+7;
int a[110][26];
char s[110];
void sol(){
    int n, m;
    cin>>n>>m;
    for(int i = 1; i <= n; i ++ ){
        cin>>(s+1);
        for(int j = 1; j <= m;  j++ ){
            int ch = s[j] - 'A';
            a[j][ch]++;
        }
    }
    int ans = 1;
    for(int j = 1; j <= m; j ++ ){
        int cnt = 0;
        for(int i = 0; i < 26; i ++ ){
            if(a[j][i]) cnt++;
        }
        ans = (LL)ans*cnt%mod;
    }
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(0);
    sol();
    return 0;
}