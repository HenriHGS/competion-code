#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

#define db double
const db eps = 1e-6;
int sign(db x){
    if(fabs(x) < eps) return 0;
    if(x < 0) return -1;
    return 1;
}
int cmp(db a, db b){
    if(fabs(a-b) < eps) return 0;
    if(a < b) return -1;
    return 1;
}
db getDis(db x1, db y1, db x2, db y2){
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}
int main(){
    db x1,y1,x2,y2,R;
    db x, y, r;
    scanf("%lf%lf%lf%lf%lf", &R, &x1, &y1, &x2, &y2);
    db flag = (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1) - R*R;
    if(sign(flag) >= 0){
        printf("%.6f %.6f %.6f",x1,y1,R);
        return 0;
    }
    db dis_cen = getDis(x1,y1,x2,y2);
    db dis = dis_cen + R;
    r = dis/2;
    x = x2, y = y2;
    db k1, k2;
    if(cmp(x1,x2) == 0){
        //k1 = k2 = 1; 
        k1 = 0;
        k2 = 1;
    }else {
        db k = (y1-y2)/(x1-x2);
        db rad = atan(k);
        k1 = fabs(cos(rad));
        k2 = fabs(sin(rad));
    }
    if(cmp(x1,x2) >= 0)x += r*k1;
    else x -= r*k1;
    if(cmp(y1,y2) >= 0) {
//        printf("debug: y1 = %.6f, y2 = %.6f\n",y1,y2);
        y += r*k2;
    }else {
        y -= r*k2;
  //      printf("debug2: y1 = %.6f, y2 = %.6f, k2 = %.6f\n",y1,y2,k2);
    }
    printf("%.6f %.6f %.6f",x,y,r);
}
/*
(-2,-2)
5 3 3 1 1
(-2,0)
5 3 3 1 3
(-2,2)
5 3 3 1 5
(0,2)
5 3 3 3 5
(2,2)
5 3 3 5 5
(2,0)
5 3 3 5 3
(2,-2)
5 3 3 5 1
(0,-2)
5 3 3 3 1
*/