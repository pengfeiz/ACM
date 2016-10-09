#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

#define maxn 1010
#define esp 1e-8

int n,maxx;
struct gao
{
    double x,y;
    double angle;
}a[maxn];

int m;
double angle[1010];
bool com(gao a,gao b)
{
    if(a.x!=b.x)
        return a.x<b.x;
    return a.y<b.y;
}


double computee(gao a,gao b)
{
    if(fabs(a.x-b.x)<esp)
        return 99999999.0;
    return (a.y-b.y)/(a.x-b.x);
}


void dosth(int x)
{
    int i,t;
    m=0;
    for(i=x+1;i<n;i++)
        angle[m++]=computee(a[i],a[x]);
    sort(angle,angle+m);
    angle[m]=-99999999.0;
    t=2;
    for(i=0;i<m;i++)
    {
        if(fabs(angle[i]-angle[i+1])<esp)
        {
            t++;
            if(t>maxx)
                maxx=t;
        }
        else
            t=2;
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
    int i,j,cc=0;
    while(scanf("%d",&n),n)
    {
        maxx=0;
        for(i=0;i<n;i++)
            scanf("%lf%lf",&a[i].x,&a[i].y);
        sort(a,a+n,com);
        for(i=0;i<n;i++)
            dosth(i);
        if(maxx<4)
            maxx=0;
        printf("Photo %d: %d points eliminated\n",++cc,maxx);
    }
    return 0;
}

