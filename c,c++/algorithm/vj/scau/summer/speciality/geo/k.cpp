#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

#define X first
#define Y second
#define pb push_back
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
typedef pair<int,int> point;
typedef long long ll;
const int N = 1e3+10;
point p[N];
int vis[N];
int main(){
    int n;
    scanf("%d", &n);
    vector<point>v;
    For(i,1,n){
        p[i].X = i;
        scanf("%d",&p[i].Y);
    }
    //case1: only 1
    ll a, b, c;
    a = p[3].Y - p[2].Y, b = -(p[3].X - p[2].X), c = -(ll)p[3].Y*b - p[3].X*a;
    if(a*p[1].X + b*p[1].Y + c != 0){
        bool ok = true;
        For(i,1,n) if(a*p[i].X + b*p[i].Y + c != 0) v.pb(p[i]);//ok &= a*p[i].X + b*p[i].Y + c == 0;
            if(v.empty()){
            //printf("debug2:\n");
            puts("No");
            return 0;
        }else if(v.size() == 1){
            puts("Yes");
            return 0;
        }
        ll prea = a, preb = b;
        a = v[1].Y - v[0].Y, b = -(v[1].X - v[0].X), c = -(ll)v[1].Y*b - v[1].X*a;
        ok = true;
        fori(i,0,v.size()){
            ok &= a*v[i].X + b*v[i].Y + c == 0;
        }
        if(ok && a*preb == b*prea){
            puts("Yes");
            return 0;
        }
    }
    //case2: 1,2,3
    v.clear();
    a = p[2].Y - p[1].Y, b = -(p[2].X - p[1].X), c = -(ll)p[2].Y*b - p[2].X*a;
    For(i,1,n){
        if(a*p[i].X + b*p[i].Y + c != 0) v.pb(p[i]);
    }
    if(v.empty()){
        //printf("debug2:\n");
        puts("No");
        return 0;
    }else if(v.size() == 1){
        puts("Yes");
        return 0;
    }
    ll prea = a, preb = b;
    a = v[1].Y - v[0].Y, b = -(v[1].X - v[0].X), c = -(ll)v[1].Y*b - v[1].X*a;
    bool ok = true;
    fori(i,0,v.size()){
        ok &= a*v[i].X + b*v[i].Y + c == 0;
    }
    if(ok && a*preb == b*prea){
        puts("Yes");
        return 0;
    }
    //case3: 1,other
    a = v[0].Y - p[1].Y, b = -(v[0].X - p[1].X), c = -(ll)v[0].Y*b - v[0].X*a;
   // printf("debug p[1] = (%d,%d), v[0] = (%d,%d):\n",p[1].X,p[1].Y, v[0].X,v[0].Y);
    v.clear();
    For(i,1,n){
        if(a*p[i].X + b*p[i].Y + c != 0) v.pb(p[i]);
    }
    if(v.empty()){
        puts("No");
         //printf("debug3 :\n");
        return 0;
    }else if(v.size() == 1){
        puts("Yes");
        return 0;
    }
     prea = a, preb = b;
    a = v[1].Y - v[0].Y, b = -(v[1].X - v[0].X), c = -(ll)v[1].Y*b - v[1].X*a;
    ok = true;
    fori(i,0,v.size()){
        ok &= a*v[i].X + b*v[i].Y + c == 0;
    }
    if(ok && a*preb == b*prea){
        puts("Yes");
        return 0;
    }
  //  printf("debug end:\n");
    puts("No");
    return 0;
}
	  		  	   		 		 			 		 	  	