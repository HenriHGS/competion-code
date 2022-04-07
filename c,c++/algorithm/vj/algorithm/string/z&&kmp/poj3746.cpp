#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <sstream>
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

int n, m;
map<string,int>prop;
map<string,int>dir;
void init(){
    prop["n"] = 1;
    prop["pron"] = 2;
    prop["adj"] = 3;
    prop["adv"] = 4;
    prop["prep"] = 5;
    prop["art"] = 6;
    prop["vt"] = 7;
    prop["vi"] = 8;
    prop["v"] = 9;
}
const string ans[2] = {"NO", "YES"};
void sol(){
    init();
    cin>>n>>m;
    For(i,1,n){
        string word, prop_;
        cin>>word>>prop_;
        dir[word] = prop[prop_];
    }
    while(m--){
        bool ok = true;
        string line;
        getline(cin,line);
        stringstream ss;//(line);
        //stringstream ss(line);
        //ss.clear();
        ss.str(line);
        string word;
        int prep = 0;
        int prep_phase = 0;
        int cnt_prep = 0;
        int adj = 0;
        int pre_art = 0;
        int noun = 0;
        int sub = 0;
        int vi = 0;
        int vt = 0;
        int v = 0;
        int obj = 0;
        int i = 0;
        while(ss>>word){
            int prop_ = dir[word];
            i++;
            if(!ok)continue;
            if(prop_ == 1 || prop_ == 2){
                //主语或者宾语
                if(!vi && !vt && !v){
                    if(prep) prep_phase = i;
                    else sub = i;//作主语
                }else if(vi){
                    //if(prep) prep_phase 
                }
                if(prop_ == 1){
                    if(!pre_art)ok = false;
                    else {
                        // art adj n
                        if(adj){
                            if(adj < pre_art) ok = false;
                            else adj = 0, pre_art = 0;
                        }else pre_art = 0;
                    }
                }
            }
        }
        if(ok)cout<<ans[1]<<endl;
        else cout<<ans[0]<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    sol();
    return 0;
}