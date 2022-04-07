#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cctype>
#include <vector>
#define mp make_pair
#define debug(a) cout<<#a<<":"<<a<<endl
#define mst(x,a) memset(x,a,sizeof x)
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ ) 
using namespace std;
typedef long long ll;
const int maxn = 2010/8*2;
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
const int up = 1e16;
const int upbit = 16;
ll cToInt(const char * s, int l, int r){
    ll res = 0;
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
    bign operator + (const bign&b){
        bign c = *this; int i;
        for(i = 0; i < b.len; i ++ ){
            c.d[i] += b.d[i];
            if(c.d[i] >= up) c.d[i] %= up, c.d[i+1]++;
        }
        while(c.d[i] >= up) c.d[i++] %= up, c.d[i]++;
        c.len = max(len,b.len);
        if(c.d[i] && c.len <= i)c.len = i + 1;
        return c;
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
const int maxx = 2010;
const int N = 5010;
struct node{
    char type[20];
    int x;
} mb[N];
int n;
bign dp[N];
bign q2[N];
typedef pair<int,int> PII;
PII pre[N];
int main(){
    //bign x = 100;
    //x.output();
    n = read();
    q2[0] = 1;
    fori(i,1,maxx) q2[i] = q2[i-1]*2;
    //debug(q2[maxx-1].len);
    For(i,1,n){
        scanf("%s %d", mb[i].type, &mb[i].x);
        int tp = (strcmp(mb[i].type,"win") == 0) + 1;
        dp[i] = dp[i-1];
        int prepos = pre[mb[i].x].first;
        int pretp = pre[mb[i].x].second;
        int x = mb[i].x;
        if(pretp){
            if(tp == 1 && pretp == 2){
                ckmax(dp[i], dp[prepos-1] + q2[x]);
            }
        }
        //dp[i].output();
        pre[mb[i].x] = mp(i,tp);
    }
    dp[n].output();
    return 0;
}