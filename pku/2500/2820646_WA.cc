#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

const double pi=3.1415926535;
const double esp=1e-8;


long long a[1010];
long long d,n,c,g;
double maxx;


struct gao
{
    double x,y,angle;
}b[1010];

bool com(gao a,gao b)
{return a.angle<b.angle;}
double cha(double x1,double y1,double x2,double y2)
{return x1*y2-x2*y1;}
double compute(gao a,gao b,gao c)
{return fabs(cha(a.x-b.x,a.y-b.y,a.x-c.x,a.y-c.y))/2.0;}
double dos(int x,int y,int xx,int yy)
{
    int mid=(xx+yy)/2;
    double l1,l2,l3,maxx,ll;
    l1=compute(b[x],b[y],b[xx]);
    l2=compute(b[x],b[y],b[mid]);
    l3=compute(b[x],b[y],b[yy]);
    maxx=l1;
    if(l2>maxx)
        maxx=l2;
    if(l3>maxx)
        maxx=l3;
    if(xx>=yy-1)
        return maxx;
    if(l1-esp<l2&&l2-esp<l3)
    {
        ll=dos(x,y,mid,yy);
        if(ll>maxx)
            maxx=ll;
    }
    else if(l1>l2-esp&&l2>l3-esp)
    {
        ll=dos(x,y,xx,mid);
        if(ll>maxx)
            maxx=ll;
    }
    else
    {
        ll=dos(x,y,xx,mid);
        if(ll>maxx)
            maxx=ll;
        ll=dos(x,y,mid,yy);
        if(ll>maxx)
            maxx=ll;
    }
    return maxx;
}


void dosth()
{
    int i,j;
    double x;
    for(i=2;i<c-1;i++)
    {
        x=dos(0,i,1,i-1)+dos(i,c,i+1,c-1);
        if(maxx<x)
            maxx=x;
    }
}


int main()
{
    int tt,tim;
    double angle;
    long long i;
    scanf("%d",&tt);
    for(tim=1;tim<=tt;tim++)
    {
        maxx=0.0;
        printf("Scenario #%d:\n",tim);
        scanf("%lld%lld%lld%lld",&d,&n,&c,&g);
        d/=2.0;
        for(i=0;i<c;i++)
            a[i]=(i*g)%n;
        for(i=0;i<c;i++)
        {
            angle=(2.0*pi*a[i])/(n*1.0);
            b[i].angle=angle;
            b[i].x=double(d)*cos(angle);
            b[i].y=double(d)*sin(angle);
        }
        b[c].x=b[0].x;
        b[c].y=b[0].y;
        sort(b,b+c,com);
        dosth();
        printf("%.6lf\n\n",maxx);
    }
    return 0;
}
