#include <cstdio>
#include <cstring>
using namespace std;
#define For(i,x,y) for(int i =  (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
typedef long long ll;
const int N = 1e5+10;
char s[N];
const ll mod = 998244353;
ll pre[26], cnt[26], pos[26], sum[26];
int main(){
    int tt;
    scanf("%d", &tt);
    while(tt--){
        ll ans = 0;
        fori(i,0,26) pos[i] = sum[i] = cnt[i] = pre[i] = 0;
        scanf("%s", s+1);
        int n = strlen(s+1);
        For(i,1,n){
            int cur = s[i] - 'a';
            fori(j,0,26){
                if(j == cur){
                    //pre[j] = (pre[j] + (i - pos[cur] - 1) * (cnt[j]*cnt[j]%mod) % mod) % mod;
                    cnt[j] = (cnt[j] + 2*(pos[cur])%mod) % mod;
                    pre[j] = (pre[j] + cnt[j] + i) % mod;
                    pos[cur] = i;
                } ans = (ans +  pre[j])%mod;
            }
        }
        printf("%lld\n", ans);
    } 
    return 0;
}
/*
5
ababa
a
abcdefga
afidhehfhd
ggggggggggg
*/