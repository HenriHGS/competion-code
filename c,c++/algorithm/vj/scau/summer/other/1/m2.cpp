#include <iostream>
#include <vector>
#include <queue>
#define pb push_back
using namespace std;
const int maxn = 5e5+10;
int n, k, m;

int main()
{
    ios::sync_with_stdio(0);
    cin>>n>>k>>m;
    vector<int>w(n*k+1);
    vector<vector<int>> e(n+1);
    vector<vector<int>> du(k+1);//du[maxn]; du[i轮][du]
    vector<queue<int>> q(n+1);
    vector<int>cnt(k+1,n);
    for (int i = 0; i <= n; i ++ ) du[1].emplace_back(0);
    for(int i = 1; i <= m; i ++ ){
        int a, b;
        cin>>a>>b;
        swap(a, b);
        e[a].pb(b);
        du[1][b]++;
    }
    for (int i = 1; i <= n * k; i ++ ) cin >> w[i];
    for (int i = 2; i <= k; i ++ )
    {
        for (int j = 0; j < du[1].size(); j ++ ) du[i].emplace_back(du[1][j]);
    }
    for (int i = 1; i <= n; i ++ )
    {
        if (!du[1][i])
        {
            for (int j = 1; j <= k; j ++ ) q[i].push(j);
        }
    }
    for (int i = n * k; i >= 1; i -- )
    {
        int j = q[w[i]].front();
        q[w[i]].pop();
        for (auto v : e[w[i]])
        {
            du[j][v] --;
            if (!du[j][v]) {q[v].push(j);
                cnt[j]--;
                if(cnt[j]==0)du[j].clear();
            }
        }
        w[i] = j;
    }

    for (int i = 1; i <= k * n; i ++ )
        cout << w[i] << " ";
    cout << endl;

    return 0;
}
