#include <cstring>
#include <string>
#include <iostream>
#include <map>
using namespace std;
typedef long long LL;
const int N = 1e5+10;
const LL mod[2] = {(int)(1e9+7), (int)(1e9+9)};
const LL q[2] = {131, 13331};
LL p[N][2];
LL ha[N][2];
void init(){
    p[0][0] = p[0][1] = 1;
    for(int i = 1; i < N; i ++ )for(int j = 0; j < 2; j ++ ) p[i][j] = (LL)p[i-1][j]*q[j]%mod[j];
}
LL get(string s, int j){
    int res = 0;
    for(auto ch: s) res = ((LL)res*q[j] % mod[j] + ch) % mod[j];
    return res;
}
void sol(){
    int n;
    cin>>n;
    string s;
    init();
    int ans = 0;
    map<int,int> ma;//map<pair<int,int>,int>ma;
    for(int i = 0; i < n; i ++ ){
        cin>>s;
        int x = get(s,0);///auto x = make_pair(get(s,0), get(s,1));
        if(!ma.count(x)) ans++;
        ma[x]++;
    }
    cout<<ans<<endl;
}

int main(){
    ios::sync_with_stdio(0);
    sol();
}