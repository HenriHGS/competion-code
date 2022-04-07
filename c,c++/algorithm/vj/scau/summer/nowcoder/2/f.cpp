#include<bits/stdc++.h>
using namespace std;
#define db double
#define debug(a) cout<<#a<<":" << a<<endl
double a[3],b[3],c[3],d[3],k1,k2;
const db eps = 1e-4;
struct node
{
    double x,y,z,r;
}p1,p2;
const double PI = acos(-1.0);
void g(double A,double B,double C,double &x,double& c)
{
    B/=A,
    C/=A;
    x=-B/2;
    c=C-B*B/4;
    return;
}
double dis(struct node a,struct node  b)
{
        return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) + (a.z-b.z)*(a.z-b.z));
}
void f(double k,double* a,double*b,struct node & p)
{
    double A=(1-k*k);
    double C=0,x=0;
    g(A,2*b[0]*k*k-2*a[0],a[0]*a[0]-k*k*b[0]*b[0],p.x,x);
    C+=x;
    g(A,2*b[1]*k*k-2*a[1],a[1]*a[1]-k*k*b[1]*b[1],p.y,x);
    C+=x;
    g(A,2*b[2]*k*k-2*a[2],a[2]*a[2]-k*k*b[2]*b[2],p.z,x);
    C+=x;
    p.r=-C;
    p.r=sqrt(p.r);
    /*
    debug(p.x);
    debug(p.y);
    debug(p.z);
    debug(p.r);
    */
}
double sol(node p1, node p2){
    double x1 = p1.x,x2 = p2.x,y1 = p1.y,y2 = p2.y,z1 = p1.z,z2 = p1.z,r1 = p1.r,r2 = p1.r;
    double ans=0;
    double dis=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2)); //球心距离
   // debug(dis);
    if(dis>=r1+r2) //没有交到的地方
    {
        ans=0;
    }
    else if (dis+r1<=r2)//重合
    {
        ans=(4.00/3.00)*PI*r1*r1*r1;
    }
    else if(dis+r2<=r1)
    {
        ans=(4.00/3.00)*PI*r2*r2*r2;
    }
    else  //相交
    {
        double cal=(r1*r1+dis*dis-r2*r2)/(2.00*dis*r1);
        double h=r1*(1-cal);
        ans+=(1.00/3.00)*PI*(3.00*r1-h)*h*h;
        cal=(r2*r2+dis*dis-r1*r1)/(2.00*dis*r2);
        h=r2*(1.00-cal);
        ans+=(1.00/3.00)*PI*(3.00*r2-h)*h*h;
    }
    return ans;
}
void solve()
{
    for(int i=0;i<3;i++) scanf("%lf",&a[i]);
    for(int i=0;i<3;i++) scanf("%lf",&b[i]);
    for(int i=0;i<3;i++) scanf("%lf",&c[i]);
    for(int i=0;i<3;i++) scanf("%lf",&d[i]);
    scanf("%lf%lf",&k1,&k2);
    f(k1,a,b,p1);
    f(k2,c,d,p2);
    printf("%.3f\n", sol(p1,p2));
}
int main ()
{
    int t;
    cin>>t;
    while(t--)solve();
}