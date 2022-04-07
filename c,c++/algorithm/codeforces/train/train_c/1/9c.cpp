#include <cstdio>
#include <string>
#include <iostream>
#include <cmath>
#define debug(a) cout<<#a<<": "<<a<<endl
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
void sol(){
    int n;
    scanf("%d", &n);
    string num = to_string(n);
    int tot = num.size();
    int ans = 0;// = pow(2,tot-1);
    //debug(ans);
    bool ok = true;
    fori(i,0,tot){
        if(num[i] == '0'){
            continue;
        }else if(num[i] == '1'){
            ans += pow(2,tot-i-1);
        }else {
            ok = false;
            ans += pow(2,tot-i);
            break;
        }
    }
    if(!ok)ans--;
    printf("%d\n", ans);
}
int main(){
    sol();
    return 0;
}