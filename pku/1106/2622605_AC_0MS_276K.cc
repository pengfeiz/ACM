#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
#define pp 57.295780490442968321226628812406
#define esp 1e-7


double a[400];

int n,m;

bool com(double a,double b)
{return a<b;}
double ll(double x)
{return x*x;}
double compute(double x,double y,double xx1,double yy1,double xx2,double yy2)
{
	double l1,l2,l3,l;
	double x1,y1,x2,y2,x3,y3,s;
	x1=x-xx1;
	x2=xx2-xx1;
	y1=y-yy1;
	y2=yy2-yy1;
	x3=xx2-x;
	y3=yy2-y;
	l1=ll(x1)+ll(y1);
	l2=ll(x2)+ll(y2);
	l3=ll(x3)+ll(y3);
	l=sqrt(l1*l2);
	s=asin( (x1*y2-x2*y1)/l )*pp;
	if(l1+l2-l3>0)
		return s;
	if(s>0)
		return 180-s;
	return -180-s;
}


int main()
{
//	freopen("in.txt","r",stdin);
	double x,y,r,xx,yy;
	int i,maxx,j;
	while(scanf("%lf%lf%lf",&x,&y,&r),r>=0)
	{
		m=maxx=0;
		r*=r;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%lf%lf",&xx,&yy);
			if(ll(xx-x)+ll(yy-y)<r+esp)
			{
				a[m]=compute(xx,yy,x,y,x+1,y);
				m++;
			}
		}
		sort(a,a+m,com);
		for(i=0;i<m;i++)
			a[i+m]=a[i]+360;
		for(i=0;i<m;i++)
		{
			for(j=i+1;j<i+m;j++)
				if(a[j]-a[i]>180+esp)
					break;
			if(j-i>maxx)
				maxx=j-i;
		}
		printf("%d\n",maxx);
	}
	return 0;
}
