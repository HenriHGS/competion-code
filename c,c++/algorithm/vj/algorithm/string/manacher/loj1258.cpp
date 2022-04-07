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
#define debug(a) cout << #a << ": " << a << " "
#define debugendl(a) cout << #a << ": " << a << endl
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

const int maxn = 2e6 + 6;

char str[maxn], s[maxn];
int z[maxn], n;

void init(){
    int k = 0;
    s[k++] = '$';
    s[k++] = '#';
    fori(i,0,n) s[k++] = str[i], s[k++] = '#';
    s[k++] = '^';
    n = k;
    fori(i,0,n)z[i] = 0;
}
void manacher(){
    int mid, rr = 0;
    fori(i,1,n){
        if(i < rr) z[i] = min(z[mid*2 - i], rr - i);
        else z[i] = 1;
        while(s[i-z[i]] == s[i + z[i]])z[i]++;
        if(i + z[i] > rr){
            rr = i + z[i];
            mid = i;
        }
    }
}
int cas;
void sol(){
    scanf("%s", str);
    n = strlen(str);
    int ans = n;
    int m = n;
    init();
    manacher();
    fori(i,0,m){
       // debug(z[i*2+2]);
       // debugendl(z[i*2+3]);
        int len1 = z[i*2+2]-1;
        int len2 = z[i*2+3]-1;
        int r1 = (len1+1)/2;
        int r2 = len2/2;
        if(i - r1+1+len1 == m){
            ans = min(ans,m-len1);
        }
        if(i-r2+1+len2 == m){
            ans = min(ans,m-len2);
        }
    }
    printf("Case %d: %d\n", ++cas, ans+m);
}
int main() {
    //ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tt;
    scanf("%d", &tt);
    while(tt--)sol();
    return 0;
}