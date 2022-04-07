#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;

const int N = 1e3+10, M = 1e5+10;
queue<int> q;
int n, m, idx, tim, ans;
int h[N], e[M], ne[M], lk[N], tag[N], p[N], pre[N], dfn[N];
void link(int x, int y){
    lk[x] = y, lk[y] = x;
}
void add(int a, int b){
    if(!lk[a] && !lk[b]) link(a,b), ans++;
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
    e[idx] = a, ne[idx] = h[b], h[b] = idx++;
}
void rev(int x) {
    //为了方便地遍历这条增广路，
    //对每个点存一个前驱 pre 表示这个点出发走一条非匹配边后应该到达哪个节点。
    //被缩掉的环上的非匹配边的 pre 应该都是双向的，在缩环时处理一下。
    if(x) rev(x[pre][lk]), link(x,pre[x]);
}
int find(int x){
    if(p[x] == x) return x;
    return p[x] = find(p[x]);
}
int lca(int x, int y){
    for(tim++;; x = x[lk][pre], swap(x,y)){
        if(dfn[x = find(x)] == tim) return x; //两边跳，x（y）会先跳到anc，之后y（x）再跳到anc时，就找到了。
        else if(x) dfn[x] = tim;
    }
}
void shrink(int x, int y, int anc){
    for(;find(x) != anc; x = pre[y]){
        pre[x] = y, y = lk[x], p[x] = p[y] = anc;
        //，因为缩起来的环是一个黑点，所以环上的白点都需改成黑点并加入到队列中。
        if(tag[y] == 2) tag[y] = 1, q.push(y);
    }
}
int blossom(int u){
    //tag[i] == 0 未被访问过的点
    //tag[i] == 1 队列中的点 “黑点”
    //tag[i] == 2 被队列中的点 拓展的点 “白点”
    For(i,1,n) tag[i] = pre[i] = 0, p[i] = i;
    tag[u] = 1, q = queue<int>(),q.push(u);
    // 黑 -> 白 “非匹配”
    for(int anc; !q.empty(); q.pop()){
        u = q.front();
        for(int i = h[u]; ~i; i = ne[i]){
            int v = e[i];
            if(tag[v] == 1){
                //访问到的点是黑点，（则找到了一个奇环，看上面的图方便理解）
                anc = lca(u,v), //找到h（看上面的图方便理解）
                 //利用并查集缩起来
                shrink(u,v,anc),
                shrink(v,u,anc);
            }
            else if(!tag[v]){
                pre[v] = u, tag[v] = 2;
                if(!lk[v]) return rev(v), 1;//找到增广路
                else tag[lk[v]] = 1, q.push(lk[v]);
            }//else 
            {
                //访问到的点是白点，（则找到了一个偶环，看上面的图方便理解）
            }
        }
    }
    return 0;
}
int main(){
    memset(h,-1,sizeof h);
    scanf("%d %d", &n, &m);
    For(i,1,m){
        int a, b; scanf("%d %d", &a,  &b);
        add(a,b);
    }
    //枚举每个未盖点（未匹配点）i，从这个点开始bfs找增广路aug。
    For(i,1,n) ans += !lk[i] && blossom(i);
    printf("%d\n", ans);
    For(i,1,n) printf("%d ",lk[i]);
    return 0;
}