#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;
const int N=1e5+10;
int dp1[N],dp2[N],num[N],l[N];
void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>num[i];
    int pos=-1;
    for(int i=n;i>=1;i--)
    {
        if(i==n)
        {
            dp1[i]=1;
        }
        else
        {
            if(num[i]==-1)
            {
                dp1[i]=dp1[i+1]+1;
            }
            else if(pos==-1)
            {
                dp1[i]=n-i+1;
            }
            else if(num[i]<num[pos])
            {
                dp1[i]=dp1[pos]+pos-i;
            }
            else dp1[i]=pos-i;
        }
        if(num[i]!=-1)pos=i;
    }
    pos=-1;
    for(int i=1;i<=n;i++)
    {
        if(i==1)
        {
            dp2[i]=1;
        }
        else if(pos==-1)
        {
            dp2[i]=i;
        }
        else if(num[i]<num[pos])
        {
            dp2[i]=dp2[pos]+i-pos;
        }
        else dp2[i]=i-pos;
        if(num[i]!=-1)pos=i;
    }
    for(int len=3;len<=n;len++)
    {
        bool jge=true;
        for(int l=1;l<=n;l+=len)
        {
            int r=min(n,l+len-1);
            if(r-l<2)
            {
                jge=false;
                break;
            }
            if(dp1[l]+dp2[r]<r-l+1)
            {
                jge=false;
                 break;
            }
            else if(dp1[l]==r-l+1)
            {
                if(num[r]!=-1)
                {
                    jge=false;
                    break;
                }
            }
            else if(dp2[r]==r-l+1)
            {
                if(num[l]!=-1)
                {
                    jge=false;
                    break;
                }
            }
        }
        if(jge)
        {
            puts("Y");
            return;
        }
    }
    puts("N");
}
int main()
{
    solve();
    return 0;
}
