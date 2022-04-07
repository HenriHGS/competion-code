#include <cstdio>
#include <cstring>
#include <algorithm>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
const int maxn = 1e6 + 10, N = 156;
const int SZ = N*80;
int tr[SZ][26], fail[SZ], idx, cnt[SZ];
void extend(char * str,int id){
    int p = 0;
    for(int i = 1; str[i]; i ++ ){
        int c = str[i] - 'a';
        if(!tr[p][c]){
            tr[p][c] = ++ idx;
            int child = tr[p][c];
            memset(tr[child], 0, sizeof tr[child]);
            fail[child] = 0;
        }
        p = tr[p][c];
    }
    cnt[p] = id;
    //printf("P = %d\n", p);
}
int q[SZ];
void build(){
    int hh = 0, tt = -1;
    fori(i,0,26) if(tr[0][i]) q[++tt] = tr[0][i];
    while(hh <= tt){
        int t = q[hh++];
        fori(i,0,26){
            int p = tr[t][i];
            if(!p) tr[t][i] = tr[fail[t]][i];
            else {
                fail[p] = tr[fail[t]][i];
                q[ ++ tt] = p;
            }
        }
    }
}
int n;
char str[maxn];
char T[SZ][80];
bool vis[SZ];
int cnt_times[SZ];
void sol(){
    memset(cnt, 0, sizeof cnt); memset(cnt_times, 0 , sizeof cnt_times);
    idx = 0; memset(tr[0], 0, sizeof tr[0]);
    For(i,1,n){
        scanf("%s", T[i] + 1);
        extend(T[i], i);
    }
    build();
    scanf("%s", str + 1);
    memset(vis,0, sizeof vis);
    int p = 0;
    int mx = 0;
    for(int i = 1; str[i]; i ++ ){
        int c = str[i] - 'a';
        p = tr[p][c]; 
        //printf("start  P = %d\n", p);
        int j = p;
        while(j){
            //printf("j = %d\n", j);
            if(cnt[j]) {
                cnt_times[cnt[j]] ++;
                mx = max(mx,cnt_times[cnt[j]] );
            }
            j = fail[j];
        }
    }
    printf("%d\n", mx);
    For(i,1,n) if(cnt_times[i] == mx && mx) printf("%s\n", T[i] + 1);
}
int main(){
    int tt; //scanf("%d", & tt);
    while(scanf("%d", &n) && n) sol();
    return 0;
}