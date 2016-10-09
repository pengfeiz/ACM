#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
#define maxn 350
#define esp 1e-6
#define dis(a,b) (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)

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


int main()
{
   // freopen("in.txt","r",stdin);
    int i,j,k,t;
    double l,ll,x,y,r;
    while(scanf("%d",&n)!=EOF&&n)
    {
        maxx=1;
        for(i=0;i<n;i++)
            scanf("%lf%lf",&a[i].x,&a[i].y);
  //      sort(a,a+n,com);
        for(i=0;i<n;i++)
            for(j=i+1;j<n&&maxx<n;j++)
            {
                l=dis(a[i],a[j]);
                if(l<4+esp)
                {
                    l=sqrt(l);
                    ll=sqrt(1-l*l/4);
                    x=(a[j].x-a[i].x)/l;
                    y=(a[j].y-a[i].y)/l;
                    q.x=(a[i].x+a[j].x)/2-y*ll;
                    q.y=(a[i].y+a[j].y)/2+x*ll;
                    t=0;
                    for(k=0;k<n;k++)
                        if(dis(a[k],q)<esp)
                            t++;
                    if(t>maxx)
                        maxx=t;
                    if(maxx==n)
                        break;
                }
            }
        printf("%d\n",maxx);
    }
    return 0;
}

