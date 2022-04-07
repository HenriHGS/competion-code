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

const int maxn = 2e5 + 6;
int a[maxn];
int m, n;
struct Qury{
    int op;
    int x,p;
} q[maxn];
int suf[maxn];//x
int ans[maxn];
int in[maxn];
void sol(){
    cin>>n;
    For(i,1,n)cin>>a[i];
    cin>>m;
    For(i,1,m){
        cin>>q[i].op;
        if(q[i].op == 1){
            cin>>q[i].p>>q[i].x;
        }else cin>>q[i].x;
    }
    for(int i = 0; i <= m+1; i ++ ) suf[i] = -1;
    for(int i = m; i >= 1; i -- ){
        if(q[i].op == 1)suf[i] = suf[i+1];
        else suf[i] = q[i].x;
    }
   // cout<<"suf"<<endl;
    //For(i,1,m)cout<<suf[i]<<' ';
   // cout<<endl;
    set<pa> S2, S1,S3;
    For(i,1,n)S2.insert({a[i],i});
    int pre = -1;
    For(i,1,m){
        int x = suf[i];
        if(q[i].op == 2){
            //debug(x);debug(pre);
            if(x >= pre){
                S3.clear();
                while(!S2.empty() && S2.begin()->first <= x){
                    auto it = S2.begin();
                    auto p = *it;
                    in[it->second] = 1;
                    p.fi = 0;
                    S1.insert(p);
                    S2.erase(it);
                }
                pre = x;
            }else{//else 空操作其它的点{
                //查看那些有改变的点，
                set<pa>S4;
                for(auto pp: S3){
                    pa cur = pp;
                    auto it = S2.find(cur);
                    S2.erase(it);
                    if(cur.fi < x)cur.fi = x;
                    a[cur.se] = cur.fi;
                    S2.insert(cur);
                    S4.insert(cur); 
                }
                S3 = S4;
               // S3.clear();
            }
        }else {
            int pp = q[i].p;
            int x = q[i].x;
            if(in[pp]){
                auto it = S1.find({0,pp});
                auto po = *it;
                po.fi = x;
                S1.erase(it);
                in[pp] = 0;
                S2.insert(po);
                S3.insert(po);
                a[po.second] = x;
            }else {
                auto it = S2.find({a[pp],pp});
                pa pre_po = *it;
                pa po = {x,pp};
                S2.erase(it);
                if(!S3.empty()){
                    it = S3.find(pre_po);
                    if(it != S3.end())S3.erase(it);
                }
                S3.insert(po);
                a[po.second] = x;
                S2.insert(po);
            }
        }
    }
    for(auto x: S1){
        ans[x.se] = pre;
    }
    for(auto x: S2){
        ans[x.se] = x.fi;
    }
    for(int i = 1; i <= n; i ++ )cout<<ans[i]<<' ';
    cout<<endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    sol();
    /*
    set<int>s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    auto it = s.find(4);
    if(it == s.end())cout<<"isend"<<endl;
    it = s.find(0);
    if(it == s.end())cout<<"isend"<<endl;
    */
    return 0;
}
/*
hack
5
2 2 2 2 2
3
2 4
1 1 1
2 2
ans:2 4 4 4 4

hack2:
5
2 2 2 2 2
4
2 4
1 1 1
2 2
2 5
ans: 5 5 5 5 5

hack3:
5
2 2 2 2 2
5
2 4
1 1 1
1 1 6
2 2
2 5
ans: 6 5 5 5 5

hack4:
5
2 2 2 2 2
5
1 1 1
1 2 2
1 3 3
1 4 4
1 5 5
ans: 1 2 3 4 5

hack5:
5
2 2 2 2 10
4
2 4
1 1 3
1 5 2
2 3
ans: 3 4 4 4 3

hack6:
5
2 2 2 2 10
4
2 4
1 1 3
1 2 3
1 3 3
ans: 3 3 3 4 10

hack7:
// i = 4 , ans: 3 3 3 4 10
5
2 2 2 2 10
8
2 4
1 1 3
1 2 3
1 3 3
2 11
1 1 1
1 2 2
1 3 3
ans: 1 2 3 11 11

hack8:
// i = 4 , ans: 3 3 3 4 10
5
2 2 2 2 10
9
2 9
1 1 3
1 2 3
1 3 3
1 1 1
1 2 2
1 3 3
2 7
2 8
ans: 1 2 3 4 10
*/