#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int main(){
    int s, t, x; cin>>s>>t>>x;
    bool ok = false;
    if(s > t){
        if(s <= x && x <= 23) ok = true;
        if(0 <= x && x < t) ok = true;
    }else {
        if(s <= x && x < t) ok = true;
    }
    if(ok) puts("Yes");
    else puts("No");
    return 0;
}