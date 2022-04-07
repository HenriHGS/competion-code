#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
#define read(a) scanf("%d", &a)
using namespace std;
char s[2000][20];
int len[2000];
int pos[26]{};
int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b,a%b);
}
int lca(int a, int b){
    return a/gcd(a,b)*b;
}
int main(){
    int tt;
    read(tt);
    while(tt--){
        int n;
        read(n);
        int cnt[26]{};
        int dif = 0;
       // int tot = 1;
        For(i,1,n){
            scanf("%s", s[i]);
            len[i] = strlen(s[i]);
            fori(j,0,len[i]){
                if(!cnt[s[i][j]-'a'])dif++;//dif += !cnt[s[i][j] - 'a'];
                cnt[s[i][j] - 'a']++;
            }
          //  tot = lca(tot,len[i]);
        }
       //For(i,1,n)printf("%s", s[i]);
        int ans = n*12;
        int nxt[200]{};
        int now = 0;
        memset(pos,-1,sizeof pos);
        int end = 4e5;
        while(1){
            For(i,1,n){
                now++;
                int cur = nxt[i];
                int tot = 0;
                pos[s[i][cur] - 'a'] = now;
                int le = 1e9;
                fori(j,0,26){
                    if(pos[j] != -1) tot++, le = min(le,pos[j]);
                }
                if(tot == dif) ans = min(ans,now - le + 1);
                nxt[i]++;
                if(nxt[i] >= len[i])nxt[i] = 0;
                if(now == end)break;
            }
            if(now==end)break;
        }
      // int ans = 0;
        printf("%d\n", ans);
    }
    return 0;
}