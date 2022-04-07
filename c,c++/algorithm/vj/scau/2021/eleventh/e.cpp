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
#include <ext/pb_ds/hash_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
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

const int maxn = 6e5 + 100;
const int mod[2] = {(int)(1e9+7), (int)(1e9+9)};
const int q[2] = {13331,131};
typedef pair<ll,ll> pau;
__gnu_pbds::gp_hash_table<ll,bool> gp;

vector<pau> dir;
ll ha[maxn][2], p[maxn][2];
void init(){
    p[0][0] = p[0][1] = 1;
    fori(i,1,maxn){
        fori(j,0,2){
            p[i][j] = (p[i-1][j]*q[j])%mod[j];
        }
    }
}
ll get(string s, int j){
    ll res = 0;
    for(char c:s)res = (res * q[j] % mod[j] + c) % mod[j];
    return res;
}
/*
aaaaa
786234389 786234333
acacaca
731743196 730755042
*/
void sol(){
    int n, m;
    init();
    cin>>n>>m;
    For(i,1,n){
        string s;
        cin>>s;
        int len = sz(s);
        ll t[2];
        fori(j,0,2) t[j] = get(s,j);
        t[0] = t[0] << 32 | t[1];
        gp[t[0]] = 1;
//        dir.pb({ha[len][0],ha[len][1]});
        /*
        debug(i);
        debug(ha[len][0]);
        debug(ha[len][1]);
        */
    }
    while(m--){
        string s;
        cin>>s;
        int len = sz(s);
        int ch[3] = {'a','b','c'};
        //getHash
        ll res[2];
        fori(j,0,2) res[j] = get(s,j);
        bool ok = false;
        fori(i,0,len){
            fori(j,0,3){
                if(ch[j]==s[i])continue;
                ll t1, t2;
                t1 = (res[0] + mod[0] - p[len-i-1][0]*s[i]%mod[0])%mod[0];
                t1 = (t1 + p[len-i-1][0]*ch[j]%mod[0])%mod[0];
                //now = ha[len][1];
                t2 = (res[1]  + mod[1]- p[len-i-1][1]*s[i]%mod[1])%mod[1];
                t2 = (t2 + p[len-i-1][1]*ch[j]%mod[1])%mod[1];
                t1 = t1 << 32 | t2;
                if(gp.find(t1) == gp.end())continue;
                else {
                    ok = true;
                    cout<<"YES"<<endl;
                    break;
                }
            }
            if(ok)break;
        }
        if(!ok)cout<<"NO"<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    sol();
    return 0;
}
/*
hack:
2 3
aaaaa
abbababba 
aabaa
abaaa
*/