#include <cstdio>
#include <cstring>
#include <map>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
const int N = 1e6+10;
int tr[N][26], cnt[N], fail[N];
char str[N];
int idx;
void extend(char * str){
    int p = 0;
    for(int i = 0; str[i]; i ++ ){
        int c = str[i] - 'a';
        if(!tr[p][c]) tr[p][c] = ++idx;
        p = tr[p][c];
    }
    cnt[p]++;
}
int q[N];
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
int main(){
    int n; scanf("%d", &n);
    For(i,1,n){
        scanf("%s", str);
        extend(str);
    }
    build();
    scanf("%s", str);
    int p = 0, ans = 0;
    for(int i = 0; str[i]; i ++ ){
        p = tr[p][str[i] - 'a'];
        int j = p;
        while(j && cnt[j]){
            ans += cnt[j];
            cnt[j] = 0;
            j = fail[j];
        }
    }
    printf("%d\n", ans);
    return 0;
}