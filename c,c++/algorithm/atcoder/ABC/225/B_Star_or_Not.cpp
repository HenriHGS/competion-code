#include <cstdio>
#include <string>
#include <iostream>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
const int N = 1e5+10;
int du[N];
int main(){
    int n; cin>>n;
    For(i,1,n-1){
        int a, b;
        cin>>a>>b;
        du[a]++,du[b]++;
    }
    bool ok = false;
    For(i,1,n) ok |= du[i] == n - 1;
    if(ok) puts("Yes");
    else puts("No");
    return 0;
}