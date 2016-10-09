#include <iostream>
#include <math.h>
using namespace std;
#define esp 1e-6
struct poi
{double x,y;
}a[1001],p,h;
int n;
double s;
double cha(double x1,double y1,double x2,double y2)
{return x1*y2-x2*y1;}
double dian(double x1,double y1,double x2,double y2)
{return x1*x2+y1*y2;}
void jiao(poi pa,poi pb,poi pc,poi pd)
{double s1,s2;
s1=cha(pa.x-pc.x,pa.y-pc.y,pd.x-pc.x,pd.y-pc.y);
s2=cha(pd.x-pc.x,pd.y-pc.y,pb.x-pc.x,pb.y-pc.y);
p.x=(s1*pb.x+s2*pa.x)/(s1+s2);
p.y=(s1*pb.y+s2*pa.y)/(s1+s2);}
double ll(double x)
{return x*x;}
void dosth()
{int i;
poi q;
q.x=a[0].x;
q.y=a[0].y;
s=0;
for(i=0;i<n-1;i++)
{if(cha(h.x-q.x,h.y-q.y,a[i].x-a[i+1].x,a[i].y-a[i+1].y)<esp)
continue;
jiao(h,q,a[i],a[i+1]);
if((p.x-a[i].x)*(p.x-a[i+1].x)<esp)
{q.x=a[i+1].x;
			q.y=a[i+1].y;
			s+=sqrt(ll(a[i+1].x-p.x)+ll(a[i+1].y-p.y));
		}
	}
	printf("%.2lf\n",s);
}
bool build(){
int i;
scanf("%d%lf",&n,&h.y);
h.x=0;
if(n==0&&fabs(h.y)<esp)
return false;
for(i=0;i<n;i++)
scanf("%lf%lf",&a[i].x,&a[i].y);
return true;}
int main()
{while(build())
dosth();
return 0;}