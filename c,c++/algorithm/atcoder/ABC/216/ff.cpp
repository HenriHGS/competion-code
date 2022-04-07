#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
using namespace std;
vector<pair<int,int>>p;
int main(){
    int n;
    scanf("%d", &n);
    For(i,1,n){
        int a, b;
        scanf("%d %d",&a, &b);
        p.pb({a,b});
    }
    sort(p.begin(),p.end());
    for(int i = 0; i < p.size(); i ++ ) cout<<p[i].first<<' ';
    cout<<endl;
    for(int i = 0; i < p.size(); i ++ ) cout<<p[i].second<<' ';
    return 0;
}