#include <cstdio>
#include <cstring>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
const int N = 1e6+10;
const int mod[2] = {(int)(1e9+7),(int)(1e9+9)};
const int q[2] = {13331,131};
typedef long long ll;
int ha[N][2], p[N][2];
void init(){
    p[0][1] = p[0][0] = 1;
    fori(i,1,N){
        fori(j,0,2) p[i][j] = 1LL*p[i-1][j]*q[j]%mod[j];
    }
}
char t[N], s[N];

inline int get(int l, int r, int j){
    return (1LL*ha[r][j] - 1LL*ha[l-1][j]*p[r-l+1][j]%mod[j] + mod[j])%mod[j];
}

int main(){
    init();
    scanf("%s", t+1);
    scanf("%s", s+1);
    int lent = strlen(t+1), lens = strlen(s+1);
    int cnt0 = 0, cnt1 = 0;
    if(s[1] == '1') For(i,1,lent) t[i] = t[i]=='1'?'0':'1';
    For(i,1,lent){
        if(t[i] == '1') cnt1++;
        else cnt0++;
    }
    For(i,1,lens){
        fori(j,0,2){
            ha[i][j] = (1LL*ha[i-1][j]*q[j]%mod[j] + s[i]) % mod[j];
        }
    }
    int ans = 0;
    For(len0,1,lens/cnt0){
        int len1 = (lens - len0*cnt0)/cnt1;
        if(len0*cnt0 + len1*cnt1 !=  lens || !len1) continue;
        int v1[2] = {-1,-1};
        int v2[2] = {-1,-1};
        bool ok = true;
        int l = 1,r;
        for(int i = 1; i <= lent; i ++ ){
            if(t[i] == '0'){
                r = l + len0 - 1;
                int v11[2]{};
                fori(j,0,2) v11[j] = get(l,r,j);
                fori(j,0,2){
                    if(v1[j] == -1) v1[j] = v11[j];
                    else if(v1[j] != v11[j]){
                        ok = false;
                        break;
                    }
                }
            }else {
                r = l + len1 - 1;
                int v22[2]{};
                fori(j,0,2) v22[j] = get(l,r,j);
                fori(j,0,2){
                    if(v2[j] == -1) v2[j] = v22[j];
                    else if(v2[j] != v22[j]){
                        ok = false;
                        break;
                    }
                }
            }
            if(!ok)break;
            l = r+1;
        }
        if(ok){
            bool equ = false;
            fori(j,0,2) equ |= v1[j] == v2[j];
            /* if(len0==3){
                printf("%d %d %d %d\n",v1[0], v1[1], v2[0], v2[1]);
                printf("len1 = %d\n",len1);
                printf("equ = %d\n", (int)equ);
            } */
            ans += !equ;
        }
    }
    printf("%d\n", ans);
    return 0;
}
/*
01
aaaaaa
*/
/*
001
kokokokotlin
*/