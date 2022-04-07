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
#include<iomanip> //精度设置
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
const db eps = 1e-10;
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
const int N = 11;
const int M = 110;
db  p[M][N];
db  r[N];
db  modif[M];//modi
int y, c, q;
const db neg = -1.0;
void init(){
    For(i,1,c)For(j,1,y)p[i][j] = -1.0, r[j] = -1.0, modif[i] = -1.0;
    For(i,1,y-1){
        cin>>r[i];
    }
    r[y] = -1.0;
    For(j,1,y){
        For(i,1,c)cin>>p[i][j];
    }
}
bool check(db now){
    return !(fabs(neg - now) < eps);
}
void cal(){
    For(i,1,c)For(j,1,y){
        db& pp = p[i][j];
        db& mm = modif[i];
        db& rr = r[j];
        //p m r(pn)
        if(check(pp) && check(mm) && check(rr) && j + 1 <= y){
            db& pn = p[i][j+1];
            if(!check(pn)) pn = pp*mm*rr;
        }
        //p m pn (r)
        if(check(pp) && check(mm)&& j + 1 <= y){
            db& pn = p[i][j+1];
            if(check(pn) && !check(rr)) rr = pn/pp/mm;
        }
        // p*(m)*r = pn;
        if(check(pp) && check(rr) && j + 1 <= y){
            db& pn = p[i][j+1];
            if(check(pn) && !check(mm)) mm = pn/pp/rr;
        }
        // (p)*m*r = pn;
        if(check(mm) && check(rr) && j + 1 <= y){
            db& pn = p[i][j+1];
            if(check(pn) && !check(pp)) pp = pn/mm/rr;
        }

        //preyear
         if(check(pp) && check(mm)&& j - 1 >= 1){
            db& pn = p[i][j-1];
            db& rn = r[j-1];
            if(!check(pn) && check(rn)) pn = pp/mm/rn;
        }
        //pn*m*(rn) = p;
        if(check(pp) && check(mm)&& j - 1 >= 1){
            db& pn = p[i][j-1];
            db& rn = r[j-1];
            if(check(pn) && !check(rn)) rn = pp/pn/mm;
        }
        // pn*(m)*rn = p;
        if(check(pp) && j - 1 >= 1){
            db& pn = p[i][j-1];
            db& rn = r[j-1];
            if(check(pn) && !check(mm) && check(rn)) mm = pp/pn/rn;
        }
        // pn*m*rn = (p);
        if(check(mm)&& j - 1 >= 1){
            db& pn = p[i][j-1];
            db& rn = r[j-1];
            if(check(pn) && !check(pp) && check(rn)) pp = pn*mm*rn;
        }
        /*
        if( j == 3){
            cout<<"debug: "<<pp<<' '<<rr<<' '<<mm<<endl;
        }
        */
    }
}
void sol(){
    cin>>y>>c>>q;
    init();
    cout<<fixed<<setprecision(4);
    For(cas,1,y*c*2 + c)cal();
    /*
    For(i,1,c)For(j,1,y){
        cout<<p[i][j]<<' ';
        if(j == y) cout<<endl;
    }
    cout<<"r :"<<endl;
    For(i,1,y-1)cout<<r[i]<<' ';
    cout<<endl;
     cout<<"modif :"<<endl;
    For(i,1,c)cout<<modif[i]<<' ';
    cout<<endl;
    */
    while(q--){
        int a, b;
        cin>>a>>b;
        if(!check(p[a][b]))cout<<"-1.0"<<endl;
        else cout<<p[a][b]<<endl;//精度输出
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    sol();
    /*;
    db now;
    cin>>now;
    cout<<(fabs(neg - now) < eps)<<endl;
    */
    return 0;
}