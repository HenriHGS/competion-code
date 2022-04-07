#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 2.5e5+10;
struct Node{
    int len, fa;
    int ch[26];
} node[N<<1];
int ans = 0;
int last, tot;
void init(){
    for(int i = 0; i <= tot; i ++ ) {
        auto & ch = node[i].ch;
        memset(ch,0, sizeof ch);
    }
    last = tot = 1;
}
void insert(int c){
    int p = last, np = last = ++tot;
    node[np].len = node[p].len + 1;
    for(; p && !node[p].ch[c]; p = node[p].fa) node[p].ch[c] = np;
    if(!p) node[np].fa = 1;
    else {
        int q = node[p].ch[c];
        if(node[q].len == node[p].len + 1) node[np].fa = q;
        else {
            int nq = ++tot;
            node[nq] = node[q], node[nq].len = node[p].len + 1;
            node[q].fa = node[np].fa = nq;
            for(; p && node[p].ch[c] == q; p = node[p].fa) node[p].ch[c] = nq;
        }
    }
}
char s[N], t[N];
int main(){
    init();
    scanf("%s", s + 1);
    int n = strlen(s+1), m;
    for(int i = 1; i <= n; i ++ ) insert(s[i] - 'a');
    scanf("%s", t + 1);
    m = strlen(t+1);
    int p = 1, len = 0, ans = 0;
    for(int i = 1; i <= m; i ++ ){
        int c = t[i] - 'a';
        while(p > 1 && !node[p].ch[c]) p = node[p].fa, len = node[p].len;
        if(node[p].ch[c]) p = node[p].ch[c],len++;
        ans = max(ans,len);
    }
    printf("%d\n", ans);
    return 0;
}