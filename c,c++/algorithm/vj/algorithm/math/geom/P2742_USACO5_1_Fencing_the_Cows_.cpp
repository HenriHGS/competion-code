#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int N = 1e5+10;
typedef double db;
struct Point{
    db x, y;
    bool operator < (const Point &a)const{
        if(x == a.x) return y < a.y;
        return x < a.x;
    }
    Point(db x = 0, db y = 0): x(x), y(y) {}
} p[N];
typedef Point Vector;
Vector operator +(Vector a, Vector b){
    return Vector(a.x + b.x, a.y + b.y);
}
Vector operator -(Point a, Point b){
    return Vector(a.x - b.x, a.y - b.y);
}
Vector operator *(Vector a, db p){
    return Vector(a.x*p, a.y*p);
}
Vector operator /(Vector a, db p){
    return Vector(a.x/p, a.y/p);
}
const db eps = 1e-6;
int sign(db x){
    if(fabs(x) < eps) return 0;
    else return x < 0 ? -1 : 1;
}
bool operator == (const  Point &a, const Point &b){
    return sign(a.x-b.x) == 0 && sign(a.y - b.y) == 0;
}
db Cross(Vector A, Vector B){
    return A.x*B.y - A.y*B.x;
}
db Area2(Point a, Point b, Point c){
    return Cross(b - a, c - a);
}
Point stk[N];
int top = 0;
int convex_hull(Point* p, Point *h, int n){
    sort(p,p+n);
    int tot = 0;
    //h[tot++] = p[0];
    for(int i = 0; i < n; i ++ ){
        while(top > 1 && Cross(h[top] - h[top - 1], p[i] - h[top-1]) <= 0)top--;
        h[++top] =  p[i];
    }
    int m = top;
    for(int i = n - 2; i >= 0; i -- ){
        while(top - m > 0 && Cross(h[top] - h[top - 1], p[i] - h[top-1]) <= 0) top --;
        h[++top] = p[i];
    }
    if(n > 1) top--;
    return top;
}
int n;
db getDis(Point a, Point b){
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i ++ ){
        db x, y; scanf("%lf %lf", &x, &y);
        p[i] = {x,y};
    }
    int tot = convex_hull(p,stk,n);
    db ans = 0;
    for(int i = 1; i <= tot; i ++ ){
        int u = i, v = i + 1;
        if(v > tot) v = 1;
        ans += getDis(stk[u], stk[v]);
    }
    printf("%.2f\n", ans);
    return 0;
}