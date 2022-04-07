#include <string>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
int main(){
    ll k;
    cin>>k;
    string a, b;
    cin>>a>>b;
    ll A = 0, B = 0;
    ll base = 1;
    for(int i = 0; i < a.size(); i ++ ){
        A = A * k + a[i] - '0';
        base *= k;
    }
    for(int i = 0; i < b.size(); i ++ ){
        B = B*k + b[i] - '0';
    }
    //cout<<A<<' '<<B<<endl;
    cout<<A*B<<endl;
    return 0;
}