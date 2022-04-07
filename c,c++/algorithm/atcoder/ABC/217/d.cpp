#include <cstdio>
#include <set>
#include <algorithm>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i <(y); i ++ )
using namespace std;
struct line{
    int l, r;
    int len;
    bool operator < (const line& x)const{
        return l < x.l;
    }
};
int main(){
    int L, q;
    scanf("%d %d", &L, &q);
    set<line> s;
    s.insert(line{0,L,L});
    while(q--){
        int c, x;
        scanf("%d %d", &c, &x);
        if(c == 1){
            auto it = s.lower_bound(line{x,0,0});
            if(it == s.end() || it->l >= x) it--;
            auto ll = *it;
            auto rr = *it;
            s.erase(it);
            int l = ll.l, r = ll.r;
            int len1 = x - l, len2 = r - x;
            ll = line{l,x,len1};
            rr = line{x,r,len2};
            s.insert(ll);
            s.insert(rr);
        }else {
             auto it = s.lower_bound(line{x,0,0});
             if(it == s.end() || it->l >= x) it--;
             auto ll = *it;
             printf("%d\n", ll.len);
        }
    }
    return 0;
}