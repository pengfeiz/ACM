#include <iostream>
#include <math.h>
using namespace std;
#define MAX 31
#define pi 3.14159265358979323846264338327950288
#define esp 1e-8

struct gao
{
	double x,y;
}a[MAX],p,q;
int n;


double maxx(double a,double b)
{return a>b?a:b;}
double ll(double x)
{return x*x;}
double cha(double x1,double y1,double x2,double y2)
{return x1*y2-x2*y1;}
double judge(gao a,gao b,gao c)
{
	double s;
	s=cha(a.x-b.x,a.y-b.y,c.x-b.x,c.y-b.y);
	return s/sqrt(ll(c.x-b.x)+ll(c.y-b.y));
}

int main()
{
	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int i,t,k;
	double j,x1,y1,x2,y2,minn,s,ho,hoho,hohoho;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%lf%lf",&a[i].x,&a[i].y);
		minn=999999999;
		i=0;
		for(j=0;j<90;j++)
		{
			x1=x2=y1=y2=0;
			p.x=a[i].x+10*cos(j/180*pi);
			p.y=a[i].y+10*sin(j/180*pi);
			q.x=a[i].x+10*cos((j+90)/180*pi);
			q.y=a[i].y+10*sin((j+90)/180*pi);
			for(k=0;k<n;k++)
			{
				s=judge(a[k],a[i],p);
				if(s<x1)
					x1=s;
				if(s>x2)
					x2=s;
				s=judge(a[k],a[i],q);
				if(s<y1)
					y1=s;
				if(s>y2)
					y2=s;
			}
			s=ll(maxx((x2-x1),(y2-y1)));
			if(s-minn<esp)
			{
				minn=s;
				ho=j;
			}
		}
		for(j=ho-1;j<ho+1;j+=0.01)
		{
			x1=x2=y1=y2=0;
			p.x=a[i].x+10*cos(j/180*pi);
			p.y=a[i].y+10*sin(j/180*pi);
			q.x=a[i].x+10*cos((j+90)/180*pi);
			q.y=a[i].y+10*sin((j+90)/180*pi);
			for(k=0;k<n;k++)
			{
				s=judge(a[k],a[i],p);
				if(s<x1)
					x1=s;
				if(s>x2)
					x2=s;
				s=judge(a[k],a[i],q);
				if(s<y1)
					y1=s;
				if(s>y2)
					y2=s;
			}
			s=ll(maxx((x2-x1),(y2-y1)));
			if(s-minn<esp)
			{
				minn=s;
				hoho=j;
			}
		}
		for(j=hoho-0.01;j<hoho+0.01;j+=0.0001)
		{
			x1=x2=y1=y2=0;
			p.x=a[i].x+10*cos(j/180*pi);
			p.y=a[i].y+10*sin(j/180*pi);
			q.x=a[i].x+10*cos((j+90)/180*pi);
			q.y=a[i].y+10*sin((j+90)/180*pi);
			for(k=0;k<n;k++)
			{
				s=judge(a[k],a[i],p);
				if(s<x1)
					x1=s;
				if(s>x2)
					x2=s;
				s=judge(a[k],a[i],q);
				if(s<y1)
					y1=s;
				if(s>y2)
					y2=s;
			}
			s=ll(maxx((x2-x1),(y2-y1)));
			if(s-minn<esp)
			{
				minn=s;
				hohoho=j;
			}
		}
		for(j=hohoho-0.0001;j<hohoho+0.0001;j+=0.000001)
		{
			x1=x2=y1=y2=0;
			p.x=a[i].x+10*cos(j/180*pi);
			p.y=a[i].y+10*sin(j/180*pi);
			q.x=a[i].x+10*cos((j+90)/180*pi);
			q.y=a[i].y+10*sin((j+90)/180*pi);
			for(k=0;k<n;k++)
			{
				s=judge(a[k],a[i],p);
				if(s<x1)
					x1=s;
				if(s>x2)
					x2=s;
				s=judge(a[k],a[i],q);
				if(s<y1)
					y1=s;
				if(s>y2)
					y2=s;
			}
			s=ll(maxx((x2-x1),(y2-y1)));
			if(s-minn<esp)
			{
				minn=s;
				ho=j;
			}
		}
		printf("%.2lf\n",minn);
	}
	return 0;
}

