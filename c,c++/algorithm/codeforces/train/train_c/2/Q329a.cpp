#include <iostream>
#include <vector>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define sz(a) (int)a.size()
using namespace std;
const int N = 110;
char s[N][N];
typedef pair<int,int>pa;
vector<pa>col[N], row[N];
int main(){
    ios::sync_with_stdio();
    int n;
    cin>>n;
    int cnt_col, cnt_row;
    cnt_col = cnt_row = 0;
    for(int i = 1; i <= n; i ++ )cin>>(s[i]+1);
    for(int i = 1; i <= n; i ++ )for(int j = 1; j <= n; j ++ ){
        if(s[i][j] =='.'){
            if(row[i].empty())cnt_row++;
            if(col[j].empty())cnt_col++;
            row[i].pb({i,j});
            col[j].pb({i,j});
        }
    }
    vector<pa>ans[N];
    if(cnt_row == n){
        for(int i = 1; i <= n; i ++ )ans[i] = row[i];
    }else if(cnt_col == n){
        for(int i = 1; i <= n; i ++ )ans[i] = col[i];
    }
    if(cnt_row == n || cnt_col == n){
        for(int i = 1; i <= n; i ++ )cout<<ans[i][0].fi<<' '<<ans[i][0].se<<endl;
    }else cout<<-1<<endl;
    return 0;
}