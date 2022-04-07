#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#define fori(i,x,y) for(int i = (x); i <(y); i ++ )
#define For(i,x,y) for(int i = (x); i <=(y); i ++ )
#define sz(a) (int)a.size()
using namespace std;

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


int mod[2] = {(int)(1e9+7),(int)(1e9+3)};
typedef unsigned long long ULL;
const int N  = 1e6+10;
ULL ha[2][N], pw[2][N];
int q[2] = {131,13331};
ULL get(int l, int r, int s){
    return (ha[s][r]- ha[s][l-1]*pw[s][r-l+1]%mod[s]+mod[s])%mod[s];
}
char s[N];
void init(int n){
    pw[0][0] = pw[1][0] = 1;
    For(i,1,n){
        fori(j,0,2){
            pw[j][i] = pw[j][i-1]*q[j]%mod[j];
            ha[j][i] = (ha[j][i-1]*q[j]%mod[j] + s[i])%mod[j];
        }
    }
}
int cas = 0;
void sol(){
    scanf("%s", s+1);
    int n = strlen(s+1);
    init(n);
    int first = s[1];
    int mx = 0;
    for(int i = 2; i <= n; i ++ ){
        if(first == s[i]){
            bool ok = true;
            int j = i;
            while(j <= n ){
                if(j + i - 1 - 1 > n){
                    int len = n - j+1;
                    bool ok1 = true;
                    ULL a[2], b[2];
                    fori(k,0,2){
                        a[k] = get(1,len,k);
                        b[k] = get(j,j + len - 1,k);
                        ok1 &= a[k] == b[k];
                    }
                    if(!ok1) ok = false;
                    break;
                }
                bool ok1 = true;
                ULL a[2], b[2];
                fori(k,0,2){
                    a[k] = get(1,i-1,k);
                    b[k] = get(j,j + i - 1 - 1,k);
                    ok1 &= a[k] == b[k];
                }
                if(!ok1){
                    ok = false;
                    break;
                }
                j = j + i - 1;
            }
            if(ok) {
                mx = i-1;
                break;
            }
            if(s[j] == first) i = j;
            else i = j - 1;
        }
    }
    vector<int>ans;
    For(i,1,n){
        if(i*mx>n)break;
        ans.push_back(i*mx);
    }
    if(mx != 1)ans.push_back(n);
    printf("Case #%d: %d\n", ++cas, sz(ans));
    for(int i = 0; i < sz(ans); i ++ )print(ans[i], i == sz(ans)- 1? '\n': ' ');
}

int main()
{
    int tt;
    scanf("%d", &tt);
    while(tt--)sol();
    return 0;
}
