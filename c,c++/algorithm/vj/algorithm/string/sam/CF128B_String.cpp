#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 2e5+10;
char s[N];
int last = 1, tot = 1, k, n;
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
struct Node{
    int len, fa;
    int ch[26];
} node[N<<1];
int siz[N<<1];
void init(){
    For(i,1,tot){
        node[i].fa = node[i].len = 0;
        auto& ch = node[i].ch;
        memset(ch, 0, sizeof ch);
    }
    last = tot = 1;
}
void extend(int c){
    int p = last, np = last = ++tot;
    siz[np] = 1;
    node[np].len = node[p].len + 1;
    for( ; p && !node[p].ch[c]; p = node[p].fa) node[p].ch[c] = np;
    if(!p) node[np].fa = 1;
    else{
        int q = node[p].ch[c];
        if(node[q].len == node[p].len + 1) node[np].fa = q;
        else {
            int nq = ++tot;
            node[nq] = node[q];
            node[q].fa = node[np].fa = nq;
            node[nq].len = node[p].len + 1;
            for(; p && node[p].ch[c] == q; p = node[p].fa) node[p].ch[c] = nq;
        }
    }
}
int c[N<<1], sortId[N<<1];
void sortLen(){
    for(int i = 1; i <= tot; i ++ ) c[node[i].len]++;
    for(int i = 1; i <= tot; i ++ ) c[i] += c[i-1];
    for(int i = tot; i >= 1; i -- ) sortId[c[node[i].len]--] = i;
    for(int i = tot; i >= 1; i -- ){
        int ind = sortId[i];
        int f = node[ind].fa;
        siz[f] += siz[ind];
    }
}
typedef long long ll;
ll f[N<<1];
ll getOrder(int x){
    if(f[x]) return f[x];
    ll& ans = f[x];
    ans = siz[x];
    for(int i = 0; i < 26; i ++ ){
        if(node[x].ch[i])ans += getOrder(node[x].ch[i]);
    }
    return f[x];
}
#include <iostream>
#define debug(a) cout<<#a<<":"<<a<<endl
void solve(int x,int k){
    if(siz[x] >= k) return;
    k -= siz[x];
    for(int i = 0; i < 26; i ++ ){
        int c = node[x].ch[i];
       /*  if(x == 1){
            if(i == 0) debug(f[c]);
        } */
        if(c && f[c] < k) k -= f[c];
        else if(c){
           // if(x == 1)debug(i);
            putchar('a' + i);
            solve(c,k);
            return ;
        }
    }
}
int main(){
    init();
    scanf("%s", s + 1);
    scanf("%d", &k);
    n = strlen(s + 1);
    For(i,1,n) extend(s[i] - 'a');
    sortLen();
    getOrder(1);
    siz[1] = 0;
    if(f[1] < k) puts("No such line.");
    else solve(1,k);
    return 0;
}