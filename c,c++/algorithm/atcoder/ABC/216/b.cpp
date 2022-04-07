#include <string>
#include <iostream>
#include <map>
#define mp make_pair
using namespace std;
string s, t;
map<pair<string,string>,int>ma;
int main(){
    int n;
    cin>>n;
    bool ok = false;
    for(int i  = 0; i < n; i ++ ){
        cin>>s>>t;
        ok |= ma.count(mp(s,t));
        ma[mp(s,t)] = 1;
    }
    if(ok)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}