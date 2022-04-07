#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
#include <cctype>
#include <assert.h>
#include <numeric>
#define pb emplace_back
#define rep(i,a,b) for(int i = (a); i <= (b); i ++ )
#define per(i,a,b) for(int i = (a); i >= (b); i -- )
#define forr(i,a) for(auto i:a)
#define rall(a) rbegin(a), rend(a)
#define all(a) begin(a), end(a)
using namespace std;

int read(){
    char ch = getchar(); int f = 0, x = 0;
    while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
    while(isdigit(ch)) x = x*10 + ch - '0', ch = getchar();
    return f?-x:x;
}
template<typename T> void print(T x){
    if(x < 0) putchar('-'), x = -x;
    if(x >= 10) print(x/10);
    putchar(x%10+'0');
}
template<typename T> void print(T x, char let){
    print(x), putchar(let);
}
typedef long long ll;
const ll INF = 1e18;
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )


const int N = 2e5+10, M = 2*N;
int n, m;
int e[M], ne[M], h[N], w[M], idx;
// even org
void add(int a, int b, int c){
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}
int deg[N];
int ans[N];
bool ok[N];
#define debug(a) cout<<#a<<":"<<a<<endl
int main(){
    memset(ans, -1, sizeof ans);
    memset(h, -1, sizeof h);
    n = read(), m = read();
    For(i,1,m){
        int a = read(), b = read(), c = read();
        add(a,b,c); add(b,a,c);
        deg[a] += c, deg[b] += c;
    }
    queue<int> que; ok[n] = 1;
    que.push(1);
    while(!que.empty()){
        int u = que.front(); que.pop();
      //  debug(u);
        ok[u] = true;
        for(int i = h[u]; ~i; i = ne[i]){
            int ver = e[i];
            //if(u == 2) cout<<ver<<' ',debug(i);
          //  if(i/2 + 1 == 1) cout<<ver<<' ',debug(u);
            if(ans[i/2 + 1] == -1) {
                ans[i/2 + 1] = i%2;
               // if(u == 2) debug(i%2);
            }
            if(!ok[ver]) {
                deg[ver] -= 2*w[i];
                if(deg[ver] == 0)que.push(ver);
            }
        }
    }
    For(i,1,m) print(ans[i],'\n');
    return 0;
}