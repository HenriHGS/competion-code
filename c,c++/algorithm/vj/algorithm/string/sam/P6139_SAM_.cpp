#include <cstdio>
#include <cctype>
#include <cstring>
using namespace std;
const int maxn = 1e6+8;
typedef long long ll;
template<typename T> void print(T x){
    if(x < 0) putchar('-'), x = -x;
    if(x >= 10) print(x/10);
    putchar(x%10+'0');
}
struct GYSAM{
    //sam的长度要开2倍
    int tot = 1, ch[maxn<<1][26], len[maxn<<1], fa[maxn<<1];
    inline int add(int c, int las){
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
    inline void solve(){
        ll ans = 0;
        for(int i = 2; i <= tot; i ++ ) ans += len[i] - len[fa[i]];
      //  return ans;//
        print(ans);
    }
} sam;
int read(){
    int f = 0, x = 0; char ch = getchar();
    while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
    while(isdigit(ch)) x = x*10 + ch - '0', ch = getchar();
    return f?-x:x;
}
char s[maxn];
int main(){
    int n = read();
    for(int i = 1; i <= n; i ++ ){
        scanf("%s", s);
        int len = strlen(s);
        int last = 1;
        for(int j = 0; j < len; j ++ ) last = sam.add(s[j]-'a', last);
    }
   // print(sam.solve());
   sam.solve();
    return 0;
}
