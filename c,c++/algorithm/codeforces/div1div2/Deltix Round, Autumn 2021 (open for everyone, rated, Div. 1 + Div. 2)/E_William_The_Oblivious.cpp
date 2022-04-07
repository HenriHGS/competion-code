#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cctype>
using namespace std;
int read(){
    char ch = getchar(); int f = 0, x = 0;
    while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
    while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    return f ? -x : x;
}
template<typename T > void print(T x){
    if(x < 0) x = -x, putchar('-');
    if(x >= 10) print(x/10);
    putchar(x % 10 + '0');
}
template<typename T> void print(T x, char let){
    print(x), putchar(let);
}
const int N = 1e5+10;
struct Node{
    int l, r;
    int a, b, c, bc, ab, abc;
    Node(){}
    Node(int l, int r){
        this->l = l, this->r = r;
        a = b = c = bc = ab = abc = 0;
    }
    Node(char ch, int l, int r){
        this->l = l, this->r = r;
        a = b = c = bc = ab = abc = 0;
        if(ch == 'a') a = 1;
        else if(ch == 'b') b = 1;
        else c = 1;
    }
    Node operator + (const Node & x){
        Node res;
        res.l = l, res.r = x.r;
        res.a = a + x.a;
        res.b = b + x.b;
        res.c = c + x.c;
        res.ab = min(ab + x.b, a + x.ab);
        res.bc = min(bc + x.c, b + x.bc);
        res.abc = min({a + x.abc, ab + x.bc, abc + x.c}); 
        return res;
    }
} tr[N<<2];
char s[N];
#define ls u << 1
#define rs u << 1 | 1
void build(int u, int l, int r){
    if(l == r){
        tr[u] = Node(s[l],l,r);
        return ;
    }else {
        int mid = l + r >> 1;
        build(ls,l,mid); build(rs,mid+1,r);
        tr[u] = tr[ls] + tr[rs];
    }
}
void mody(int u, int x, char ch){
    if(tr[u].l == tr[u].r && tr[u].l == x){
        tr[u] = Node(ch,x,x);
    }else {
        int mid = tr[u].l + tr[u].r >> 1;
        if(x <= mid) mody(ls,x,ch);
        else mody(rs,x,ch);
        tr[u] = tr[ls] + tr[rs];
    }
}
int main(){
    int n = read(), m = read();
    scanf("%s", s + 1);
    build(1,1,n);
    while(m--){
        int x = read(); char ch;
        scanf("%c", &ch);
        mody(1,x,ch);
        print(tr[1].abc, '\n');
    }
    return 0;
}