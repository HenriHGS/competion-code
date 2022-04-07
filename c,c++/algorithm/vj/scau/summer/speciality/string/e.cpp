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
#define eb emplace_back
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

const int maxn = 100000 + 6;
const int N = 2e5+10;
char s[N], str[N];
int n;
void init(){
    int k = 0;
    s[k++] = '$';
    s[k++] = '#';
    for(int i = 0; i < n; i  ++ )s[k++] = str[i], s[k++] = '#';
    s[k++] = '^';
    n = k;
}
int z[N];
void manacher(){
    int mid = 0, rr = 0;
    for(int i = 1; i < n; i ++ ){
        if(i < rr) z[i] = min(z[mid*2-i], rr-i);
        else z[i] = 1;
        while(s[i-z[i]] == s[i+z[i]]) z[i]++;
        if(i + z[i] > rr){
            rr = i + z[i];
            mid = i;
        }
    }
}
void sol(){
    //cin>>str;
    n = strlen(str);
    int len = n;
    /*
    fori(i,0,len){
        s[n++] = s[len - i - 1]; 
    }
    */
    //s[n] = '\0';
    init();
    manacher();
    int mi = len;
    //debug(mi);
    fori(i,0,len){
        int len1 = z[i*2+2] - 1;
        int r1 = len1+1>>1;
        int len2 = z[i*2+3] - 1;
     //   cout<<len1<<' '<<len2<<endl;
        int r2 = len2>>1;
      //  cout<<len1<<' '<<len2<<endl;
        if(i + r2 + 1 == len){
            mi = min(mi,i - r2 + 1);
        }
        if(i + r1  == len){
            mi = min(mi, i - r1 + 1);
        }
    }
    //cout<<mi<<endl;
    for(int i = 0; i < len; i ++ )cout<<str[i];
    for(int i = mi - 1; i >= 0; i -- )cout<<str[i];
    cout<<endl;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    while(cin>>str)sol();
   // int cnt = 4;
   // while(cnt-- && cin>>str)sol();
    return 0;
}
/*
aaaa
abba
amanaplanacanal
xyz
*/