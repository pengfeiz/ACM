#include <iostream>
#include <math.h>
using namespace std;

#define eps 1e-8
#define maxn 105
#define pi 3.1415926535

double x[maxn],y[maxn];
double k,h;
int n;

double det(double x1,double y1,double x2,double y2)
{return x1*y2-y1*x2;}
double min(double a,double b)
{return a<b?a:b;}
double max(double a,double b)
{return a>b?a:b;}
bool between (double a,double x,double b)
{return (x>a-eps)&&(x<b+eps);}


double angle(double x,double y)
{
	double ang;
	if(fabs(x)<eps)
	{
		if(y>0)
			return pi/2;
		else
			return 3*pi/2;
	}
	ang=atan(y/x);
    if(x<-eps)
		ang=pi+ang;
    if(ang<-eps)
		ang+=2*pi;
    return ang;
}

void gett(double x1,double y1,double x2,double y2,double &a1,double &a2)
{
	if(det(x1,y1,x2,y2)<eps)
	{
		swap(x1,x2);
		swap(y1,y2);
	}
	a1=angle(x1,y1);
	a2=angle(x2,y2);
	if(a2<a1-eps)
		a2=a2+2*pi;
}

int main()
{
	int i,j;
	double a,b,aa,bb;
	scanf("%lf%lf%d",&k,&h,&n);
	memset(x,0,sizeof(x));
	memset(y,0,sizeof(y));
	a=9999999.0;
	b=-a;
	for(i=0;i<n;i++)
		scanf("%lf%lf",&x[i],&y[i]);
	x[n]=x[0];
	y[n]=y[0];
	gett(x[0],y[0],x[1],y[1],a,b);
	for(i=0;i<n;i++)
	{
		gett(x[i],y[i],x[i+1],y[i+1],aa,bb);
		for(j=-1;j<=1;j++)
		{
			if(between(a,aa+2*pi*j,b)||between(a,bb+2*pi*j,b))
			{
				a=min(a,aa+2*pi*j);
				b=max(b,bb+2*pi*j);
				break;
			}
		}
	}
	printf("%.2lf\n",((min(b-a,2*pi)*k*h)));
	return 0;
}
