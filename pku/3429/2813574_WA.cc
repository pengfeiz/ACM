#include <iostream>
#include <cmath>
using namespace std;
#define maxn 2001
#define E 1e-12

struct poi
{
	double x,y;
}p,a[maxn];

int n;
double ans,pi;

double ll(double x)
{return x*x;}
double dis(double x1,double y1,double x2,double y2)
{return sqrt(ll(x1-x2)+ll(y1-y2));}
double cha(double x1,double y1,double x2,double y2)
{return x1*y2-x2*y1;}
double dian(double x1,double y1,double x2,double y2)
{return x1*x2+y1*y2;}
bool jiao(poi pa,poi pb,poi pc,poi pd,poi &p)
{
	double s1,s2;
	s1=cha(pa.x-pc.x,pa.y-pc.y,pd.x-pc.x,pd.y-pc.y);
	s2=cha(pd.x-pc.x,pd.y-pc.y,pb.x-pc.x,pb.y-pc.y);
	p.x=(s1*pb.x+s2*pa.x)/(s1+s2);
	p.y=(s1*pb.y+s2*pa.y)/(s1+s2);
        return true;
}


int main()
{
        int i,t,b1,b2,b3,b4,k,tim=0;
        bool f=false;
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            scanf("%lf%lf",&a[i].x,&a[i].y);
        scanf("%d",&t);
        for(k=1;k<=t;k++)
        {    
            scanf("%d%d%d%d",&b1,&b2,&b3,&b4);
            if(jiao(a[b1],a[b2],a[b3],a[b4],p))
            {
                if(fabs(p.x)<E&&fabs(p.y)<E&&!f)
                {
                    f=true;
                    tim=k;
                }
                a[++n].x=p.x;
                a[n].y=p.y;
            }            
        }
        printf("%d\n",tim);
	return 0;
}


