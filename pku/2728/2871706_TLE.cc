#include <iostream>
#include <cmath>
using namespace std;
#define esp 1e-5

const int maxn=1025;

int n,m;
int root[maxn];

struct gao
{
    double x,y,z;
}a[maxn];

struct gao2
{
    double l,h;
}d[maxn][maxn];

struct gao3
{
    int v,u;
    double l;
}b[maxn*maxn];


bool com(gao3 a,gao3 b)
{return a.l<b.l;}
double ll(double x)
{return x*x;}
void dosth(gao2 &x,gao a,gao b)
{
    x.l=sqrt(ll(a.x-b.x)+ll(a.y-b.y));
    x.h=fabs(a.z-b.z);
}

int getroot(int x)
{
    if(x!=root[x])
        root[x]=getroot(root[x]);
    return root[x];
}


bool dosth(double xx)
{
    int i,j,nn,x,y;
    double t=0.0;
    m=nn=0;
    for(i=0;i<=n;i++)
        root[i]=i;
    for(i=0;i<n;i++)
        for(j=i+1;j<n;j++)
        {
            b[m].v=i+1;
            b[m].u=j+1;
            b[m].l=d[i][j].h-d[i][j].l*xx;
            m++;
        }
    sort(b,b+m,com);
    for(i=0;i<m;i++)
    {
        x=getroot(b[i].v);
        y=getroot(b[i].u);
        if(x==y)
            continue;
        else
        {
            root[x]=y;
            t+=b[i].l;
            nn++;
        }
        if(nn==n-1)
            break;
    }
    return t>-esp;
}


int main()
{
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
        bb=10000000.0;
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
