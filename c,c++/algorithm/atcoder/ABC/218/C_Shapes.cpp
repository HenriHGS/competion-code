#include <cstdio>
#include <iostream>
#include <cstring>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
const int N = 600+10;
char ans[N][N];
char g1[N][N], g2[N][N], g[N][N];
int main(){
    int n; scanf("%d", &n);
    For(i,1,n) scanf("%s", g[i]+1);
    For(i,1,n) scanf("%s", ans[i]+1);
    int cnt[2]{};
    fori(i,0,N)fori(j,0,N) g1[i][j] = g2[i][j] = '.';
    For(i,1,n)For(j,1,n) if(g[i][j] == '#') cnt[0]++;
    For(i,1,n)For(j,1,n) if(ans[i][j] == '#') cnt[1]++;
    if(cnt[0] != cnt[1]){
        puts("No");
        return 0;
    }
    pair<int,int> st1(1000,1000),st0(n,n);
    For(i,1,n)For(j,1,n) if(ans[i][j] == '#') st0 = min(st0,pair<int,int>(i,j));
    /* For(i,1,n) For(j,1,n){
        int ii = j+200, jj =  (n - i) + 1 + 200;
        g1[ii][jj] = g[i][j];
        if(g[ii][jj] == '#'){
            st1 = min(st1,pair<int,int>(ii,jj));
        }
    } */
    fori(rot,0,4){
        st1 = {n,n};
        fori(i,0,N)fori(j,0,N) g2[i][j] = '.';
        For(i,1,n) For(j,1,n){
            //int ii = j+200, jj =  (n - i) + 1 + 200;
            int ii = j, jj =  (n - i) + 1;
            g1[ii][jj] = g[i][j];
            g2[ii+200][jj+200] = g[i][j];
            if(g1[ii][jj] == '#'){
                st1 = min(st1,pair<int,int>(ii,jj));
            }
        }
        For(i,1,n)For(j,1,n) g[i][j] = g1[i][j];
        /* printf("rot = %d\n", rot);
        For(i,1,n)For(j,1,n){
            printf("%c",g[i][j]);
            if(j == n) printf("\n");
        } */
        int i = st1.first, j = st1.second;
        int ii = i - st0.first, jj = j - st0.second;
        ii = 201 + ii , jj = 201 + jj;
        bool ok = true;
       // cout<<ii<<' '<<jj<<endl; 
        For(i,1,n)For(j,1,n){
            ok &= g2[ii][jj] == ans[i][j];
           /*  cout<<g2[ii][jj];
            if(j==n)cout<<endl; */

            if(j == n)ii++, jj = jj - n + 1;
            else jj++;
        }
        if(ok) {
            puts("Yes");
            return 0;
        }
    }
     /* printf("left\n");
    For(i,1,n)For(j,1,n) {
        cout<<g1[i+200][j+200];
        if(j == n) cout<<endl;
    }
    printf("rigth\n");
    For(i,1,n)For(j,1,n) {
        cout<<g2[i+200][j+200];
        if(j == n) cout<<endl;
    }  */
    /* bool succ = false;
    //1
    {
       
    }
    //2
     {
        int i = st2.first - 200, j = st2.second - 200;
        int ii = st0.first - i, jj = st0.second - j;
        ii = 201 + ii , jj = 201 + jj;
        bool ok = true;
       // cout<<ii<<' '<<jj<<endl;
        For(i,1,n)For(j,1,n){
            ok &= g2[ii][jj] == ans[i][j];

           /*  cout<<g2[ii][jj];
            if(j==n)cout<<endl; */

          /*   if(j == n)ii++, jj = jj - n + 1;
            else jj++;
        }
        if(ok){
            puts("Yes");
            return 0;
        }
    }  */
    puts("No");
    return 0;
}