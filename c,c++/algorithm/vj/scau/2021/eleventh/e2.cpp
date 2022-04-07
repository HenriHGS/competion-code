//#include <bits/stdc++.h>
#include <ext/pb_ds/hash_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/rope>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <random>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <cmath>
#include <ctime>

#define X first
#define Y second
#define ls rt<<1
#define rs rt<<1|1
#define getmid ((l+r)>>1)
#define PB push_back
#define EB emplace_back
#define lowbit(x) ((x)&-(x))
#define sz(a) ((int)a.size())
#define ALL(x) x.begin(),x.end()
#define mst(x,a) memset(x, a, sizeof(x))
using namespace std;
#ifdef LOCAL
#define dbg(args...) cout << #args << " -> ", err(args);
void err(){ cout << endl; }
template<typename T, typename... Args>
void err(T a, Args... args){ cout << a << ' '; err(args...); }
#else
#define dbg(args...)
#endif // LOCAL

//using namespace __gnu_cxx;
using namespace __gnu_pbds;
typedef double db;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fll;

const int N = 6e5 +10;
const int M = 20 + 10;
const int maxn = 1e6 + 10;
const int mod1 = (int)1e9 + 7;
const int mod2 = (int)1e9 + 9;
const db eps = 1e-15;
const db pi = acos(-1.0);
const int base = 131;

int n,m;
ll pw1[N];
ll pw2[N];
gp_hash_table<ll,bool> gp;

void init() {
    pw1[0] = pw2[0] = 1;
    for(int i=1; i<N; i++) {
        pw1[i] = pw1[i-1] * base % mod1;
        pw2[i] = pw2[i-1] * base % mod2;
    }
}

inline ll get1(string &s) {
    ll res = 0;
    for(char c: s) res = (res * base + c) % mod1;
    return res;
}

inline ll get2(string &s) {
    ll res = 0;
    for(char c: s) res = (res * base + c) % mod2;
    return res;
}

int main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
#endif //LOCAL
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    cin>>n>>m;
    string s;
    for(int i=1; i<=n; i++) {
        cin>>s;
        cout<<get1(s)<<' ';
        cout<<get2(s)<<endl;
        ll res = (get1(s) << 32) | get2(s);
        gp[res] = 1;
    }
    for(int i=1; i<=m; i++) {
        cin>>s;
        ll res1 = get1(s);
        ll res2 = get2(s);
        int len = sz(s);
        bool tag = 0;
        for(int i=0; i<len; i++) {
            for(char c='a'; c<='c'; c++) {
                if(c == s[i]) continue;
                ll t1 = (res1 + (c - s[i]) * pw1[len - i - 1]) % mod1;
                ll t2 = (res2 + (c - s[i]) * pw2[len - i - 1]) % mod2;
                t1 = (t1 + mod1) % mod1;
                t2 = (t2 + mod2) % mod2;
                t1 = (t1 << 32) | t2;
                if(gp.find(t1) != gp.end()) {
                    tag = 1;
                    break;
                }
            }
            if(tag) break;
        }
        cout<<(tag ? "YES" : "NO")<<'\n';
    }

    return 0;
}

  		 			  		  		 			  			 	