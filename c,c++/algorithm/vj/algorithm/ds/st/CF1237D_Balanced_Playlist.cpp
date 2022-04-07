#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
const int N = 3e5+10;
const int MX_LOG = 24;
int mx[N][MX_LOG];
int read(){
    char ch = getchar(); int f = 0, x = 0;
    while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
    while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    return f? -x : x; 
}
int logn[N];
void init(){
    logn[1] = 0;
    fori(i,2,N) logn[i] = logn[i/2] + 1;
}
int n;
int find(int l, int r){
    int s = logn[r - l + 1];
    return max(mx[l][s], mx[r - (1<<s) + 1][s]); 
}
int main(){
    init();
    n = read();
    int n3 = n*3;
    int maxNum = 0, minNum = 1e9+10;
    For(i,1,n){
        mx[i][0] = read(), 
        maxNum = max(maxNum, mx[i][0]);
        minNum = min(minNum, mx[i][0]);
        mx[i + n][0] = mx[i][0];
        mx[i + 2*n][0] = mx[i][0];
    }
    if(maxNum <= minNum*2){
        For(i,1,n) printf("-1 ");
        return 0;
    }
    fori(j,1,MX_LOG) 
        for(int i = 1; i + (1<<j) - 1 <= n3; i ++ ){
            mx[i][j] = max(mx[i][j-1], mx[i + (1<<(j-1))][j-1]);
        }
    int pos = 1;
    int maxx = mx[1][0];
    For(i,1,n){
        while(mx[pos][0]*2 >= maxx) {
            maxx = max(maxx,mx[pos][0]);
            pos++;
        }
        maxx = find(i+1,pos);
        printf("%d ", pos - i);
    }
    return 0;
}