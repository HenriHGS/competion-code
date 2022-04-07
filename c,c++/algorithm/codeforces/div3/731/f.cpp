# include <bits/stdc++.h>
using namespace std;
const int N = 500010;
typedef long long LL;
int n, m;
LL w[N];
struct Node
{
    int l, r;
    LL sum, d;
}tr[N * 4];

LL gcd(LL a, LL b)
{
    return b ? gcd(b, a % b) : a;
}

void pushup(Node &u, Node &l, Node &r)
{
    u.sum = l.sum + r.sum;
    u.d = gcd(l.d, r.d);
}

void pushup(int u)
{
    pushup(tr[u], tr[u << 1], tr[u << 1 | 1]);
}

void build(int u, int l, int r)
{
    if (l == r)
    {
        LL b = w[r] - w[r - 1];
        tr[u] = {l, r, b, b};
    }
    else
    {
        tr[u].l = l, tr[u].r = r;
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}

void modify(int u, int x, LL v)
{
    if (tr[u].l == x && tr[u].r == x)
    {
        LL b = tr[u].sum + v;
        tr[u] = {x, x, b, b};
    }
    else
    {
        int mid = tr[u].l + tr[u].r >> 1;
        if (x <= mid) modify(u << 1, x, v);
        else modify(u << 1 | 1, x, v);
        pushup(u);
    }
}

Node quary(int u, int l, int r)
{
    if (tr[u].l >= l && tr[u].r <= r) return tr[u];
    else
    {
        int mid = tr[u].l + tr[u].r >> 1;
        if (r <= mid) return quary(u << 1, l, r);
        else if (l > mid) return quary(u << 1 | 1, l, r);
        else
        {
            auto left = quary(u << 1, l, r);
            auto right = quary(u << 1 | 1, l, r);
            Node res;
            pushup(res, left, right);
            return res;
        }
    }
}
bool check(int len){
    auto left = quary(1,1,1);
    Node right({0, 0, 0, 0});
    if (1 + 1 <= len) right = quary(1, 1 + 1, len);
    int x = abs(gcd(left.sum, right.d));
 //    if(len == 2) cout<<"x = "<<x<<endl;
    for(int i = 2; i <= n; i ++ ){
        if(i + len - 1 <= n){
            auto left = quary(1,1,i);
            Node right({0, 0, 0, 0});
            if (i + 1 <= i + len - 1) right = quary(1, i + 1, i + len -1);
            int tmp = abs(gcd(left.sum, right.d));
          //  if(len == 2) cout<<"tmp = "<<tmp<<endl;
            if(tmp != x)return false;
        }else {
            auto left1 = quary(1,1,i);
            Node right1({0, 0, 0, 0});
            if (i + 1 <= n) right1 = quary(1, i + 1, n);
            int tmp = abs(gcd(left1.sum, right1.d));
         //   if(len == 2) cout<<"tmp1 = "<<tmp<<endl;
            int R =  len - n + i - 1;
            auto left2 = quary(1,1,1);
            Node right2({0, 0, 0, 0});
            if (1 + 1 <= R) right2 = quary(1, 1 + 1, R);
            tmp = gcd(tmp, abs(gcd(left2.sum, right2.d)));
        //    if(len == 2) cout<<"tmp2 = "<<tmp<<endl;
            if(tmp != x)return false;
        }
    }
    return true;
}
void sol(){
    scanf("%d", &n);
    for(int i = 1;i <= n; i ++ )scanf("%lld", w+i);
    build(1,1,n);
    
    int L = 2, R = n, ans;
    while(L <= R){
        //cout<<L<<' '<<R<<endl;
        int mid = L + R >> 1;
        if(check(mid)) ans = mid, R = mid - 1;
        else L = mid + 1;
    }
   // cout<<"debug: ans:"<<ans<<endl;
    bool equal = true;
    for(int i = 1; i <= n; i ++ ) equal &= w[i] == w[1];
    ans--;
    if(equal)ans--; 
    ans = max(ans,0);
    cout<<ans<<endl;
}
int main(){
    int tt;
    scanf("%d", &tt);
    while(tt--)sol();
    return 0;
}
/*
5
4
16 24 10 5
4
42 42 42 42
3
4 6 4
5
1 2 3 4 5
6
9 9 27 9 9 63

*/