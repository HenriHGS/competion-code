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
//#define endl '\n' 
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
typedef pair<string,LL> psl;
const int maxn = 100000 + 5;
map<string,int> idc;
vector<psl>dirc;
LL count(string s){
    LL res = 0;
    for(int i = 0; i < sz(s); i ++ ) res += "haha" == s.substr(i,4);
    return res;
}
int getId(string s){
    if(idc.count(s)) return idc[s];
    LL cnt = count(s);
    dirc.pb({s,cnt});
    return idc[s] = sz(dirc) - 1;
}
void merge(string a, string b, string var){
    psl res;
    int id1 = getId(a), id2 = getId(b);
    res.se =  dirc[id1].se + dirc[id2].se;
    /*
    debug(dirc[id1].se);
    debug(dirc[id2].se);
    debug(dirc[id1].fi);
    debug(dirc[id2].fi);
    */
    string& s = dirc[id1].fi;
    string& t = dirc[id2].fi;
    res.fi = s + t;
    int siz1 = sz(s), siz2 = sz(t);
    /*
    debug(siz1);
    debug(siz2);
    */
    for(int i = max(0,siz1-3); i < siz1; i ++ ){
        res.se += res.fi.substr(i,4) == "haha";
    }
    if(sz(res.fi) > 6){
        string& word = res.fi;
        word.erase(word.begin()+3,word.end()-3);
    }
    int id = getId(var);
    dirc[id] = res;
}
void sol(){
    int n;
    cin>>n;
    idc.clear();
    dirc.clear();
    string word;
    //getchar();
    //getchar();
    getline(cin,word);
    LL ans = 0;
    For(i,1,n){
        string line;
        getline(cin,line);
        //debug(line);
        if(line.find(":=") != string::npos){
            string var, val;
            var = line.substr(0,line.find(' '));
            val = line.substr(line.find(":= ")+3);
            //debug(val);
            int id = getId(var);
            psl& var_val = dirc[id];
            var_val.fi = val;
            var_val.se = count(val);
            word = var;
        }else {
            string var1, var2, var3;
            var1 = line.substr(0,line.find(' '));
            line = line.substr(line.find("= ")+2);//
            var2 = line.substr(0,line.find(' '));
            line = line.substr(line.find("+")+2);
            var3 = line;
            /*
            debug(var1);
            debug(var2);
            debug(var3);
            */
            int id1 = getId(var1);
            int id2 = getId(var2);
            int id3 = getId(var3);
            merge(var2,var3,var1);
            word = var1;
        }
        ans = dirc[getId(word)].se;
        //debug(ans);
    }
    ans = dirc[getId(word)].se;
    cout<<ans<<endl;
}



int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tt; cin>>tt;
    while(tt--)
        sol();
    return 0;
}