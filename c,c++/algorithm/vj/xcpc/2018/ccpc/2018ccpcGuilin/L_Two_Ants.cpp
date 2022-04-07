#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
#define db double
using namespace std;
#define debug(a) cout<<#a<<":"<<a<<endl
const db eps = 1e-14;
struct point{
    db x, y;
    point(db x = 0, db y = 0) : x(x), y(y){}
};
int sgn(db x){
    if(fabs(x) < eps) return 0;
    if(x < 0) return -1;
    else return 1;
}
int cmp(db a, db b){
    if(fabs(a-b) < eps) return 0;
    if(a < b) return -1;
    else return 1;
}
typedef point vec;
bool operator == (point a, point b){
    return sgn(a.x - b.x) == 0 && sgn(b.y - a.y) == 0;
}
vec  operator  + (vec a, vec b){
    return vec(a.x + b.x, b.y + a.y);
}
vec  operator  - (point a, point b){
    return vec(a.x - b.x, a.y - b.y);
}
vec operator *(vec a, db p){
    return vec(a.x*p, a.y*p);
}
vec operator /(vec a, db p){
    return vec(a.x/p, a.y/p);
}
db operator *(vec a, vec b){
    return a.x*b.x + a.y*b.y;
}
db operator ^ (vec a, vec b){
    return a.x*b.y - a.y*b.x;
}
db length(vec a){
    return sqrt(a*a);
}
int segment_intersection(point a1, point a2, point b1, point b2){
    int c1 = sgn( (a2-a1) ^ (b1-a1)); int c2 = sgn( (a2-a1) ^ (b2-a1));
    int c3 = sgn( (b2-b1) ^ (a1-b1)); int c4 = sgn( (b2-b1) ^ (a2-b1));
    if(c1*c2 < 0 && c3*c4 < 0) return 2;
    return c1*c2 <= 0 && c3*c4<=0;
}
int relation(point a, point b, point c){
    db c1 = (c - a) ^ (c - b);
    if(sgn(c1) < 0) return -1;
    else if(sgn(c1) > 0) return 1;
    else return 0;
}
bool point_on_segment(point a, point b, point c){
    return sgn( (a-c) * (b-c)) <= 0 && relation(a,b,c) == 0;
}
point get_line_intersection(point a1, point a2, point b1, point b2){
    vec u = a1-b1;
    vec v = (a2 - a1);
    vec w = (b2 - b1);
    db t = (w^u) / (v^w);
    return a1 + v*t;
}
bool parallel(point a1, point a2, point b1, point b2){
    vec u = a2 - a1;
    vec v = b2 - b1;
    return sgn(u^v) == 0;
}
db ix[8], iy[8];
void sol(){
    point wa, wb, ba,bb;
    For(i,1,4) scanf("%lf %lf", &ix[i], &iy[i]);
    wa = point{ix[1],iy[1]};wb = point{ix[2],iy[2]};
    ba = point{ix[3],iy[3]};bb = point{ix[4],iy[4]};
    int seg_cas = segment_intersection(wa,wb,ba,bb);
    if(seg_cas == 2){
        printf("0.000");
    }else if(seg_cas == 1){
        if(relation(wa,wb,ba) == 0 && relation(wa,wb,bb) == 0){
            printf("0.000");
        }else if(point_on_segment(wa,wb,ba) || point_on_segment(wa,wb,bb)){
            printf("inf");
        }else {
            printf("0.000");
        }
    }else {
        if(sgn((wb - wa) ^ (bb - wa)) * sgn((wb - wa) ^ (ba - wa)) <= 0){
            printf("0.000");
            return ;
        }
        bool inf = true;
        db ans;
       // cout<<"wa3"<<endl;
        if(!parallel(wa,ba,wb,bb)){
            point p = get_line_intersection(wa,ba,wb,bb);
            /* debug(p.x);
            debug(p.y); */
            int sg = sgn((wb - wa) ^ (bb - wa));
            if (sgn((wb - wa) ^ (p - wa)) != sg) {
                inf = false;
                ans = abs((wb - wa) ^ (p - wa)) / 2;
            }

            /* db dis_p_wa = length(p-wa);
            db dis_wa_ba = length(wa-ba);
            db dis_ba_p = length(ba-p);
            db dis_p_wb = length(p-wb);
            db dis_wb_bb = length(wb-bb);
            db dis_bb_p = length(bb-p);
            if(cmp(dis_ba_p, dis_wa_ba + dis_p_wa) == 0 && 
                cmp(dis_bb_p, dis_wb_bb + dis_p_wb ) == 0){
                    inf = false;
                    ans = fabs((p-wa) ^ (p-wb));
                } */

           /*  debug(dis_p_wa);
            debug(dis_wa_ba);
            debug(dis_ba_p);
            debug(dis_p_wb);
            debug(dis_wb_bb);
            debug(dis_bb_p); */
                //cout<<"wa3"<<endl;
        }
        if(!parallel(wa,bb,wb,ba)){
            point p = get_line_intersection(wa,bb,wb,ba);
            /* db dis_p_wa = length(p-wa);
            db dis_wa_bb = length(wa-bb);
            db dis_bb_p = length(bb-p);
            db dis_p_wb = length(p-wb);
            db dis_wb_ba = length(wa-ba);
            db dis_ba_p = length(ba-p);
            if(cmp(dis_bb_p, dis_wa_bb + dis_p_wa) == 0 && 
                cmp(dis_ba_p, dis_wb_ba + dis_p_wb) == 0){
                    inf = false;
                    ans = fabs((p-wa) ^ (p-wb));
                }
                 */
            int sg = sgn((wb - wa) ^ (bb - wa));
            if (sgn((wb - wa) ^ (p - wa)) != sg) {
                inf = false;
                ans = abs((wb - wa) ^ (p - wa)) / 2;
            }
        }
        if(inf) printf("inf");
        else printf("%.6f", ans);
    }
}
int main(){
    int tt; scanf("%d", &tt);
    For(cas,1,tt){
        if(cas != 1) puts("");
        printf("Case %d: ",cas);
        sol();
    }
    return 0;
}