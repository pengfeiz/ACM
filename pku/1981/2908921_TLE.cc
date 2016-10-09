#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
#define maxn 301
#define esp 1e-5

struct gao
{
    double x,y;
}a[maxn],q;

int n,maxx;

bool com(gao a,gao b)
{
    if(a.x!=b.x)
        return a.x<b.x;
    return a.y<b.y;
}

double ll(double x)
{return x*x;}
double dis(gao a,gao b)
{return ll(a.x-b.x)+ll(a.y-b.y);}

int main()
{
   // freopen("in.txt","r",stdin);
    int i,j,k,t;
    double l,ll,xx,yy,x,y;
    while(scanf("%d",&n),n)
    {
        maxx=0;
        x=y=-98765432;
        for(i=0;i<n;i++)
            scanf("%lf%lf",&a[i].x,&a[i].y);
        sort(a,a+n,com);
        for(i=0;i<n;i++)
            for(j=i+1;j<n;j++)
            {
                l=dis(a[i],a[j]);
                if(l<4+esp)
                {
                    l=sqrt(l);
                    ll=sqrt(1+esp-l/2);
                    xx=(a[j].x-a[i].x)/l;
                    yy=(a[j].y-a[i].y)/l;
                    q.x=(a[i].x+a[j].x)/2-yy*ll;
                    q.y=(a[i].y+a[j].y)/2+xx*ll;
                    if(fabs(q.x-x)<0.01&&fabs(q.y-y)<0.01)
                        continue;
                    t=0;
                    for(k=0;k<n;k++)
                        if(dis(q,a[k])<1+esp)
                            t++;
                    if(t>maxx)
                    {
                        x=q.x;
                        y=q.y;
                        maxx=t;
                    }
                }
            }
        printf("%d\n",maxx);
    }
    return 0;
}
