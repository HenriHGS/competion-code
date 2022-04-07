#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#define pb push_back
#define mst(x,a) memset(x,a,sizeof x)
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
const int N = 5e5+10;
char s[N];
struct Node{
    int len, fa;
    int ch[26];
} node[N<<2];
int tot, last;
void init(){
    last = tot = 1;
}
int siz[N<<2], f[N<<2];
//f 求不同子串的个数， siz求这个等价类里的个数。
void add(int c){
    int p = last, np = last = ++tot;
    siz[np] = f[np] = 1;
    node[np].len = node[p].len + 1;
    for( ; p && !node[p].ch[c]; p = node[p].fa) node[p].ch[c] = np;

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
vector<int> bb[N];
int t, k;
void print(int k, int now){
    if(siz[now] >= k) return;
    k -= siz[now];
    fori(i,0,26){
        int ch = node[now].ch[i];
        if(!ch) continue;
        if(f[ch] < k) k -= f[ch];
        else {
            printf("%c", (i+'a'));
            print(k, ch);
            return ;
        }
    }
}
int main(){
    init();
    scanf("%s %d %d", (s+1), &t, &k);
    init();
    int n = strlen(s+1);
    For(i,1,n) add(s[i]-'a');
    For(i,1,tot) bb[node[i].len].pb(i); 
    for(int i = n; i>=0; i -- ){
        for(auto x: bb[i]){
            int fa = node[x].fa;
            siz[fa] += siz[x];
        }
    }//求不同子串的个数
  //  For(i,1,tot) cout<<siz[i]<<' ';
    //cout<<endl;
    if(t == 0)For(i,1,tot) siz[i] = f[i] = 1;
    else For(i,1,tot) f[i] = siz[i];
    siz[1] = f[1] = 0;
    for(int i = n; i>=0; i -- ){
        for(auto x: bb[i]){
            fori(j,0,26){
                if(node[x].ch[j]) f[x] += f[node[x].ch[j]];
            }
        //    cout<<"x: "<<x<<", f[x] = "<<f[x]<<endl;
        }
    }//求每个点，向后延申的子串的个数(根据等价类)
    //cout<<f[1]<<endl;
    if(k > f[1]) puts("-1");
    else print(k,1);
    return 0;
}