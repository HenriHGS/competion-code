#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#define x first
#define y second
using namespace std;



int main(){
    ios::sync_with_stdio(0);
    int n, k;
    cin>>n>>k;
    vector<pair<int,int>> a(n);
    vector<int>ans(n);
    for(int i = 0; i < n; i ++ ){
        int val;
        a[i].y = i;
        for(int j = 0; j < 3; j ++ ){
            cin>>val;
            a[i].x += val;
        }
    }    
    sort(a.begin(), a.end());
    for(int i = 0; i < n; i ++ ){
        auto tmp = a[i];
        tmp.x += 300; tmp.y = 10000000;
        int pos = upper_bound(a.begin(), a.end(), tmp) - a.begin();
        pos--;
        if(pos >= n-k) ans[a[i].y] = true;
    }
    for(int i = 0; i < n; i ++ ) {
        if(ans[i]) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}