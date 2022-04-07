#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
int n, s;
bool par(int x, int b){
    string s = "";
    while(x){
        s += '0' + x%b;
        x /= b;
    }
    return (s == string(s.rbegin(),s.rend()));
}
bool check(int x){
    int cnt = 0;
    for(int i = 2; i <= 10; i ++ )
        cnt += par(x,i);
    //cout<<cnt<<endl;
    return cnt >= 2;
}
int main(){
    ios::sync_with_stdio(0);
    cin>>n>>s;
    for(int i = 1, x = s+1; i <= n; i ++ ){
        while(!check(x))x++;
        cout<<x<<endl;
        x++;
    }
    return 0;
}
