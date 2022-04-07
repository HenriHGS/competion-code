
/*
字符hash
&&思维
加法的特征
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <queue>
#include <string>
#include <cmath>
#include <cstring>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
#define sz(a) (int)a.size()
#define ALL(a) a.begin(), a.end()
#define mst(x,a) memset(x,a,sizeof(x))
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define db double
#define endl '\n' 
#define AC return 0
#define debug(a) cout << #a << ": " << a << endl
using namespace std;
typedef long long LL;
typedef long long ll;
typedef unsigned long long ULL;
const LL INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
typedef pair<int,int>pa;
typedef pair<ll,ll>pai;
typedef pair<db,db> pdd;
const db eps = 1e-6;
const db pi = acos(-1.0);

template<typename T1, typename T2> void ckmin(T1 &a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> void ckmax(T1 &a, T2 b) { if (a < b) a = b; }
int read() {
    int x = 0, f = 0; char ch = getchar();
    while (!isdigit(ch)) f |= ch == '-', ch = getchar();
    while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
    return f ? -x : x;
}
template<typename T> void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x >= 10) print(x / 10);
    putchar(x % 10 + '0');
}
template<typename T> void print(T x, char let) {
    print(x), putchar(let);
}
template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

const int maxn=1e6+10;
struct bign
{
    int d[maxn],len;
    void clean(){while(len>1&&!d[len-1])len--;}//清除前导0.
    //
    bign(){mst(d,0);len=1;}
    bign(int num){*this=num;}
    bign(char*num){*this=num;}
    bign operator = (const char *num){
        mst(d,0);len=strlen(num);
        for(int i=0; i<len; i++)d[i]=num[len-1-i]-'0';
        clean();
        return *this;
    }
    bign operator = (int num){
        char s[20];sprintf(s,"%d",num);
        *this=s;
        return *this;
    }
    //
    bign operator + (const bign &b){
        bign c= *this; int i;
        for(i=0; i<b.len; i++){
            c.d[i]+=b.d[i];
            if(c.d[i]>9)c.d[i]%=10,c.d[i+1]++;
        }
        while(c.d[i]>9)c.d[i++]%=10,c.d[i]++;
        c.len=max(len,b.len);
        if(c.d[i]&&c.len<=i)c.len=i+1;
        return c;
    }
    bign operator - (const bign&b){
        bign c=*this; int i;
        for(i=0; i<b.len; i++){
            c.d[i]-=b.d[i];
            if(c.d[i]<0)c.d[i]+=10,c.d[i+1]--;
        }
        while(c.d[i]<0)c.d[i++]+=10,c.d[i]--;
        c.clean();
        return c;
    }
    bign operator * (const bign&b)const{
        int i,j; bign c; c.len=len+b.len;
        for(j=0; j<b.len; j++){
            for(i=0; i<len; i++)c.d[i+j]+=d[i]*b.d[j];
        }
        for(i=0; i<c.len-1; i++)c.d[i+1]+=c.d[i]/10,c.d[i]%=10;
        c.clean();
        return c;
    }
    bign operator /(const bign&b){
        int i,j;
        bign c=*this,a=0;
        for(i=len-1; i>=0; i--){
            a=a*10+d[i];
            for(j=0; j<10; j++)if(a<b*(j+1))break;
            c.d[i]=j;
            a=a-b*j;
        }
        c.clean();
        return c;
    }
    bign operator %(const bign&b){
        int i,j;
        bign a=0;
        for(i=len-1; i>=0; i--){
            a=a*10+d[i];
            for(j=0; j<10; j++)if(a<b*(j+1))break;
            a=a-b*j;
        }
        return a;
    }
    bign operator +=(const bign&b){
        *this=*this+b;
        return *this;
    }
    bign operator -=(const bign&b){
        *this=*this-b;
        return *this;
    }
    bign operator *=(const bign&b){
        *this=*this*b;
        return *this;
    }
    bign operator /=(const bign&b){
        *this=*this/b;
        return *this;
    }
    bool operator <(const bign&b)const{
        if(len!=b.len)return len<b.len;
        for(int i=len-1; i>=0; i--){
            if(d[i]!=b.d[i])return d[i]<b.d[i];
        }
        return false;
    }
    bool operator >(const bign&b)const{return b<*this;}
    bool operator <=(const bign&b)const{return !(b<*this);}
    bool operator >= (const bign&b)const{return !(*this<b);}
    bool operator != (const bign&b)const{return b<*this||*this<b;}
    bool operator ==(const bign&b)const{return !(b<*this)&&!(b>*this);}
    //
    string str() const{
        char s[maxn]={};
        for(int i=0; i<len; i++)s[len-1-i]=d[i]+'0';
        return s;
    }
};
istream& operator>>(istream& in,bign&x){
    string s;
    in>>s;
    x=s.c_str();
    return in;
}
ostream& operator<<(ostream& out, bign&x){
    out<<x.str();
    return out;
}
char str[maxn];
const ULL q = 10, mod[2] = {(ULL)1e9+7, (ULL)1e9+3};
ULL ha[2][maxn], p[2][maxn];
ULL mul(ULL a, ULL b, ULL mod){
    ULL res = a*b%mod;
    return res;
}
ULL add(ULL a, ULL b, ULL mod){
    ULL res = (a+b)%mod;
    return res;
}
ULL get(int  l, int r, ULL ha[], ULL p[], ULL mod){
    ULL res = ha[r];
    res = (res - (ha[l-1]*p[r-l+1])%mod + mod)%mod;
    return res;
}
int n;
bool check(int ae, int be){
    int len[4] = {0,ae,be-ae,n-be};
    int st = 1, ed;
    For(i,1,3){
        if(len[i] == 0) return false;
        if(len[i]>=2 && str[st] == '0')return false;
        st += len[i];
    }
    ULL a[4][2];
    st = 1, ed = 0;
    For(i,1,3){
        ed += len[i];
        fori(j,0,2){
            a[i][j] = get(st,ed,ha[j],p[j],mod[j]);
        }
        st += len[i];
    }
    fori(j,0,2){
        if( (a[1][j]+a[2][j])%mod[j] != a[3][j] )return false;
    }
  //  For(i,1,3)debug(len[i]);
    for(int i = 1; i <= n; i ++ ){
        printf("%c", str[i]);
        if(i == len[1])printf("+");
        if(i == len[2]+len[1])printf("=");
    }
    return true;
}
int sol(){
    scanf("%s", str+1);
    p[1][0] = p[0][0] = 1;
    n = strlen(str+1);
    for(int i = 1; i <= n; i ++ ){
        fori(j,0,2){
            p[j][i] = mul(p[j][i-1], q, mod[j]);
            ha[j][i] = add(mul(ha[j][i-1],q,mod[j]), str[i]-'0',mod[j]);
        }
        /*
        p[0][i] = mul(p1[i-1],q, mod1);
        p[1][i] = mul(p2[i-1],q, mod2);
        ha1[i] = add(mul(ha1[i-1],q,mod1), str[i]-'0',mod1);
        ha2[i] = add(mul(ha2[i-1],q,mod2), str[i]-'0',mod2);
        */
    }
    For(len,1,n/2){
        //lena+1 == c
        if(check(len,n-len-1))AC;
        //lena == c
        if(check(len,n-len))AC;
        //lenb+1 == c 
        if(check(n-2*len-1,n-len-1))AC;
        //lenb == c
        if(check(n-2*len,n-len))AC;
    }
}
int main() {
   // ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    sol();
    return 0;
}