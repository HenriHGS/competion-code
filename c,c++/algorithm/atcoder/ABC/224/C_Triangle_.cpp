#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>
#define x first
#define y second
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
using namespace std;
typedef long long ll;
const int N = 310;
typedef pair<int,int>PII;

struct point{
    ll x, y;
}p[N];
typedef point vec;
vec operator - (const point&a, const  point& b){
    return vec{a.x-b.x,a.y-b.y};
}
ll cross(vec v1, vec v2){
    return v1.x * v2.y - v1.y*v2.x;
}
bool online(point p1, point p2, point p3){
    return abs(cross(p2-p1, p3 - p2)) == 0;
}

int main(){
    ios::sync_with_stdio(0);
    int n; cin>>n;
    For(i,1,n) cin>>p[i].x>>p[i].y;
    int ans = n*(n-1)*(n-2)/2/3;
    For(i,1,n)For(j,i+1,n)For(k,j+1,n) ans -= online(p[i],p[j],p[k]);
    cout<<ans<<endl;
    return 0;
}