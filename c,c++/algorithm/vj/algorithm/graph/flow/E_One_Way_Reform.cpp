#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cctype>
#define x first
#define y second
//#define DEBUG
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )

using namespace std;
//这题直接学习了大佬的代码了。。。。。。run了
const int M = 2*(300*300 + 200);
const int N = 210;
int read(){
    char ch = getchar(); int f = 0, x = 0;
    while(!isdigit(ch)) f|= (ch == '-'), ch = getchar();
    while(isdigit(ch)) x = x*10 + ch - '0', ch = getchar();
    return f ? -x : x;
}
template<typename T> void print(T x){
    if(x < 0) putchar('-'), x = -x;
    if(x >= 10) print(x/10);
    putchar(x%10 + '0');
}
template<typename T> void print(T x, char let) {
    print(x), putchar(let);
}
int n, m;
int deg[N];
int e[M], ne[M], idx, h[N];
void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
vector<pair<int,int>> ansp;
bool have[M];
void dfs(int x){
    for(int i = h[x]; ~i; h[x] = ne[i], i = ne[i]){
        if(have[i]) {
            continue;
        }
        int v = e[i];
        ansp.push_back({x,v});
        have[i] = have[i^1] = 1;
        dfs(v);
    }
}
void sol(){
    memset(have,0,sizeof have);
    memset(h,-1,sizeof h);
    idx = 0;
    n = read(), m = read();
    For(i,1,n) deg[i] = 0;
    For(i,1,m) {
        int a = read(), b = read();
        add(a,b); add(b,a);
        deg[a]++, deg[b]++;
    }
    int ans1 = 0;
    For(i,1,n) ans1 += (deg[i]%2 == 0);
    For(i,1,n) if(deg[i]&1) add(0,i),add(i,0);

    #ifdef DEBUG
    puts("ans,begin:");
    #endif
    print(ans1, '\n');
    For(i,1,n) dfs(i);
    fori(i,0,ansp.size()){
        auto& cur = ansp[i];
        if(cur.x && cur.y){
            print(cur.x,' ');
            print(cur.y,'\n');
        }
    }
    ansp.clear();
    #ifdef DEBUG
    puts("ans,end:");
    #endif
}

int main()
{
    int tt = read();
    while(tt--) sol();
    return 0;
}