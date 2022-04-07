#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    int x;
    cin>>x;
    if(x < 40) cout<<40-x<<endl;
    else if(x < 70)cout<<70-x<<endl;
    else if(x < 90) cout<<90-x<<endl;
    else cout<<"expert";
}