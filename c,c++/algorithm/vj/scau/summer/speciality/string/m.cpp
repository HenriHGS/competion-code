#include <cstring>
#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
#define fori(i,x,y) for(int i = (x); i <(y); i ++ )
using namespace std;
const int N = 1e5+10, sigma_size = 26;
int all[2], son[2][N][sigma_size], fail[2][N], cnt[2][N],len[2][N], text[2][N], last[2], tot[2];
int newnode(int l,int cnt[], int son[][sigma_size], int& tot, int len[]){
    for(int i = 0; i < sigma_size; i ++ ) son[tot][i] = 0;
    cnt[tot] = 0, len[tot] = l;
    return tot++;
}
void init(int& last, int& tot, int& all, int text[], int fail[], int cnt[], int  son[][sigma_size], int len[]){
    last = tot = all = 0;
    newnode(0,cnt,son,tot,len),newnode(-1,cnt,son,tot,len);
    text[0] = -1, fail[0] = 1;
}
int getfail(int x, int text[], int& all, int len[], int fail[]){
    while(text[all - len[x] - 1] != text[all]) x = fail[x];
    return x;
}
void add(int w,int text[], int& all, int& last, int son[][sigma_size], int len[], int fail[], int cnt[], int& tot){
    text[++all] = w;
    int x = getfail(last, text,all,len,fail);
    if(!son[x][w]){
        int y = newnode(len[x] + 2, cnt,son,tot,len);
        fail[y] = son[getfail(fail[x],text,all,len,fail)][w];
        son[x][w] = y;
    }
    cnt[last = son[x][w]]++;
}
char str[N];
void sol(){
//    cin>>str;
    cin>>str;
    int n = strlen(str);
    fori(i,0,2)init(last[i],tot[i],all[i],text[i],fail[i],cnt[i],son[i],len[i]);
    fori(k,0,2){
        fori(i,0,n)add(str[i] - 'a',text[k],all[k],last[k],son[k],len[k],fail[k],cnt[k],tot[k]);
        reverse(str,str+n);
    }
    int ans = 0;

    fori(k,0,2){
        cout<<endl;
        fori(i,0,n)cout<<len[k][i+1]<<' ';
    }
   /*
   baacaabbacabb
   1 1 2 1 3 5 7 2 4 3 5 7 0
   bbacabbaacaab
1 2 1 1 3 5 7 4 2 3 5 7 0
   */
  //  cout<<endl;
    fori(i,0,n){
        //cout<<"i: "<<len[0][i+1 + 1]<<' '<<len[1][n - (i+1)] << endl; 
        ans = max(ans, len[0][i+1 + 1] + len[1][n - (i+1) + 1]);
    }
    cout<<ans<<endl;
    //fori(i,0,2)init()
}
int main(){
    sol();
    return 0;
}