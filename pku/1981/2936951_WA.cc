#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
#define maxn 301
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
 //   freopen("in.txt","r",stdin);
    int i,j,k,t;
    double l,ll,x,y,r;
    while(scanf("%d",&n),n)
    {
        maxx=0;
        for(i=0;i<n;i++)
            scanf("%lf%lf",&a[i].x,&a[i].y);
        sort(a,a+n,com);
        for(i=0;i<n;i++)
            for(j=i+1;j<n;j++)
            {
                if(i==j)
                    continue;
                l=dis(a[i],a[j]);
                if(l<4+esp)
                {
                    		x=(a[i].x+a[j].x)/2,y=(a[i].y+a[j].y)/2;
				r=sqrt(dis(a[i],a[j]));
				l=sqrt(1-r*r/4);
				q.x=x-l*(a[j].y-a[i].y)/r,
				q.y=y+l*(a[j].x-a[i].x)/r;
                                t=0;
                 /*   l=sqrt(l);
                    ll=sqrt(1+esp-l/2);
                    xx=(a[j].x-a[i].x)/l;
                    yy=(a[j].y-a[i].y)/l;
                    q.x=(a[i].x+a[j].x)/2-yy*ll;
                    q.y=(a[i].y+a[j].y)/2+xx*ll;
                    t=0;*/
                    for(k=0;k<n;k++)
                        if(dis(q,a[k])<1+esp&&fabs(q.x-a[k].x)>esp&&fabs(q.y-a[k].y)>esp)
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
