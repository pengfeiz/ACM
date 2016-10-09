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
double dist[maxn];
bool c[maxn];
int e[maxn];


double ll(double x)
{return x*x;}
void dosth1(gao2 &x,gao a,gao b)
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
    memset(dist,127,sizeof(dist));
    memset(c,0,sizeof(c));
    dist[0]=0;
    for(i=0;i<n;i++)
    {
        ll=999999999.0;
        for(j=0;j<n;j++)
        {
            if(!c[j]&&dist[j]<ll)
            {
                ll=dist[j];
                x=j;
            }
        }
        t+=ll;
        c[x]=true;
        for(j=0;j<n;j++)
        {
            if(!c[j]&&b[x][j]<dist[j])
                dist[j]=b[x][j];
        }
    }
    return t<esp;
}


int main()
{
    //freopen("in.txt","r",stdin);
    int i,j;
    double aa,bb,mid;
    while(scanf("%d",&n),n)
    {
        bb=0;
        for(i=0;i<n;i++)
        {
            scanf("%lf%lf%lf",&a[i].x,&a[i].y,&a[i].z);
            if(bb<a[i].z)
                bb=a[i].z;
        }
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                dosth1(d[i][j],a[i],a[j]);
        aa=0;
        bb=1000.00;
        while(aa<bb-esp)
        {
            mid=(aa+bb)/2;
            if(dosth(mid))
                bb=mid;
            else
                aa=mid;
        }
        printf("%.3lf\n",aa);
    }
    return 0;
}
