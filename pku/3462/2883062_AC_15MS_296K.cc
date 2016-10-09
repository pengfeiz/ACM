#include <iostream>
#include <cmath>
using namespace std;
#define esp 1e-10
#define maxn 101

struct poi
{
	double x,y;
}a[maxn],p,c[maxn],xx1,xx2,q;

struct gao
{
    poi a,b;
}b[maxn];
int n;

double ans,pi;


double cha(double x1,double y1,double x2,double y2)
{return x1*y2-x2*y1;}
double dian(double x1,double y1,double x2,double y2)
{return x1*x2+y1*y2;}


void jiao(poi pa,poi pb,poi pc,poi pd,poi &p)
{
	double s1,s2;
	s1=cha(pa.x-pc.x,pa.y-pc.y,pd.x-pc.x,pd.y-pc.y);
	s2=cha(pd.x-pc.x,pd.y-pc.y,pb.x-pc.x,pb.y-pc.y);
	p.x=(s1*pb.x+s2*pa.x)/(s1+s2);
	p.y=(s1*pb.y+s2*pa.y)/(s1+s2);
}

bool com(poi a,poi b)
{
    if(fabs(a.x-b.x)>esp)
        return a.x<b.x;
    return a.y>b.y;
}

int main()
{
    int tt,t,i;
    double minn;
    scanf("%d",&tt);
    while(tt--)
    {
        t=1;
        scanf("%d",&n);
        xx1.x=1000;
        xx2.x=-1000;
        xx1.y=xx2.y=0;
        scanf("%lf%lf",&q.x,&q.y);
        for(i=0;i<n;i++)
            scanf("%lf%lf%lf%lf",&b[i].a.x,&b[i].a.y,&b[i].b.x,&b[i].b.y);
        for(i=0;i<n;i++)
        {
            jiao(q,b[i].a,xx1,xx2,p);
            c[i].x=p.x;
            jiao(q,b[i].b,xx1,xx2,p);
            c[i].y=p.x;
            if(c[i].y<c[i].x)
                swap(c[i].x,c[i].y);
        }
        sort(c,c+n,com);
        minn=-9999999;
        for(i=0;i<n;i++)
        {
            if(c[i].y<minn)
                continue;
            if(c[i].x<minn+esp&&c[i].y>minn)
                minn=c[i].y;
            else if(c[i].x>minn+esp)
            {    
                t++;
                minn=c[i].y;
            }
        }
        printf("%d\n",t);
    }
    return 0;
}
