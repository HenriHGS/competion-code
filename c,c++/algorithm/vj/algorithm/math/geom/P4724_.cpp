#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#define pb push_back
#define sz(a) (int)a.size()
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
const int N = 2000+10;
typedef double db;
struct point{
    db x, y, z;
    point(db _x = 0, db _y = 0, db _z = 0):x(_x),y(_y), z(_z){}
} p[N];
typedef point vec;
vec operator +(const vec& a, const vec& b){
    return vec(a.x + b.x, a.y + b.y, a.z + b.z);
}
vec operator - (const point& a, const point& b){
    return vec(a.x - b.x, a.y - b.y, a.z - b.z);
}
vec operator * (const vec& a, const db& p){
    return vec(a.x*p,a.y*p, a.z*p);
}
vec operator / (const vec& a, const db& p){
    return vec(a.x/p,a.y/p, a.z/p);
}
const db eps = 1e-8;
int sign(db x){
    if(fabs(x) < eps) return 0;
    return x < 0? -1: 1;
}
bool operator == (const point &a, const point& b){
    return sign(a.x - b.x) == 0 && sign(b.y - a.y) == 0 && sign(a.z - b.z) == 0;
}
db dot(const vec& a,const vec& b){
    return a.x*b.x + a.y*b.y + a.z*b.z;
}
db length(const vec&a){
    return sqrt(dot(a,a));
}
db angle(const vec& a, const vec&b){
    return acos( dot(a,b)/length(a)/length(b) );
}
vec cross(const vec& a, const vec&b){
    return vec(a.y*b.z -a.z*b.y, a.z*b.x - a.x*b.z, a.x*b.y - a.y*b.x); 
}
db area2(const point& a, const point& b, const point& c){
    return length( cross(b-a,c-a) );
}

template<class T> using vc = vector<T>;
template<class T> using vvc = vc<vc<T>>;
struct face{
    int v[3];
    vec normal(point* p){
        return cross(p[v[1]] - p[v[0]], p[v[2]] - p[v[0]]);
    }
    bool cansee(point*p, int i){
        return  dot(p[i] - p[v[0]], normal(p))  > 0 ? 1 : 0;
    }
};
using vf = vc<face>;
db rand01() { return rand() / (db) RAND_MAX; }
db randeps() { return (rand01() - 0.5) * eps; }
void randp(point &p1){ 
    p1.x +=  randeps();
    p1.y +=  randeps();
    p1.z += randeps();
}
//[-eps/2, +eps/2]
bool vis[N][N];
vf convex_hull(point*p, int n){
    vf cur;
    cur.push_back({0,1,2});
    cur.push_back({2,1,0});
    for(int i = 3; i < n; i ++ ){
        vf next;
        for(int j = 0; j < cur.size(); j ++ ){
            face & f = cur[j];
            int res = f.cansee(p,i);
            if(!res) next.push_back(f);
            for(int k = 0; k < 3; k ++ ) vis[f.v[k]][f.v[(k+1)%3]] = res;
        }
        for(int j = 0; j < cur.size(); j ++ ){
            for(int k = 0; k < 3; k ++ ){
                int a = cur[j].v[k], b = cur[j].v[ (k + 1) % 3];
                if(vis[a][b] != vis[b][a] && vis[a][b])
                    next.push_back({a,b,i});
            }
        }
        cur = next;
    }
    return cur;
}
int n;
int main(){
    scanf("%d", &n);
    fori(i,0,n){
        db x, y, z;
        scanf("%lf %lf %lf", &x, &y, &z);
        p[i] = {x,y,z}; randp(p[i]);
    }
    vf cur = convex_hull(p,n);
    db ans = 0;
    fori(i,0,cur.size()){
        int id1 = cur[i].v[0];
        int id2 = cur[i].v[1];
        int id3 = cur[i].v[2];
        ans += area2(p[id1], p[id2], p[id3])/2;
    }
    printf("%.3lf\n", ans);
    return 0;
}