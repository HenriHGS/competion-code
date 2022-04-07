#include <cstdio>
#include <cstring>
#include <iostream>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ ) 
using namespace std;
const int N = 1e5+10;

struct Node{
    int len, fa;
    int ch[26];
} node[N<<1];
int tot = 1, last = 1;
char s[N];
void init(){
    For(i,1,tot){
        auto& ch = node[i].ch;
        memset(ch,0,sizeof ch);
    }
    tot = last = 1;
}
int siz[N<<1];
void extend(int c){
    int p = last, np = last = ++tot;
    node[np].len = node[p].len + 1;
   // if(tot == 6) cout<<"ch:"<<(char)(c+'a')<<endl;
    for( ; p && !node[p].ch[c]; p = node[p].fa) node[p].ch[c] = np;
    if(!p) node[np].fa = 1;
    else {
        int q = node[p].ch[c];
        if(node[q].len == node[p].len + 1) node[np].fa = q;
        else {
            int nq = ++tot;
            node[nq] = node[q]; node[nq].len = node[p].len + 1;
            node[q].fa = node[np].fa = nq;
            for(; p && node[p].ch[c] == q; p = node[p].fa) node[p].ch[c] = nq;
        }
    }
}
int c[N<<1], sortId[N<<1];
void sortLen(){
    For(i,1,tot) c[node[i].len]++;
    For(i,1,tot) c[i] += c[i-1];
    for(int i = tot; i >= 1; i -- ){
        sortId[c[node[i].len] -- ] = i;
    }
    for(int i = tot; i >= 1; i -- ){
        int ind = sortId[i];
        int f = node[ind].fa;
        siz[f] += siz[ind];
    }
}
typedef long long ll;
ll ans;
void traverse(){
    for(int i = 2; i <= tot; i ++ ){
        int f = node[i].fa;
        // cout<<"len:";
        // cout<<node[i].len<<' '<<node[f].len<<endl; 
      //  cout<<"siz:";
      //  cout<<siz[i]<<endl; 
        ans += 1ll*(node[i].len - node[f].len)*(siz[i])*(siz[i] + 1) /2;
    }
    printf("%lld\n", ans);
}

int main(){
    init();
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    For(i,1,n) extend(s[i] - 'a'), siz[last] = 1;
/*     For(i,1,n){
        cout<<siz[i]<<' ';
    } */
   // puts("");
    sortLen();
    traverse();
}
/*
debug
len:0 0
len:1 0
len:2 1
len:3 0
len:4 0
len:5 1
len:1 0
len:6 1
23

siz:
siz:6
siz:2
siz:1
siz:1
siz:1
siz:1
siz:2
siz:1
23
*/