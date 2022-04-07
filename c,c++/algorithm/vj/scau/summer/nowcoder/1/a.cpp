#include <bits/stdc++.h>;
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )

using namespace std;

const int N = 5010;
int f[N][N];
void table(){
    //cout<<a
    cout<<"b[ ] = {";
    int cnt = 0;
    For(i,1,N-1){
        For(j,i,N-1){
            if(!f[i][j]){
                cout<<j<<',';
                cnt++;
                if(cnt%10==0)cout<<endl<<"        ";
                               //"a[ ] = {"
            }
        }

    }
    cout<<cnt<<endl;
}
int main()
{
    f[0][0] = 0;
    for (int i = 0; i < N; i ++ )
    {
        for (int j = 0; j < N; j ++ )
        {
            if (f[i][j] == 0)
            {
                for (int k = 1; k + i < N; k ++ )
                {
                    for (int s = 0; s * k + j < N; s ++ )
                    {
                        f[i + k][j + s * k] = 1;
                    }
                }
                for (int k = 1; k + j < N; k ++ )
                {
                    for (int s = 0; s * k + i < N; s ++ )
                        f[i + s * k][k + j] = 1;
                }
            }
        }
    }
    table();
    //cout<<cnt<<endl;
    /*
    int T;
    cin >> T;
    while (T -- )
    {
        int n, m;
        scanf("%d%d", &n, &m);
        if (f[n][m] == 0) puts("Bob");
        else puts("Alice");
    }
    */
}
