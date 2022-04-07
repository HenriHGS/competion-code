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

const int maxn = 5e6 + 6;
int phi[maxn];
bool st[maxn];
int primes[maxn], cnt;
ll get_phi(int n){
    phi[1] = 1;
    for(int i = 2; i <= n; i ++ ){
        if(!st[i]){
            primes[cnt++] = i;
            phi[i] = i - 1;
        }
        for(int j = 0; i <= n/primes[j]; j ++ ){
            st[i*primes[j]] = 1;
            if(i % primes[j] == 0){
                phi[i*primes[j]] = phi[i]*primes[j];
                break;
            }
            phi[i*primes[j]] = phi[i]*(primes[j]-1);
        }
    }
}
/*
ULL pre[maxn];
void init(){
    fori(i,1,maxn){
        pre[i] = pre[i-1] + (ULL)phi[i]*phi[i];
    }
}
*/
int cas;
const int N = 1e5+10;
struct Seg{
    int l, r;
    ULL res;
} seg[N];
struct Node{
    int l;
    ULL res;
//    operator
    bool operator <  (const Node& x)const{
        return l < x.l;
    }
    bool operator == (const Node&x)const {
        return l==x.l&&res==x.res;
    }
} node[2*N];
int tot;
void sol(){
    int n = read();
    For(i,1,n){
        seg[i].l = read(), seg[i].r = read();
        node[++tot] = {seg[i].l, 0};
        node[++tot] = {seg[i].r, 0};
    }
    sort(node + 1,node + 1 + tot);
    tot = unique(node + 1, node + 1 + tot) - (node + 1);
    ULL pre = 0;
    int now = 1;
    fori(i,1,maxn){
        pre = pre + (ULL)phi[i]*phi[i];
        if(i == node[now].l){
            node[now].res = pre;
            now++;
        }
    }
    For(i,1,n){
        Node n1 = {seg[i].l, (ULL)0};
        Node n2 = {seg[i].r, (ULL)0};
        int l = lower_bound(node + 1, node + 1 + tot, n1) - node;    
        int r = lower_bound(node + 1, node + 1 + tot, n2) - node;
        ULL res = node[r].res - node[l].res + (ULL)phi[node[l].l] * phi[node[l].l];
        printf("Case %d: %llu\n", i, res);   
    }
    //cin>>n;
    // ULL ans = pre[b] - pre[a-1];
    //cout<<"Case "<<++cas<<": ";
    //cout<<ans<<endl;
}
int main() {
    //ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    get_phi(maxn-1);
    //init();
    sol();
    //cin>>tt;
   // while(tt--)sol();
    return 0;
}
