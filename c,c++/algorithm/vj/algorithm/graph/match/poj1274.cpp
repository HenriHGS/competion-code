#include <cstdio>
#include <cstring>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
const int N = 210, M = 210*310, N2 = 310;
int n1, n2;
bool st[N2];
int match[N2];
int h[N], e[M], idx, ne[M];
void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}
int find(int x){
    for(int i = h[x]; ~i; i = ne[i]){
        int j = e[i];
        if(!st[j]){
            st[j] = true;
            if(match[j] == 0 || find(match[j])){
                match[j] = x;
                return true;
            }
        }
    }
    return false;
}
int main(){
    while(~scanf("%d %d", &n1, &n2)){
        memset(h,-1,sizeof h);
        memset(match,0,sizeof match);
        For(i,1,n1){
            int t;
            scanf("%d", &t);
            while(t--){
                int x;
                scanf("%d", &x);
                add(i,x);
            }
        }
        int mx = 0;
        For(i,1,n1) {
            memset(st,0,sizeof st);
            if(find(i)) mx++;
        }
        printf("%d\n", mx);
    }
    return 0;
}