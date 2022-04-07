#include <cstring>
#include <string>
#include <iostream>
#define debug(a) cout<<#a<<":"<<a<<endl
#define sz(a) (int)a.size()
#define mst(x,a) memset(x,a,sizeof(x))
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
using namespace std;
typedef long long LL;
const int N = 3e5+10;
const int q[2] = {131,13331};
const int mod[2] = {(int)(1e9+9), (int)(1e9+7)};
LL p[2][N];
void init(){
    fori(k,0,2){
        p[k][0] = 1; 
        fori(i,1,N){
            p[k][i] = (p[k][i-1]*q[k])% mod[k]; 
        }
    }
}
LL h1[2][N], h2[2][N]; 
int get1(int l, int r, int k){
    return (h1[k][r] + mod[k] - h1[k][l-1]*p[k][r-l+1]%mod[k]) % mod[k];
}
int get2(int l, int r, int k){
    return (h2[k][r] + mod[k] - h2[k][l-1]*p[k][r-l+1]% mod[k]) % mod[k];
}
char str[N], s[N];
int pre[N], suf[N], f[N];
int min_pos[N];
void sol(){
    cin>>str+1;
    int n = strlen(str+1);
    int nn = n;
    n = 0;
    s[++n] = '#';
    For(i,1,nn){
        s[++n] = str[i];
        s[++n] = '#';
    }
    init();
    //debug(n);
    For(i,1,n){
        fori(k,0,2){
            h1[k][i] = (h1[k][i-1] * q[k] % mod[k] + s[i])%mod[k];
            h2[k][i] = (h2[k][i-1] * q[k] % mod[k] + s[n - i + 1]) % mod[k];
        }
    }
    // check 
    auto check = [&](int len, int x){
        bool ok = true;
        //fori(k,0,2) ok &= get1(x - len + 1, x + len - 1,k) == get2(n - x - len + 2, n - x + len,k);
        fori(k,0,2) ok &= get1(x, x + len - 1,k) == get2(n - x + 1, n - x + len,k);
        return ok;
    };
    // find position of x's max huiwen
    auto find = [&](int x){
        int L, R, ans;
        L = 1, R = min(x, n - x + 1);
        while(L <= R){
            int mid = L + R >> 1;
            if(check(mid,x)) ans = mid, L = mid+1;
            else R = mid - 1;
        }
        return ans;
    };
    mst(min_pos,0x3f);
    For(i,1,n){
        f[i] = find(i);
        min_pos[i + f[i] - 1] = min(min_pos[i+f[i]-1],i);
    }
    s[n+1] = '\0';
    /*
    debug(s+1);
    For(i,1,n)cout<<f[i]<<' ';
    cout<<endl;
    For(i,1,n)cout<<min_pos[i]<<' ';
    cout<<endl;
    
    For(i,1,n)cout<<min_pos[i]<<' ';
    cout<<endl;
    */
    for(int i = n - 1; i >= 1; i --)
        min_pos[i] = min(min_pos[i],min_pos[i+1]);
    int ans = 0;
    for(int i = 2; i <= n - 1; i ++){
        int tmp = min_pos[i-f[i] + 1];
        if(i - f[i] + 1 == 1) tmp = min_pos[2];
        ans = max(ans, i - tmp << 1);
      //  debug(ans);
    }
    cout<<(ans>>1)<<endl;
    /*
    For(len,1,n){
        for(int i = 1; i + len - 1 <= n; i += len){
            int j = i + len - 1;
            bool ok = true;
            fori(k,0,2){
                ok &= get1(i,j,k) == get2(n-j+1,n-i+1,k);
                if(len == 2){
                    debug(get1(i,j,k));
                    debug(get2(n-j+1,n-i+1,k));
                }
            }
            if(ok) pre[j] = max(pre[j],len), suf[i] = max(suf[i],len);
        }
    }
    
    int ans = 0;
    For(i,1,n-1){
        ans = max(ans,pre[i] + suf[i]);
    }
    cout<<ans<<endl;
    */
}

int main(){
    ios::sync_with_stdio(0);
    sol();
}