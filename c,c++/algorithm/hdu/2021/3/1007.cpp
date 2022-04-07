#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
struct color{
    int r, g, b;
    void init(char *s){
        r = g = b = 0;
        fori(i,0,6){
            if(i <= 1){
                r = r*16 + (s[i]>='A' ? s[i] - 'A' + 10: s[i] - '0'); 
            }else if(i <= 3){
                g = g*16 + (s[i]>='A' ? s[i] - 'A' + 10: s[i] - '0'); 
            }else {
                b = b*16 + (s[i]>='A' ? s[i] - 'A' + 10: s[i] - '0'); 
            }
        }
    }
    void calc(int x){
        stack<char>stk;
        fori(i,0,2){
            int cur = x%16;
            x /= 16;
            if(cur <=9)stk.push(cur + '0');//printf("%d",cur);
            else stk.push((char)(cur - 10 + 'A'));
            //else printf("%c", (char)(cur - 10 + 'A'));
        }
        while(!stk.empty()){
            printf("%c", stk.top());
            stk.pop();
        }
    }
    void out(){
        calc(this->r);
        calc(this->g);
        calc(this->b);
    }
    color operator + (const color& x){
        color c = *this;
        c.r += x.r;
        c.g += x.g;
        c.b += x.b;
        return c;
    } 
    color operator = (const color& x){
        r = x.r;
        g = x.g;
        b = x.b;
        return *this;
    } 
    color operator += (const color&x){
        *this = *this + x;
        return *this;
    }
    color operator - (const color&x){
        color c = *this;
        c.r -= x.r;
        c.g -= x.g;
        c.b -= x.b;
        return c;
    }
};
const int N = 1e5+10;
int pre_mod[N];
int op[N];
color pre[N];
color a[N];
char s[10];
void sol(){
    int n, q;
    scanf("%d%d", &n, &q);
    pre[0].r = pre[0].g = pre[0].b = 0;
    For(i,1,n){
        scanf("%d%s", op+i, s);
        a[i].init(s);
       // cout<<a[i].r<<' '<<a[i].g<<' '<<a[i].b<<endl;
        if(op[i] == 1) {
            pre_mod[i] = i;
            pre[i] =  a[i];
        }else {
            pre_mod[i] = pre_mod[i-1];
            pre[i] = pre[i-1] + a[i];
            color aa = pre[i];
           // cout<<aa.r<<' '<<aa.g<<' '<<aa.b<<endl;
        }
    }
    while(q--){
        int l, r;
        scanf("%d%d", &l ,&r);
        int zui = pre_mod[r];
        color res;
        if(zui >= l) {
            res = pre[r];
            
        }else {
            res = pre[r] - pre[l-1];
        }
        res.r = min(res.r, 255);
        res.g = min(res.g, 255);
        res.b = min(res.b, 255);
        res.out();
        puts("");
    }
}
int main(){
    int tt;
    scanf("%d", &tt);
    while(tt--)sol();
    return 0;
}