#include <cstdio>
#include <cctype>
#include <cstring>
#include <vector>
using namespace std;
const int maxn = 1e6+8;
typedef long long ll;
template<typename T> void print(T x){
    if(x < 0) putchar('-'), x = -x;
    if(x >= 10) print(x/10);
    putchar(x%10+'0');
}
int w[2][maxn<<1];
struct GYSAM{
    //sam的长度要开2倍
    int tot = 1, ch[maxn<<1][26], len[maxn<<1], fa[maxn<<1];
    int siz[maxn<<1];
    inline int insert(int c, int las){
        if(ch[las][c]){
            int p = las, q = ch[p][c];
            if(len[p] + 1 == len[q]) return q;
            int nq = ++tot;
            memcpy(ch[nq], ch[q], sizeof ch[q]);
            len[nq] = len[p] + 1;
            fa[nq] = fa[q];
            fa[q] = nq;
            for(; p && ch[p][c] == q; p = fa[p]) ch[p][c] = nq;
            return nq;
        }
        int p = las; int np = las = ++tot;
        len[np] = len[p] + 1;
        //w[np] = 1;
        for(;p&&!ch[p][c]; p = fa[p]) ch[p][c] = np;
        if(!p) fa[np] = 1;
        else {
            int q = ch[p][c];
            if(len[q] == len[p] + 1) fa[np] = q;
            else {
                int nq = ++tot;
                memcpy(ch[nq], ch[q], sizeof ch[q]);
                len[nq] = len[p] + 1;
                fa[nq] = fa[q];
                fa[q] = fa[np] = nq;
                for(; p && ch[p][c] == q; p = fa[p]) ch[p][c] = nq;
            }
        }
        return np;
    }
   // vector<int> bucket[maxn<<1];
    int c[maxn<<1];
    int sortId[maxn<<1];
    void sortLen(){
        for(int i = 1; i <= tot; i ++ ) c[len[i]]++;
        for(int i = 1; i <= tot; i ++ ) c[i] += c[i-1];
        for(int i = tot; i >= 1; i -- ){
            sortId[c[len[i]]--] = i;
        }
        for(int i = tot; i >= 1; i -- ){
            int ind = sortId[i];
            int f = fa[ind];
            w[0][f] += w[0][ind];
            w[1][f] += w[1][ind];
        }
        /* 
        //for(int i = 0; i <= tot; i ++ ) bucket[i].clear();
        int mx_len = 0;
        for(int i = 1; i <= tot; i ++ ){
           // bucket[len[i]].push_back(i);
           c[len[i]]++;
            mx_len = max(mx_len, len[i]);
        }
        for(int i = mx_len; i >= 1; i -- ){
            for(auto ind: bucket[i]){
                int f = fa[ind];
                w[0][f] += w[0][ind];
                w[1][f] += w[1][ind];
            }
        } 
        */
    }
    inline void solve(){
        ll ans = 1e9;
        for(int i = 2; i <= tot; i ++ ){
            if(w[0][i] == 1 && w[1][i] == 1){
                ans = min(ans,1ll*len[fa[i]] + 1);
            }
        }
      //  return ans;//
       if(ans == 1e9) ans = -1;
        print(ans);
    }
} sam;
int read(){
    int f = 0, x = 0; char ch = getchar();
    while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
    while(isdigit(ch)) x = x*10 + ch - '0', ch = getchar();
    return f?-x:x;
}
char s[maxn], t[maxn];

int main(){
    scanf("%s", s);
    scanf("%s", t);
    int slen = strlen(s), tlen = strlen(t);
    int last = 1;
    for(int i = 0;  i < slen; i ++ ) last = sam.insert(s[i] - 'a', last), w[0][last] = 1;
    last = 1;
    for(int i = 0; i < tlen; i ++ ) last = sam.insert(t[i] - 'a', last), w[1][last] = 1;
    //sort
    //print(sam.tot);
    sam.sortLen();
    sam.solve();
    return 0;
}
