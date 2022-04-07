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

const int N = 202000 + 10, M = 2e6+10;
LL n, s; 
struct Node{
    int a, b, c, sign, p, id;
    LL res;
    bool operator < (const Node&x)const {
        if(a != x.a) return a < x.a;
        if(b != x.b) return b < x.b;
        return c < x.c;
    }
}q[N], w[N];
LL tr[M<<1];
LL ans[N];
int lowbit(int x){
    return x & (-x);
}
void add(int x, int v){
    for(int i = x; i < M; i += lowbit(i)) tr[i] += v;
}
LL sum(int x){
    LL res = 0;
    for(int i = x; i ; i -= lowbit(i)) res += tr[i];
    return res;
}
void merger_sort(int l, int r){
    if(l >= r) return ;
    int mid = l + r >> 1;
    merger_sort(l,mid); merger_sort(mid + 1, r);
    int i = l, j = mid + 1, k = 0;
    while(i <= mid && j <= r){
        if(q[i].b <= q[j].b)add(q[i].c, q[i].p), w[k++] = q[i++];
        else q[j].res += sum(q[j].c), w[k++] = q[j++];
    }
    while(i <= mid) add(q[i].c, q[i].p), w[k++] = q[i++];
    while(j <= r)   q[j].res += sum(q[j].c), w[k++] = q[j++];
    for(int i = l; i <= mid; i ++ ) add(q[i].c, -q[i].p);
    for(int i = l, j = 0; j < k; i ++ , j ++ )q[i] = w[j];
}
int main() {
    //ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    scanf("%d%d", &s, &n);
    int cnt = 0, time = 0;
    int op;
    int k = 0;
    while(scanf("%d", &op) && op != 3){
        time++;
        if(op == 1){
            int x, y,p;
            scanf("%d%d%d", &x, &y, &p);
            q[++k] = {x,y,time,1,p};
        }else {
            cnt++;
            int x1, y1, x2, y2;
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            LL sum = s*n*n;
            q[++k] = {x2, y2, time, 1, 0,cnt, sum};
            q[++k] = {x2, y1 - 1, time, -1, 0,cnt};
            q[++k] = {x1 - 1, y2, time, -1, 0,cnt};
            q[++k] = {x1 - 1, y1 - 1, time, 1, 0,cnt};
        }
    }
    sort(q+1,q+1+k);
    merger_sort(1,k);
    for(int i = 1; i <= k; i ++ ){
        if(!q[i].id)continue;
        LL id = q[i].id, val = q[i].res;
        ans[id] += q[i].res*q[i].sign;
    }
    For(i,1,cnt){
        printf("%lld\n", ans[i]);
    }
    return 0;
}