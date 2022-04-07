#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
#define x first
#define y second
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
const int N = 1e5+10;
const double PI = acos(-1);
typedef pair<double,double> PDD;
struct Circle{
    PDD p;
    double r;
};
PDD operator * (PDD a, double t){
    return {a.x * t, a.y * t};
}
PDD operator + (PDD a, PDD b){
    return {a.x + b.x, a.y + b.y};
}
PDD operator - (PDD a, PDD b){
    return {a.x - b.x, a.y - b.y};
}
double operator * (PDD a, PDD b){
    return (a.x*b.y - a.y*b.x);
}
PDD operator / (PDD a, double t){
    return {a.x / t, a.y/t};
}
PDD rotate(PDD a, double b){
    return {a.x * cos(b) + a.y * sin(b), -a.x*sin(b) + a.y*cos(b)};
}
const double eps = 1e-12;
int sign(double a){
    if(fabs(a) < eps) return 0;
    if(a < 0) return -1;
    return 1;
}
int dcmp(double a, double b){
    if(fabs(a - b) < eps) return 0;
    if(a < b) return -1;
    return 1;
}
PDD get_line_intersection(PDD p, PDD v, PDD q, PDD w){
    auto u = p - q;
    double t = w*u/(v*w);
    return p + v * t;
}
pair<PDD,PDD> get_normal(PDD a, PDD b){
    return {(a+b)/2, rotate(b - a, PI / 2)};
}
double get_dist(PDD a, PDD b){
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx*dx + dy * dy);
}
Circle get_circle(PDD a, PDD b, PDD c){
    auto u = get_normal(a,b), v = get_normal(a,c);
    auto p = get_line_intersection(u.x,u.y,v.x,v.y);
    return {p, get_dist(p,a)};
}
int n;
PDD q[N];

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i ++ ) scanf("%lf %lf", &q[i].x, & q[i].y);
    random_shuffle(q, q + n);

    Circle c({q[0], 0});
    for(int i = 1; i < n; i ++ ){
        if(dcmp(c.r, get_dist(c.p, q[i])) < 0){
            c = {q[i],0};
            for(int j = 0; j < i; j ++ ){
                if(dcmp(c.r, get_dist(c.p, q[j])) < 0){
                    c = {(q[i] + q[j])/2,
                        get_dist(q[i],q[j])/2};
                    for(int k = 0; k < n; k ++ )
                        if(dcmp(c.r, get_dist(c.p, q[k])) < 0)
                            c = get_circle(q[i],q[j],q[k]);
                }
            }
        }
    }
    printf("%.10lf\n", c.r);
    printf("%.10lf %.10lf\n", c.p.x, c.p.y);;
    return 0;
}