#include <iostream>
#include <math.h>
using namespace std;

#define MAX 1002
#define esp 1e-5

struct poi
{
	double x,y;
}pa,pb,pc,pd,p,a[MAX],c[MAX],d[MAX];

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
double compute3(poi a,poi b,poi c)
{return (a.x*b.y+b.x*c.y+c.x*a.y)-(a.y*b.x+b.y*c.x+c.y*a.x);}


double v;
int n1,n2;


double compute2(poi d[],int m)
{
	int i;
	double s=0;
	for(i=1;i<m-1;i++)
		s+=compute3(d[0],d[i],d[i+1]);
	return fabs(s/2);
}

double compute(double mid,poi a[],int n)
{
	int i,j,k,m;
	poi he,ha;
	if(mid>a[n-1].y+esp||mid>a[0].y+esp)
		return 99999999;
	he.x=6;
	he.y=mid;
	ha.x=100;
	ha.y=mid;
	m=0;
	for(i=0;i<n;i++)
	{
		if(a[i].y<mid+esp)					
		{
			jiao(a[i-1],a[i],ha,he,d[0]);
			break;
		}
	}
	for(j=n-1;j>=0;j--)
	{
		if(a[j].y<mid+esp)	
		{
			m=j-i+3;
			jiao(a[j+1],a[j],ha,he,d[m-1]);
			break;
		}
	}
	for(k=1;k<m-1;k++)
	{
		d[k].x=a[k+i-1].x;
		d[k].y=a[k+i-1].y;
	}
	return compute2(d,m);
}

		
bool judge(double mid)
{
	double s;
	s=compute(mid,a,n1);
	s+=compute(mid,c,n2);
	return s<v+esp;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i,t;
	double fir,sec,mid;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lf",&v);
		scanf("%d",&n1);
		for(i=0;i<n1;i++)
			scanf("%lf%lf",&a[i].x,&a[i].y);
		scanf("%d",&n2);
		for(i=0;i<n2;i++)
			scanf("%lf%lf",&c[i].x,&c[i].y);
		fir=-9999999;
		sec=9999999;
		while(sec-fir>esp)
		{
			mid=(fir+sec)/2;
			if(judge(mid))
				fir=mid;
			else
				sec=mid;
		}
		if(fabs(fir)<esp)
			fir=esp;
		printf("%.3lf\n",fir);
	}
	return 0;
}
