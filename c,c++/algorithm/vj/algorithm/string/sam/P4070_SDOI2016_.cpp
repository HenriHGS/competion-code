#include <cstdio>
#include <cstring>
#include <map>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
using namespace std;
const int N = 1e5+10;
struct Node{
    int len, fa;
    map<int,int> ch;
} node[N<<1];
typedef long long ll;
ll ans = 0;
int last, tot;
void init(){
    For(i,0,tot) node[i].ch.clear();
    last = tot = 1;
}
void insert(int c){
    int p = last, np = last = ++tot;
    node[np].len = node[p].len + 1;
    for(; p && !node[p].ch.count(c) ; p = node[p].fa) node[p].ch[c] = np;
    if(!p) node[np].fa = 1;
    else {
        int q = node[p].ch[c];
        if(node[q].len == node[p].len + 1) node[np].fa = q;
        else {
            int nq = ++tot;
            node[nq] = node[q]; node[nq].len = node[p].len + 1;
            node[q].fa = node[np].fa = nq;
            for(; p && node[p].ch.count(c) && node[p].ch[c] == q; p = node[p].fa) 
                node[p].ch[c] = nq;
        }
    }
    ans += node[np].len - node[node[np].fa].len;
    printf("%lld\n", ans);
}
int main(){
    init();
    int n; scanf("%d", &n);
    For(i,1,n) {
        int x; scanf("%d", &x);
        insert(x);
    }
    return 0;
}