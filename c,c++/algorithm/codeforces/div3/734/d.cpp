#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <cmath>
#include <cstring>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
#define sz(a) (int)a.size()
#define ALL(a) a.begin(), a.end()
#define mst(x,a) memset(x,a,sizeof(x))
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define db double
#define endl '\n' 
#define debug(a) cout << #a << ": " << a << endl
using namespace std;
typedef long long LL;
typedef long long ll;
typedef unsigned long long ULL;
const LL INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int mod = 1e9+7;
typedef pair<int,int>pa;
typedef pair<ll,ll>pai;
typedef pair<db,db> pdd;
const db eps = 1e-6;
const db pi = acos(-1.0);

template<typename T1, typename T2> void ckmin(T1 &a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> void ckmax(T1 &a, T2 b) { if (a < b) a = b; }
int read() {
    int x = 0, f = 0; char ch = getchar();
    while (!isdigit(ch)) f |= ch == '-', ch = getchar();
    while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
    return f ? -x : x;
}
template<typename T> void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x >= 10) print(x / 10);
    putchar(x % 10 + '0');
}
template<typename T> void print(T x, char let) {
    print(x), putchar(let);
}
template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

const int maxn = 100000 + 5;
char ans[110][110];
void sol(){
    int dom[2];
    int n, m, k;
    cin>>n>>m>>k;
    For(i,0,n+3)For(j,0,m+3)ans[i][j] = ' ';

    dom[0] = k, dom[1] = n*m/2 - k;
    bool ok = true;
    int op = -1;
    if(n&1) op = 0;
    if(m&1) op = 1;
    int nn = n, mm = m;
    if(op != -1){
        int len = m;
        if(op) len = n;
        int need = len/2;
        if(need > dom[op]){
            cout<<"NO"<<endl;
            return;
        }
        dom[op] -= need;
        /*
        if(op) {
            int ch = 0;
            For(i,1,n) {
                ans[i][m] = 'a' + ch;
                if(i%2 == 0) ch = (ch+1)%2;
            }
            mm--;
        }
        else {
            nn--;
            int ch = 0;
            For(j,1,m) {
                ans[n][j] = 'a' + ch;
                if(j%2 == 0) ch = (ch+1)%2;
            }
        }
        */
        if(mm == 0 || nn == 0){
            cout<<"YES"<<endl;
            /*
            For(i,1,n)For(j,1,m){
                cout<<ans[i][j];
                if(j==m)cout<<endl;
            }
            */
            return;
        }
    }
    if(dom[0]%2 != 0 || dom[1]%2!=0){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    /*
    for(int i = 1; i <= nn; i += 2)for(int j = 1; j <= mm; j += 2){
        vector<pa>p(4+8);
        p[0] = mp(i,j);
        p[1] = mp(i,j+1);
        p[2] = mp(i+1,j);
        p[3] = mp(i+1,j+1);

        p[4] = mp(i-1,j);
        p[5] = mp(i-1,j+1);
        p[6] = mp(i,j+2);
        p[7] = mp(i+1,j+2);
        p[8] = mp(i+2,j+1);
        p[9] = mp(i+2,j);
        p[10] = mp(i+1,j-1);
        p[11] = mp(i,j-1);
        int vis[26]{};
        fori(k,4,12){
            auto x = p[k];
            if(ans[x.fi][x.se] == ' ')continue;
            int ch = ans[x.fi][x.se] - 'a';
            vis[ch]++;
        }
        int col[2] = {-1, -1};
        fori(k,0,26){
            if(!vis[k] && col[0]== -1) col[0]= k;
            else if(!vis[k]&&col[1]==-1){
                col[1] = k;
                break;
            }
        }
        int op = 0;
        if(dom[0]){
            dom[0] -= 2;
        }else dom[1] -= 2, op = 1;
        fori(k,0,4){
            auto x = p[k];
            int pos = k / 2;
            if(op == 1){
                pos = (2-k+2)%2;
            }
            //if(ans[x.fi][x.se] == ' ')continue;
            ans[x.fi][x.se] = col[pos] + 'a';
        }
    }
    For(i,1,n)For(j,1,m){
        cout<<ans[i][j];
        if(j==m)cout<<endl;
    }
    */
}



int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tt; cin>>tt;
    while(tt--)
        sol();
    return 0;
}