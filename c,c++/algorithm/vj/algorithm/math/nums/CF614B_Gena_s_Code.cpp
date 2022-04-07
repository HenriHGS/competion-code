#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cctype>
#include <vector>
#define debug(a) cout<<#a<<":"<<a<<endl
#define mst(x,a) memset(x,a,sizeof x)
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ ) 
using namespace std;
typedef long long ll;
const int maxn = 40;
int read(){
    char ch = getchar(); int f = 0, x = 0;
    while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
    while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    return f ? -x : x;
}
template<typename T1, typename T2> void ckmin(T1 &a, T2 b){
    if(a > b) a = b;
}
template<typename T1, typename T2> void ckmax(T1 &a, T2 b){
    if(a < b) a = b;
}
const int up = 1e8;
const int upbit = 8;
int cToInt(const char * s, int l, int r){
    int res = 0;
    for(int i = l; i <= r; i ++ ){
        res = res * 10 + s[i] - '0';
    }
    return res;
}
struct bign{
    ll d[maxn];
    int len;
    void clean() { while(len > 1 && !d[len-1]) len--;}
    bign(){mst(d,0); len = 1;}
    bign(int num){*this = num;}
    bign(char* num) {*this = num;}
    bign operator = (const char *num){
        mst(d,0); 
        int slen = strlen(num);
        len = (slen + upbit - 1) / upbit ;
        int r = slen - 1, l = slen;
        fori(i,0,len) {
            //r = min(r + up - 1,slen - 1);
            l = max(0,l - upbit);
            d[i] = cToInt(num,l,r); 
            //debug(d[i]);
            r -= upbit;
        }
        clean();
        return *this;
    }
    bign operator = (int num){
        char s[20]; sprintf(s, "%d", num);
        *this = s;
        return *this;
    }
    bign operator *(const bign&b) const{
        int i, j; bign c; c.len = len + b.len;
        for(j = 0; j < b.len; j ++ )
            for(i = 0; i < len; i ++ )c.d[i + j] += d[i]*b.d[j];
        for(i = 0; i < c.len - 1; i ++ ) c.d[i + 1] += c.d[i]/up, c.d[i] %= up;
        c.clean();
        return c;
    }
    bign operator *= (const bign&b){
        *this = *this*b;
        return *this;
    }
    bool operator < (const bign&b)const {
        if(len != b.len) return len < b.len;
        for(int i = len - 1; i >= 0; i -- ){
            if(d[i] != b.d[i]) return d[i] < b.d[i];
        }
        return false;
    }
    bool operator > (const bign&b) const {return b < *this;}
    bool operator <=(const bign&b) const {return !(b < *this);}
    bool operator >= (const bign&b) const {return !(*this < b);}
    bool operator != (const bign&b) const{return b < *this || *this < b;}
    bool operator == (const bign&b) const {return !(b < *this) && !(b > *this);}
    void output(){
        //for(int i = 0; i < len; i ++ ) putchar(d[len - 1 - i] + '0');
        printf("%I64d",d[len - 1]);
        for(int i = 1; i < len; i ++ ) printf("%.8I64d",d[len - 1 - i]);
    }
} ;
const  int N = 710;
int siz[N], n;
bign f[N][N], ans;
vector<int> e[N];
void dfs(int x, int fa){
    siz[x] = 1;
    f[x][1] = 1;
    for(auto v : e[x]){
        if(v == fa) continue;
        dfs(v,x);
        for(int i = siz[x]; i; i -- )
            for(int j = siz[v]; j >= 0; j --)
                ckmax(f[x][i + j], f[x][i]* f[v][j]);
        siz[x] += siz[v]; 
    }
    f[x][0] = siz[x];
    for(int i = 1; i <= siz[x]; i ++ ) ckmax(f[x][0], f[x][i]*i);
}
int main(){
    //bign x = 100;
    //x.output();
     n = read();
    For(i,1,n-1) {
        int a = read(), b = read();
        e[a].push_back(b);
        e[b].push_back(a);
    }
    dfs(1,-1);
    f[1][0].output(); 
    return 0;
}