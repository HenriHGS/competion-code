#include <cstring>
#include <cstdio>
#include <string>
#include <map>
#include <string>
#include <iostream>
#include <vector>
#define debug(a) cout<<#a<<":"<<a<<endl
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
typedef long long ll;
typedef pair<int,int>pa;
const int N = 4e5+10;
const int mod[] = {(int)(1e9+7), (int)(1e9+9)};
const int q[] = {131,13331};
int p[2][N];
void init(){
    p[0][0] = p[1][0] = 1;
    fori(k,0,2)fori(i,1,N) p[k][i] = ((ll)p[k][i-1]*q[k]) % mod[k];
}
map<pa,int>ma;
map<pa,int>used;
//char s[N];
int ha[2][N];
int tmp1[2], tmp2[2];
int get(int l, int r, int k){
    return ((ll)ha[k][r] - (ll)ha[k][l-1]*p[k][r - l + 1]%mod[k] + mod[k])% mod[k];
}
int main(){
    ios::sync_with_stdio(0);
    int n;
    cin>>n;//scanf("%d", &n);
    ll ans1 = 0, ans2 = 0;
    init();
    vector<string> v(n+1);
    vector<int>olen(n+1);
    For(i,1,n)cin>>v[i];
    For(i,1,n){
        auto& s = v[i];
        olen[i] = s.size();//strlen(s + 1);
        s = " " + s;
        int len = olen[i];
       // debug(s);
        For(j,1,len){
            fori(k,0,2){
                ha[k][j] = ((ll)ha[k][j-1]*q[k]%mod[k] + s[j])%mod[k];
            }    
        }
        /*
         fori(k,0,2)For(j,1,len){
            cout<<ha[k][j]<<' ';
            if(j == len) cout<<endl;
        }
        */
        fori(k,0,2)tmp1[k] = get(1,len,k);
      //  debug(tmp1[0]);
      //  debug(tmp1[1]);
        auto pp = make_pair(tmp1[0],tmp1[1]);
        ma[pp]++;
    }
    For(i,1,n){
//        scanf("%s", s + 1);
        auto& s = v[i];
       // debug(s);
        int len = olen[i];//strlen(s + 1);
        used.clear();
        // ha && pre
        //debug(len);
        For(j,1,len){
            fori(k,0,2){
                ha[k][j] = ((ll)ha[k][j-1]*q[k]%mod[k] + s[j])%mod[k];
            }    
        }
        /*
        fori(k,0,2)For(j,1,len){
            cout<<ha[k][j]<<' ';
            if(j == len) cout<<endl;
        }
        */
        //pre
        For(j,len/2,len){
            if(j < len && j*2 > len){
                //把后面多余的分给别人
                int dif = 2*j - len;
                fori(k,0,2)tmp1[k] = get(1,j,k);
                /*
                debug(get(1,1,0));
                debug(get(2,3,0));
                debug(get(3,3,0));
                debug(get(4,4,0));
                */
                bool equ = true;
                fori(k,0,2){
                    tmp2[k] = get(j+1,len,k);
                    equ &= tmp2[k] == get(1,len-j,k);
                }
                if(!equ) continue;
                fori(k,0,2)tmp2[k] = ((ll)tmp2[k]* p[k][dif]) % mod[k];
                int res[2]{};
                fori(k,0,2) res[k] = (tmp1[k] - tmp2[k] + mod[k]) % mod[k];
                auto pp = make_pair(res[0],res[1]);
                if(ma.count(pp)) {
                    used[pp] = 1;
                    ans2 += ma[pp];
                }
            }else if(j == len){
                fori(k,0,2)tmp1[k] = get(1,len,k);
                auto pp = make_pair(tmp1[0],tmp1[1]);
               // debug(tmp1[0]);
                //debug(tmp1[1]);
                if(ma.count(pp)) {
                    ans1 += (ma[pp] - 1);
                    // debug(ma[pp]);
                }
            }
        }
        //suf
        for(int j = len - 1; j >= 1; j -- ){
            int jj = j + 1;
            if(j*2 < len){
                //debug(j*2);
                //debug(len);
                //int dif = len - 2*j;
                fori(k,0,2)tmp1[k] = get(jj,len,k);
              //  auto pp = make_pair(tmp1[0],tmp1[1]);
               // if(used.count(pp))continue;
                /*
                cout<<jj<<' '<<len<<endl;
                debug(tmp1[0]);
                debug(tmp1[1]);
                */
                bool equ = true;
                fori(k,0,2){
                    tmp2[k] = get(1,j,k);
                    equ &= tmp2[k] == get(len - j + 1,len,k);
                    /*
                    debug(tmp2[k]);
                    debug(get(len - j + 1,len,k));
                    cout<<len-j+1<<' '<<len<<endl;
                    */
                }
                if(!equ) continue;
              //  debug(equ);
               // fori(k,0,2)tmp2[k] = ((ll)tmp2[k]* p[k][dif]) % mod[k];
                int res[2]{};
                fori(k,0,2) res[k] = get(j+1,len-j,k);
                auto pp = make_pair(res[0],res[1]);
                if(used.count(pp))continue;
                if(ma.count(pp)) ans2 += ma[pp];
            }
        }
    }
   // debug(ans1);
   // debug(ans2);
    printf("%lld\n", ans1/2 + ans2);
}
