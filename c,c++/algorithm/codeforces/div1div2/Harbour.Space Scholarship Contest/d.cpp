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

void sol(){
    string s;
    string t;
    cin>>s>>t;
    vector<vector<int>> v0(26), v1(26);
    fori(i,0,sz(s)){
        if(i%2==0)v0[s[i]-'a'].pb(i);
        else v1[s[i]-'a'].pb(i);
    } 
    bool ok = false;
    //odd
    int pos = 0;
    fori(k,0,2){
        ok = false;
        pos = k;
        if(k == 1)pos = -1; 
        fori(i,0,sz(t)){
            int ch = t[i] - 'a';
            int nxt;
            if(pos%2==0 && pos != -1){
                //debug(pos);
                //debug(ch);
                if(lower_bound(ALL(v1[ch]), pos+1) == v1[ch].end())break;
                int id = lower_bound(ALL(v1[ch]), pos+1)  - v1[ch].begin();
                nxt = v1[ch][id];
              //  debug(t[i]);
               // debug(s[nxt]);
            }else {
                if(lower_bound(ALL(v0[ch]), pos+1) == v0[ch].end())break;
                int id = lower_bound(ALL(v0[ch]), pos+1)  - v0[ch].begin();
                nxt = v0[ch][id];
            }
            pos = nxt;
            if(i == sz(t) - 1)ok = true;
        }
        /*
        debug(ok);
        debug(k);
        debug(pos);
        */
        if(ok &&  (sz(s) - 1 ) % 2== pos % 2){
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
    //even
}



int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tt; cin>>tt;
    while(tt--)
        sol();
    return 0;
}