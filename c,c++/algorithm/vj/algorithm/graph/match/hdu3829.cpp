#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#define debug(a) cout<<#a<<":"<<a<<endl
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
const int N = 510, M = 510*510*2;
int e[M], ne[M], h[N], idx;
int match[N];
bool st[N];
void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
    e[idx] = a, ne[idx] = h[b], h[b] = idx++;
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
int c,d,p;
int like[N], dislike[N];
void sol(){
    fori(i,0,idx){
        int a = e[i];
        int b = e[i^1];
        h[a] = h[b] = -1;
    }
    idx = 0;
    scanf("%d %d %d", &c, &d, &p);
    For(i,1,p){
        char ch;
        int num, ad;
        ch = getchar();
        while(!isalpha(ch)) ch = getchar();
        scanf("%d", &num);
        ad = ch =='D'?c:0;
        like[i] = ad+num;
        //  
        ch = getchar();
        while(!isalpha(ch)) ch = getchar();
        scanf("%d", &num);
        ad = ch =='D'?c:0;
        dislike[i] = ad+num;
        //debug(num);
        fori(j,1,i){
            if(like[i] == dislike[j] || dislike[i] == like[j]) add(i,j);
        }
        match[i] = 0;
    }
    int mx = 0;
    For(i,1,p){
        memset(st,0,sizeof st);
        if(find(i)) mx++;
    }
  //  debug(mx);
    printf("%d\n", p - mx/2);
}
int main(){
    memset(h,-1,sizeof h);
    int tt;
    scanf("%d", &tt);
    while(tt--) sol();
    return 0;
}