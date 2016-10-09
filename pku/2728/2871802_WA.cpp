#include <iostream>
#include <cmath>
using namespace std;
#define esp 1e-5

const int maxn=1025;

int n,m;

struct gao
{
    double x,y,z;
}a[maxn];

struct gao2
{
    double l,h;
}d[maxn][maxn];

double b[maxn][maxn];
bool c[maxn];
int e[maxn];
int f[maxn];


double ll(double x)
{return x*x;}
void dosth(gao2 &x,gao a,gao b)
{
    x.l=sqrt(ll(a.x-b.x)+ll(a.y-b.y));
    x.h=fabs(a.z-b.z);
}


bool dosth(double xx)
{
    int i,j,x;
    double t=0.0;
    double ll;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            b[i][j]=d[i][j].h-d[i][j].l*xx;
    m=1;
    e[0]=0;
    memset(c,0,sizeof(c));
    memset(f,127,sizeof(f));
    while(m<n-1)
    {
        ll=9999999.0;
        c[m-1]=true;
        for(i=0;i<n;i++)
        {
            if(ll>b[e[m-1]][i]&&!c[i])
            {
                ll=b[e[m-1]][i];
                f[m-1]=i;
            }
        }
        ll=9999999.0;
        for(i=0;i<m;i++)
            if(ll>b[e[i]][f[i]])
            {
                ll=b[e[i]][f[i]];
                x=f[i];
            }
        t+=ll;
        e[m++]=x;    
    }
    return t>-esp;
}


int main()
{
 //   freopen("in.txt","r",stdin);
    int i,j;
    double aa,bb,mid;
    while(scanf("%d",&n),n)
    {
        for(i=0;i<n;i++)
            scanf("%lf%lf%lf",&a[i].x,&a[i].y,&a[i].z);
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                dosth(d[i][j],a[i],a[j]);
        aa=0;
        bb=1000.0;
        while(aa<bb-esp)
        {
            mid=(aa+bb)/2;
            if(dosth(mid))
                aa=mid;
            else
                bb=mid;
        }
        printf("%.3lf\n",aa);
    }
    return 0;
}
