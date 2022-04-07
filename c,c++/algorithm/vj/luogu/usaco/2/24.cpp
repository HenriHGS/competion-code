#include <cstdio>
#include <vector>
using namespace std;
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++)
#define pb push_back
using vi = vector<int>;
int n, m;
struct Vim{
    vi type;
}need, have[20];

void sol(){
    scanf("%d", &n);
    For(i,1,n){
        int x;
        scanf("%d", &x);
        need.type.pb(x);
    }
    scanf("%d", &m);
    fori(i,0,m){
        For(j,1,n){
            int x;
            scanf("%d", &x);
            have[i].type.pb(x);
        }
    }
    /*
    printf("need: ");
    fori(j,0,n) printf("%d ", need.type[j]);
    puts("");
    */
   /*
    For(i,1,m){
        printf("have[%d]: ",i);
        fori(j,0,n) printf("%d ", have[i].type[j]);
        puts("");
    }
    */
    int mi = n+1;
    vector<int>ans;
   // printf("%d\n", (1<<m) -1);
    fori(bitmasks,0,1<<m){
        Vim temp;
        vi te_ans;
        int cnt = 0;
        temp.type.resize(n,0);
       // temp.type.
        fori(i,0,m){
            if((bitmasks>>i) & 1){
                te_ans.pb(i);
                cnt++;
                fori(j,0,n)temp.type[j] += have[i].type[j];
            }
        }
        //printf("bitmasks = %d, cnt = %d\n",bitmasks, cnt);
        
        bool ok = true;
        fori(j,0,n) ok &= temp.type[j] >= need.type[j];
        /*
        if(bitmasks == (1<<m) - 1){
            printf("type: ");
            fori(j,0,n) printf("%d ", temp.type[j]);
            puts("");
        }
        */
        if(ok){
            if(cnt < mi){
                mi = cnt;
                ans = te_ans;
            }
        }
        
    }
    printf("%d ", ans.size());
    for(auto x: ans)printf("%d ", x+1);
}

int main(){
    sol();
    return 0;
}