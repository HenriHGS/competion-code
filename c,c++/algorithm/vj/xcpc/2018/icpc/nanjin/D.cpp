#include <bits/stdc++.h>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
const double eps = 1e-8;
const int inf = 0x3f3f3f3f;
const double start_T = 1000;
struct point3d{ 
    double x, y, z;
} Data[150];
int n;
double dis(point3d a, point3d b){
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y-b.y)*(a.y-b.y) + (a.z - b.z)*(a.z-b.z));
}
double solve(){
    double step = start_T, ans = inf, mt;
    point3d z; 
    z.x = z.y = z.z = 0;
    int S = 0;
    while(step > eps){
        for(int i = 0; i < n; i ++ ){
            if(dis(z,Data[S]) < dis(z,Data[i])) S = i;
        }
        mt = dis(z,Data[S]);
        ans = min(ans,mt);
        z.x += (Data[S].x - z.x) / start_T*step;
        z.y += (Data[S].y - z.y) / start_T * step;
        z.z += (Data[S].z - z.z) / start_T * step;
        step *= 0.97;
    }
    return ans;
}
void sol(){
    double ans;
    scanf("%d", &n);
    fori(i,0,n) scanf("%lf %lf %lf", &Data[i].x, &Data[i].y, &Data[i].z);
    ans = solve();
    printf("%.8f\n", ans);
} 

int main(){
    //int tt; scanf("%d", &tt);
   // while(tt--) sol();
   sol();
    return 0;
}