#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
#define sz(a) (int)a.size()
#define ALL(a) a.begin(), a.end()
#define mst(x,a) memset(x,a,sizeof(x))
#define pb push_back
using namespace std;
typedef double db;
typedef long long LL;
typedef pair<int,int> pa;
const int maxn = 100000 + 5;
const db eps = 1e-6;
struct Obj{
    db len;
    string name;
    int a;
    bool operator < (const Obj& x) const {
        return len<x.len;
    }
};
int main() {
    int n;
    cin>>n;
    vector<Obj> v;
    For(i,1,n){
        string s;
        cin>>s;
        int a;
        cin>>a;
        if(s[1] == 'u')v.pb({(db)a,s,a});
        else v.pb({a*sqrt(2),s,a});
    }
    sort(ALL(v));
    bool ok = true;
    fori(i,1,n){
        if(v[i-1].name[1] != 'u' && v[i].name[1] == 'u') ok &= v[i].a>=2*v[i-1].a;
    }
    if(ok){
        fori(i,0,n)cout<<v[i].name <<' ' <<v[i].a <<  endl;
    }else {
        cout<<"impossible";
    }
    return 0;
}