#include <iostream>
#include <math.h>
using namespace std;
#define esp 1e-9
#define pi 3.14159265358979323846264338327950288


struct poi
{
	double x,y;
}aa[1000];
double ll(double x)
{return x*x;}
double dis(poi a,poi b)
{return sqrt(ll(a.x-b.x)+ll(a.y-b.y));}


bool cocircle(poi p1,poi p2,poi p3,poi &q,double &r)
{
	double x12=p2.x-p1.x;
	double y12=p2.y-p1.y;
	double x13=p3.x-p1.x;
	double y13=p3.y-p1.y;
	double z2=x12*(p1.x+p2.x)+y12*(p1.y+p2.y);
	double z3=x13*(p1.x+p3.x)+y13*(p1.y+p3.y);
	double d=2.0*(x12*(p3.y-p2.y)-y12*(p3.x-p2.x));
	if(fabs(d)<esp)
		return false;
	q.x=(y13*z2-y12*z3)/d;
	q.y=(x12*z3-x13*z2)/d;
	r=dis(p1,q);
	return true;
}

int main()
{
	poi p1,p2,p3,q;
	int t,n,i,j,k;
	double r,maxx;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		maxx=0;
		for(i=0;i<n;i++)
			scanf("%lf%lf",&aa[i].x,&aa[i].y);
		for(i=0;i<n;i++)
		{
			p1.x=aa[i].x;
			p1.y=aa[i].y;
			for(j=i+1;j<n;j++)
			{
				p2.x=aa[j].x;
				p2.y=aa[j].y;
				for(k=j+1;k<n;k++)
				{
					p3.x=aa[k].x;
					p3.y=aa[k].y;
					if(cocircle(p1,p2,p3,q,r))
						if(r>maxx)
							maxx=r;
				}
			}
		}
		printf("%.3lf\n",maxx);
	}
	return 0;
}