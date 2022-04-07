#include<bits/stdc++.h>
const int N=1e6+10;
using namespace std;
vector<int>g[55];
typedef long long ll;
ll MAX=9e18;
void init()
{
    for(int i=1;i<N;i++)
    {
        int cnt=0;
        int x=i;
        while(x)
        {
            cnt+=x%10;
            x/=10;
        }
        g[cnt].push_back(i);
    }
    return;
}
void solve()
{
    ll mmax=MAX;
    int a,b,c,d,n;
    scanf("%d%d%d%d%d",&a,&b,&c,&d,&n);
    for(int i=1;i<55;i++)
    {
        int l=0,r=upper_bound(g[i].begin(),g[i].end(),n) - g[i].begin() - 1;
        if(r==-1)continue;
        ll A=a*i+b,B=1LL*c*i*i+d*i;
        ll ans=A*g[i][r]*g[i][r]+B*g[i][r];
        ans=min(ans, A*g[i][0]*g[i][0]+B*g[i][0]);
        if(A==0)
        {
            if(B>0)
            {
                ans=g[i][0]*B;
            }
            else ans=g[i][r]*B;
        }
        else if(A>0)
        {
            ll p=-1*(B/(2*A));
            int x = upper_bound(g[i].begin(),g[i].end(),p) - g[i].begin();
            if (x > r) ans=A*g[i][r]*g[i][r]+B*g[i][r];
            else 
            {
                  int lx=max(0,x-3);
                  for(int j=lx;j<=x;j++)
                  {
                      ans=min(ans,A*g[i][j]*g[i][j]+B*g[i][j]);
                  }
            }
        }
        else
        {
            ans=A*g[i][r]*g[i][r]+B*g[i][r];
            ans=min(ans, A*g[i][0]*g[i][0]+B*g[i][0]);
        }
        mmax=min(mmax,ans);
    }
    printf("%lld\n",mmax);
}
int main() {
    //ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin>>T;
    init();
    while(T--)solve();
    return 0;
}