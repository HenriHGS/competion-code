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

const int maxn = 3e5 + 10;
int a[maxn];
//bool vis[maxn];
set<int>S;
set<int>temp;
LL pre[maxn];
int pos[maxn];
void sol(){
    int n;
    cin>>n;
    int mx = 0;
    For(i,1,n)cin>>a[i], ckmax(mx,a[i]),S.insert(a[i]), pos[a[i]] = i;
    mx*=2;
    LL ans = 0;
    LL sum = 0;
    For(i,1,n){
        pre[i] += pre[i-1];
        LL sub = 0;
        for(int j = a[i]; j <= mx; j += a[i]){
            if(S.lower_bound(j)!=S.end()){
                auto it =  S.lower_bound(j);
                int val = *it;
                if(pos[val] > i){
                    //会对后面的答案产生贡献
                    pre[pos[val]] += val%i + i%val;
                }else if(pos[val] < i){
                    pre[i] += val%i + i%val;
                }
                //sub += *it;
                temp.insert(*it);
                S.erase(it);
            }
        }
        for(auto x:temp)S.insert(x);
        temp.clear();
       // pre[i] += sum - sub;
        debug(sum);
        debug(sub);
        sum += a[i];
        //S.insert(a[i]);
        cout<<pre[i]<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    sol();
    return 0;
}