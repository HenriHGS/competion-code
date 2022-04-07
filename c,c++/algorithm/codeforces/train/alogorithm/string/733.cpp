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

struct Tri{
    int e[3];
    bool operator < (const Tri& x) const {
        if(e[0] != x.e[0]) return e[0] < x.e[0];
        if(e[1] != x.e[1]) return e[1] < x.e[1];
        return e[2] < x.e[2];
    }
} ston[maxn];
map<pa,pa> ma;
void sol(){
    int n;
    int ans = 1, mx = 0;
    vector<int>id(2);
    cin>>n;
    For(i,1,n){
        int a, b, c;
        cin>>a>>b>>c;
        ston[i] = {a,b,c};
        int mi = min(a,min(b,c));
        if(mx < mi){
            mx = mi;
            id[0] = i;
        }
       // fori(k,0,3)cout<<ston[i].e[k]<<' ';
        //cout<<endl;
    }
    // if(ans == 1)cout<<1<<endl<<id[0]<<endl;
  //  else cout<<2<<endl<<id[0]<<' '<<id[1]<<endl;
    For(i,1,n){
        fori(k,0,3){
            int c = ston[i].e[k];
            int a = ston[i].e[(k+1)%3];
            int b = ston[i].e[(k+2)%3];
            if(a > b) swap(a,b);
            if(ma.count(mp(a,b))){
                c += ma[mp(a,b)].fi;
                int mi = min(a,min(b,c));
                if(mi > mx) {
                    mx = mi;
                    ans = 2;
                    id[0] = i, id[1] = ma[mp(a,b)].se;
                }
            }
        }
        fori(k,0,3){
            int c = ston[i].e[k];
            int a = ston[i].e[(k+1)%3];
            int b = ston[i].e[(k+2)%3];
            if(a > b) swap(a,b);
            auto squar = mp(a,b);
            if(ma.count(squar)){
                if(c > ma[squar].fi) {
                   ma[squar] = mp(c,i);
                }
            }else ma[squar] = mp(c,i);
        }
    }
    if(ans == 1)cout<<1<<endl<<id[0]<<endl;
    else cout<<2<<endl<<id[0]<<' '<<id[1]<<endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    sol();
    return 0;
}