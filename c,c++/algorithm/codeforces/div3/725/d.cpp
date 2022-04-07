#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
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
#define debug(a) cout << #a << ": " << a << endl
using namespace std;
typedef long long LL;
typedef long long ll;
typedef unsigned long long ULL;
const LL INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int mod = 1e9+7;
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

const int maxn = 100000 + 5;
bool st[maxn+1];
int primes[maxn+1], tot;
void sieve(){
    st[1] = st[0] = 1;
    for(int i = 2; i <maxn; i ++ ){
        if(!st[i]) primes[tot++] = i;
        for(int j = 0; primes[j] <= maxn/i; j ++ ){
            st[i*primes[j]] = 1;
            if(i % primes[j] == 0) break;
        }
    }
}
int divide(int x){
    int res = 0;
    for(int i = 0; primes[i] <= x/primes[i]; i ++ ){
        int pri = primes[i];
        while(x%pri==0){
            res++;
            x/=pri;
        }
    }
    if(x>1)res++;
    return res;
}
int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b,a%b);
}
void sol(){
    int a, b, k;
    a = read(), b = read(), k = read();//cin>>a>>b>>k;
    int cnt = divide(a);
    cnt += divide(b);
    if(cnt > k){
        if(k == 1){
            int d = gcd(a,b);
            if(a < b) swap(a,b);
            if(a == b) puts("NO");//cout<<"NO"<<'\n';//endl;
            else if(a==1||b==1)puts("YES");//endl;
            else if(a%b!=0)puts("NO");
            else puts("YES");
        }else puts("YES");//cout<<"YES"<<'\n';
    }else if(cnt == k) puts("YES");
    else puts("NO");
}



int main() {
    //ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tt = read();// cin>>tt;
    sieve();
    while(tt--)
        sol();
    return 0;
}