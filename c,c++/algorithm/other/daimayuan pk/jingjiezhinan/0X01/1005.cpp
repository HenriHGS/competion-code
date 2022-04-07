#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 1e5+10;
const int sigma_size = 31;
int mbit[sigma_size], mlen = 0;
char op[maxn][6];
int  t[maxn];
int n, m;
void cal(int& x, int k){
    for(int j = 1; j <= n; j ++ ) {
        if(strcmp(op[j],"AND") == 0) {
             x &= (t[j]>>k & 1);
        }else if(strcmp(op[j],"OR") == 0){
             x |= (t[j]>>k & 1);
        }else if(strcmp(op[j],"XOR") == 0){
             x ^= (t[j]>>k &1);
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i = 1; i <= n; i ++ ) cin>>op[i]>>t[i];
    int x = m;
    while(x){
        mbit[mlen++] = x % 2;
        x /= 2; 
    }
    if(mlen)mlen--;
    int ans = 0;
    bool limit = true;
    for(int i = 30; i >= 0; i -- ){
        if(i > mlen){
            int x = 0;
            cal(x,i);
            ans |= (x<<i) ;
        }else if(limit){
            int x0 = 0, x1 = 1;
            cal(x0,i); cal(x1,i);
            if(mbit[i] == 1){
                if(x1) ans |= (1<<i);
                if(x0) limit = false, ans |= (1<<i);
                if(x1 == 0 && x0 == 0) limit = false;
            }else {
                if(x0) ans |= (1<<i);
            }
        }else {
            int x0 = 0, x1 = 1;
            cal(x0,i); cal(x1,i);
            if(x1|x0) ans |= (1<<i);
        }
    }
    cout<<ans<<endl;
    return 0;
}
// m = 10001001
// src        wa       ans
// 310984152 301991936 304367616
//0001101110111100100100010100100
//0000000000010000000000000100100
//0000000000010010001001000100100