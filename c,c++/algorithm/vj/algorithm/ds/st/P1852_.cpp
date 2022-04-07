#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
using namespace std;
struct node{
    int a, b, c;
    bool operator == (const node& x) const{
        return x.a == a && x.b == b && x.c == c;
    }
    bool operator != (const node& x) const{
        return !((*this) == x);
    }
}ra, rb, a, b;
int read(){
    char ch = getchar(); int f = 0, x = 0;
    while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
    while(isdigit(ch)) x = x*10 + ch - '0', ch = getchar();
    return f ? -x : x;
}
node readn(){
    int v[3];
    for(int i = 0; i < 3; i ++ ) v[i] = read();
    sort(v,v+3);
    node res;
    res = {v[0],v[1],v[2]};
    return res;
}
const int INF = 1e9+10;
node step(node x, int limit, int& res){
    int  k;
    res = 0;
    for(res; limit; res += k){
        int d1 = x.b - x.a, d2 = x.c - x.b;
        if(d1 == d2) return x;
        if(d1 < d2){
            k = min((d2 - 1) / d1, limit);
            x.a += k*d1, x.b += k * d1;
            limit -= k;
        }else {
            k = min((d1 - 1) / d2, limit);
            x.b -= k* d2;
            x.c -= k * d2;
            limit -= k;
        }
    }
    return x;
}
int main(){
    a = readn();
    b = readn();
    int dep1 = 0, dep2 = 0;
    ra = step(a,INF,dep1);
    rb = step(b,INF,dep2);
    if( ra != rb ) {
        puts("NO");
        return 0;
    }
    if(dep1 < dep2){
        swap(dep1,dep2);
        node tmp = a;
        a = b;
        b = tmp;
    }
    int ans2 = 0, ans1 = 0;
    a = step(a,dep1 - dep2,ans2);
    int L = 0, R = dep2;
    while(L <= R){
        int mid = L + R >> 1;
        int t1,t2;
        if(step(a,mid,t1) == step(b,mid,t2))ans1 = mid, R = mid - 1;
        else L = mid + 1;
    }
    puts("YES");
    printf("%d", ans1*2+ans2);
    return 0;
}