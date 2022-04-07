#include <cstdio>
#include <cstring>
#include <iostream>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define mst(x,a) memset(x,a,sizeof(x))
using namespace std;
const int N = 2e5+10;
char s[N], t[N];
int L[N], R[N];
int pos[N];
int main(){
//    ios::sync_with_stdio(0);
    cin>>(s + 1) >> (t + 1);
    int ns = strlen(s + 1), nt = strlen(t + 1);
    int p = 1;
    For(i,1,ns){
        if(s[i] == t[p]  && p <= nt){
            L[i] = pos[s[i] - 'a'] = p ++ ;
        }else L[i] = pos[s[i] - 'a'];
    }
    p = nt;
    For(i,0,26) pos[i] = ns+1;
    For(i,0,ns)R[i] = ns+1;
    for(int i = ns; i >= 1; i -- ){
        if(s[i] == t[p] && p >= 1){
            R[i] = pos[s[i]-'a'] = p--;
        }else R[i] = pos[s[i]-'a'];
    }
    bool ok = true;
    For(i,1,ns){
        //cout<<L[i]<<' '<<R[i]<<endl;
        if(L[i] < R[i]){
           puts("No");// cout<<"No"<<endl;
            return 0;
        }
    }
    puts("Yes");
   // cout<<"Yes"<<endl;
    return 0;
}