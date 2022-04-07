#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <map>
#define fi first
#define se second
#define sz(a) (int)a.size()
#define pb push_back
using namespace std;
void sol(){
    int n;
    cin>>n;    //    scanf("%d", &n);
    vector<int>a(n);
    for(int i = 0; i < n; i ++ )cin>>a[i];
    sort(a.begin(), a.end());
    map<int,int> ma;
    for(int i = 1; i < n; i ++ ){
        ma[a[i]-a[i-1]]++;
    }
    vector<pair<int,int>>v;
    for(auto x:ma){
        v.pb(x);
    }
    if(n == 1)cout<<-1<<endl;
    else if(sz(v) == 1){
        if(v[0].fi == 0){
            cout<<1<<endl;
            cout<<a[0]<<endl;
        }else {
            int d = v[0].fi;
            vector<int>ans;
//            cout<<2<<endl;
  //          cout<<a[0]-d<<' '<<a[n-1]+d<<endl;
            ans.pb(a[0]-d), ans.pb(a[n-1]+d);
            if(v[0].se == 1 && v[0].fi % 2== 0)ans.pb(a[0] + a[n-1]>>1);
            sort(ans.begin(),ans.end());
            cout<<sz(ans)<<endl;
            for(auto x: ans)cout<<x<<' ';
        }
    }else if(sz(v) == 2 && v[1].se == 1 && v[0].fi*2 == v[1].fi){
        int d2 = v[1].fi;
        int hal = 0;
        for(int i = 1; i < n; i ++ ){
            if(a[i] - a[i-1] == d2){
                hal = a[i-1] + a[i]>>1;
                break;
            }
        }
        cout<<1<<endl;
        cout<<hal<<endl;
    }else cout<<0<<endl;
}
int main(){
    ios::sync_with_stdio(0);
    sol();
    return 0;
}