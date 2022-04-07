#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

#define db double
const db eps = 1e-8;
struct Point{
    db x, y;
    Point(db x = 0, db y = 0):x(x),y(y){}
};
int sign(db x){
    if(fabs(x) < eps) return 0;
    if(x < 0) return -1;
    return 1;
}
int cmp(db x, db y){
    if(fabs(x-y) < eps) return 0;
    if(x < y) return -1;
    return 1;
}
typedef Point Vector;
Vector operator + (Vector A, Vector B){return Vector(A.x+B.x, A.y + B.y);}
Vector operator - (Point a, Point b){ return Vector(a.x - b.x, a.y - b.y);}
Vector operator * (Vector A, db p){ return Vector(A.x*p, A.y*p);}
Vector operator / (Vector A, db p){ return Vector(A.x/p, A.y/p);}

bool operator < (const Point&a, const Point& b){
    return a.x < b.x || sign(a.x-b.x) == 0 && a.y < b.y;
}
bool operator == (const Point&a, const Point&b){
    return sign(a.x-b.x) == 0 && sign(a.y-b.y) == 0; 
}

db Dot(Vector A, Vector B){
    return A.x*B.x + A.y*B.y;
}
db get_length(Vector A){
    return sqrt(Dot(A,A));
}
db Angle(Vector A, Vector B){
    return acos(Dot(A,B)/get_length(A)/get_length(B));
}
db Cross(Vector A, Vector B){
    return A.x*B.y - A.y*B.x;
}
// c 在最右边
db Area2(Point A, Point B, Point C){
    return Cross(B-A,C-A);
}
//rad是弧度
Vector Rotate(Vector A, db rad){
    return Vector(A.x*cos(rad) - A.y*sin(rad), A.x*sin(rad) + A.y*cos(rad));
}
//计算法线
Vector Normal(Vector A){
    db L = get_length(A);
    return Vector(-A.y/L,A.x/L);
}
/* Line */
Point GetLineIntersection(Point p, Vector v, Point q, Vector w){
    Vector u = p - q;
    db t = Cross(w,u)/Cross(v,w);
    return p + v*t;
}
/* 点到直线 */
db distance_to_line(Point p, Point a, Point  b){
    Vector v1 = b - a, v2 = p - a;
    return fabs(Cross(v1,v2)/get_length(v1));
}
db disttance_to_segment(Point p, Point a, Point b){
    if(a == b) return get_length(p - a);
    Vector v1 = b - a, v2 = p - a, v3 = p - b;
    if(sign(Dot(v1,v2)) < 0) return get_length(v2);
    if(sign(Dot(v1,v3)) > 0) return get_length(v3);
    return distance_to_line(p,a,b); 
}
Point get_line_projection(Point p, Point a, Point b){
    Vector v = b - a;
    return a + v * (Dot(v,p-a)/Dot(v,v));
}
bool on_segment(Point p, Point a, Point b){
    return sign(Cross(p-a, p - b)) == 0 && sign(Dot(p-a, p - b)) <= 0;
    // = 表示包含端点；
}
bool segment_intersection(Point a1, Point a2, Point b1, Point b2){
    db c1 = Cross(a2 - a1, b1 - a1), c2 = Cross(a2-a1,b2-a1);
    db c3 = Cross(b2-b1,a2-b1), c4 = Cross(b2-b1,a1-b1);
    return sign(c1) * sign(c2) <= 0 && sign(c3)*sign(c4)<=0;
    // = 表示包含端点；
}//跨立实验
int main(){ 
    return 0;
}