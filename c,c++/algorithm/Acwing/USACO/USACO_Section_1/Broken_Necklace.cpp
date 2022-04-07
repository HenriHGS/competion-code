/*
本题需要注意的地方：
1. 直接暴力，O(n)，有点困难
2. 对于从左到右的贪心，要保证两次相加，不会超过ans
*/
# include <iostream>
# include <cstdio>
# include <cstring>
# define For(i,x,y) for(int i = (x); i <= (y); i ++ )
# define fori(i,x,y) for(int i = (x) ; i< (y) ; i ++ )
using namespace std;
char str[500];
int n;
void rig(int& cnt, int & p, int other){
    int op = 0;
    while(cnt<n&& cnt + other < n){
        if(p>n) p = 1;
        if(op == 0 || str[p] == 'w' || op&&str[p]==op){
            cnt++;
            if(str[p]!='w'){
                op = str[p];
            }
            p++;
        }else break;
    }
}
void lef(int & cnt, int q, int other){
    int op = 0;
    while(cnt < n && cnt+other<n){
        if(q<=0)q = n;
        if(op == 0|| str[q] == 'w' || op&&str[q]==op){
            cnt++;
            if(str[q]!='w'){
                op = str[q];
            }
            q--;
        }else break;
    }
}
int main(){
    cin>>n;
    cin>>(str+1);
    int ans = 0;
    For(i,0,n){
        int q = i, p = i+1;
        int cnt[2]{};
        int op = 0, pre = 0;
        rig(cnt[0],p,cnt[1]);
        if(cnt[0] == n){
            cout<<n<<endl;
            return 0;
        }
        lef(cnt[1],q,cnt[0]);
        ans = max(ans,cnt[0]+cnt[1]);
        /*
        cnt[0] = cnt[1] = 0;
        p = i+1, q = i;
        lef(cnt[1],q,cnt[0]);
        rig(cnt[0],p,cnt[1]);
        ans = max(ans,cnt[0]+cnt[1]);
       // if(ans == 12)cout<<i<<' '<<(char)op<<' '<<cnt[0]<<' '<<cnt[1]<<endl;
        */
    }
    cout<<ans<<endl;
    return 0;
}