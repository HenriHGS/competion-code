#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <numeric>
#include <algorithm>
#include <vector>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int N = 2e5+10;

int ans[N];
vector<PII>p;

int main(){
    ios::sync_with_stdio(0);
    int n;
    cin>>n;
    fori(i,0,n){
        int a, b;
        cin>>a>>b;
        p.pb({a,0});
        p.pb({a + b - 1,1});
    }
    sort(p.begin(),p.end());
    int sum = 0, l = -1;
    for(int i = 0; i < p.size(); ){
        int r = p[i].fi;
        if(l != -1){
            ans[sum] += r - l - 1;
        }
        l = p[i].fi;
        int j = i;
        while(j < p.size() && p[j].se == 0 && p[j].fi == l)j++;
        sum += j - i;
        ans[sum] ++;
        i = j;
        while(j < p.size() && p[j].se == 1 && p[j].fi == l)j++;
        sum -= j - i;
        i = j;
    }
    For(i,1,n) cout<<ans[i]<<' ';
    return 0;
}