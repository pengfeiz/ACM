#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
const double esp=1e-6;
#define pi 3.14159265358979323846264338327950288



struct poi
{
	double x,y;
}a[1000];
int n,d[1000],p;
bool u[1000];

double ll(double x)
{return x*x;}
double dis(poi a,poi b)
{
	double x1;
	double x2;
	x1=ll(a.x-b.x);
	x2=ll(a.y-b.y);
	return sqrt(x1+x2);
}


bool com(poi a,poi b)
{
	if(a.y!=b.y)
		return a.y<b.y;
	return a.x<b.x;
}
bool cha(double x1,double y1,double x2,double y2)
{
	double x;
	x=x1*y2-x2*y1;
	if(x>esp)
		return true;
	return false;
}
void tubao()
{
	int i;
	memset(u,0,sizeof(u));
	d[1]=1;
	d[2]=p=2;
	u[2]=true;
	for(i=3;i<=n;i++)
	{
		while( p>1 && cha( a[d[p]].x-a[d[p-1]].x , a[d[p]].y-a[d[p-1]].y , a[i].x-a[d[p]].x , a[i].y-a[d[p]].y))
			u[d[p--]]=false;
		d[++p]=i;
		u[i]=true;
	}
	for(i=n;i>0;i--)
	{
		if(!u[i])
		{
			while(cha( a[d[p]].x-a[d[p-1]].x , a[d[p]].y-a[d[p-1]].y , a[i].x-a[d[p]].x , a[i].y-a[d[p]].y))
				u[d[p--]]=false;
			d[++p]=i;
			u[i]=true;
		}
	}
	p--;
}


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
	q.x=(y13*(z2/d)-y12*(z3/d));
	q.y=(x12*(z3/d)-x13*(z2/d));
	r=dis(p1,q);
	return true;
}

int main()
{
//	freopen("in.txt","r",stdin);

	poi p1,p2,p3,q;
	int t,i,j,k;
	double r,maxx;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		maxx=0;
		for(i=1;i<=n;i++)
			scanf("%lf%lf",&a[i].x,&a[i].y);
		sort(a+1,a+1+n,com);
//		tubao();
		for(i=1;i<=n;i++)
		{
			p1.x=a[i].x;
			p1.y=a[i].y;
			for(j=i+1;j<=n;j++)
			{
				p2.x=a[j].x;
				p2.y=a[j].y;
				for(k=j+1;k<=n;k++)
				{
					p3.x=a[k].x;
					p3.y=a[k].y;
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