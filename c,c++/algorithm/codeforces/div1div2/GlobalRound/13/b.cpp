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

const int maxn = 100000 + 5;
const int N = 1100;
int  vis[5][N];
int rk[N][5];
int generate(int k, int n){
    int res = 0;
    res = rand()%n+1;
    while(vis[k][res]){
        res = rand()%n+1;
    }
    vis[k][res] = 1;
    return res;
}
void table(int n){
    For(i,1,n)fori(k,0,5)vis[k][i] = 0;
    For(i,1,n){
        fori(k,0,5)rk[k][i] = generate(k,n);
    }
    int chp = -1;
    For(i,1,n){
        int sum = 0;
        fori(k,0,5) sum += rk[k][i];
        cout<<"i = "<<i<<" sum ="<<sum<<"    rk:";
        fori(k,0,5) cout<<rk[k][i]<<' ';
        cout<<endl;
    }
    For(i,1,n){
        bool ok = true;
        For(j,1,n){
            int cnt = 0;
            fori(k,0,5) cnt += rk[k][i] <= rk[k][j];
            ok &= (cnt >= 3);
        }
        if(ok){
            chp = i;
            cout<<"chp = "<<i<<endl;
            return;
        }
    }
}

void sol(){
    
}



int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    fori(i,10,20)table(i);
    /*
    int tt; cin>>tt;
    while(tt--)
        sol();
    */
    return 0;
}