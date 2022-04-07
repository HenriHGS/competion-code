#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#define debug(a) cout<<#a<<":"<<a<<endl;
using namespace std;
typedef unsigned long long ll;
const int N=1e5+10,M=1e6+10;
const int mod[2] = {(int)(1e9+7),(int)(1e9+9)};
ll P[2]={131,13331};
string s[N];
string ans;
ll h1[2][M],p[M],h2[2][M],q[M];
ll query1(int l,int r)
{
    return (h1[0][r] + mod[0]- h1[0][l-1]*p[r-l+1]%mod[0]) % mod[0];
}
ll query2(int l,int r)
{
    return (h2[0][r] +mod[0] -h2[0][l-1]*p[r-l+1]%mod[0]) % mod[0];
}
ll query3(int l,int r)
{
    return (h1[1][r] + mod[1] -h1[1][l-1]*q[r-l+1]%mod[1]) % mod[1];
}
ll query4(int l,int r)
{
    return (h2[1][r] + mod[1] -h2[1][l-1]*q[r-l+1]%mod[1])%mod[1];
}
void init()
{
    p[0]=1,q[0]=1;
    for(int i=1;i<M;i++)
    {
        p[i]=p[i-1]*P[0]%mod[0];
        q[i]=q[i-1]*P[1]%mod[1];
    }
}
int getnum(int ch)
{
    if(ch>='A'&&ch<='Z')ch=ch-'A'+1;
    else if(ch>='a'&&ch<='z')ch=26+ch-'a'+1;
    else
    {
        ch=53+ch-'0';
    }
    return ch;
}
void strhash(int x)
{
    int len=s[x].size();
    for(int i=0;i<len;i++)
    {
        h2[0][i+1]=h2[0][i]*P[0]%mod[0]+getnum(s[x][i]);
        h2[0][i+1] %= mod[0];
        h2[1][i+1]=h2[1][i]*P[1]%mod[1]+getnum(s[x][i]);
        h2[1][i+1] %= mod[1];
    }
}
int main()
{
    init();
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
    }
    int len=0,x=0;
    for(int i=1;i<=n;i++)
    {
        int fg=s[i].size();
        for(int j=x;j<fg;j++)
        {
            len++;
            h1[0][len]=h1[0][len-1]*P[0]%mod[0]+getnum(s[i][j]);
            h1[0][len] %= mod[0];
            h1[1][len]=h1[1][len-1]*P[1]%mod[1]+getnum(s[i][j]);
            h1[1][len] %= mod[1];
            ans+=s[i][j];
        }
        if(i==n)break;
        strhash(i+1);
        int len1=s[i+1].size();
        int d=min(len,len1);
        while(d)
        {
            /*
            if(i == 2){
                debug(d);
                cout<<"query1:  ";
                cout<<query1(len-d+1,len)<<' '<<query2(1,d)<<endl;
                cout<<"query2:  ";
                cout<<query3(len-d+1,len)<<' '<<query4(1,d)<<endl;
            }
            */
            if((query1(len-d+1,len)==query2(1,d))&&(query3(len-d+1,len)==query4(1,d)))
            {
                break;
            }
            d--;
        }
        x=d;
    }
    cout<<ans<<endl;
    return 0;
}
