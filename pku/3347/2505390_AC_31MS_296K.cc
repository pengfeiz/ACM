#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
#define MAX 55
#define E 1e-5
#define esp 1e-9

struct poi
{
	double x,y;
}p;


struct gao
{
	poi a,b,c,d;
}a[MAX];

double b[MAX];
bool d[MAX];
double bb[410];
int tt;
int n,m;

double cha(double x1,double y1,double x2,double y2)
{return x1*y2-x2*y1;}
double dian(double x1,double y1,double x2,double y2)
{
	if(fabs(x1)<esp)
		x1=fabs(x1);
	if(fabs(x2)<esp)
		x2=fabs(x2);
	if(fabs(y1)<esp)
		y1=fabs(y1);
	if(fabs(y2)<esp)
		y2=fabs(y2);
	return x1*x2+y1*y2;
}


void jiao(poi pa,poi pb,poi pc,poi pd,poi &p)
{
	double s1,s2;
	s1=cha(pa.x-pc.x,pa.y-pc.y,pd.x-pc.x,pd.y-pc.y);
	s2=cha(pd.x-pc.x,pd.y-pc.y,pb.x-pc.x,pb.y-pc.y);
	p.x=(s1*pb.x+s2*pa.x)/(s1+s2);
	p.y=(s1*pb.y+s2*pa.y)/(s1+s2);
}

bool judge(double mid,double l)
{
	int i;
	poi h1;
	poi h2;
	h1.x=mid;
	h1.y=0;
	h2.x=mid-sqrt(l*l/2.0);
	h2.y=sqrt(l*l/2.0);
	for(i=0;i<m;i++)
	{	
		if(mid<a[i].b.x)
			return false;
		jiao(a[i].b,a[i].c,h1,h2,p);
		if(dian(p.x-h1.x,p.y-h1.y,h2.x-p.x,h2.y-p.y)>-esp&&dian(p.x-a[i].c.x,p.y-a[i].c.y,a[i].b.x-p.x,a[i].b.y-p.y)>-esp)
			return false;
	}
	return true;
}



int judge2(double l)
{
	int i,k=n;
	poi h1,h2;
	h1.y=0;
	h2.y=100;
	h1.x=h2.x=l;
	double w=0.0;
	for(i=0;i<n;i++)
	{
		jiao(h1,h2,a[i].c,a[i].d,p);
		if(dian(p.x-a[i].c.x,p.y-a[i].c.y,a[i].d.x-p.x,a[i].d.y-p.y)>-E)
		{
			if(p.y>w+E)
			{
				w=p.y;
				k=i;
			}
			if(fabs(p.y-w)<E&&!d[k])
				k=i;
		}
		jiao(h1,h2,a[i].a,a[i].d,p);
		if(dian(p.x-a[i].a.x,p.y-a[i].a.y,a[i].d.x-p.x,a[i].d.y-p.y)>-E)
		{
			if(p.y>w+E)
			{
				w=p.y;
				k=i;
			}
			if(fabs(p.y-w)<E&&!d[k])
				k=i;
		}
	}
	return k;
}



int main()
{
//	freopen("in.txt","r",stdin);
	int i,t,j;
	double l;
	double aa,bbb,mid;
	while(scanf("%d",&n),n)
	{
		tt=0;
		for(i=0;i<n;i++)
			scanf("%lf",&b[i]);
		l=sqrt(b[0]*b[0]/2.0);
		a[0].a.x=0;
		a[0].a.y=l;
		a[0].b.x=l;
		a[0].b.y=0;
		a[0].c.x=2*l;
		a[0].c.y=l;
		a[0].d.x=l;
		a[0].d.y=2*l;
		bb[tt++]=0.01;
		bb[tt++]=l-0.01;
		bb[tt++]=l+0.01;
		bb[tt++]=2*l-0.01;
		bb[tt++]=2*l+0.01;
		m=0;
		for(i=1;i<n;i++)
		{
			m++;
			aa=0;
			bbb=99999;
			l=sqrt(b[i]*b[i]/2.0);
			while(bbb-aa>esp)
			{
				mid=(aa+bbb)/2;
				if(judge(mid,b[i]))
					bbb=mid;
				else
					aa=mid;
			}		
			a[i].a.x=mid-l;	
			a[i].a.y=l;
			a[i].b.x=mid;
			a[i].b.y=0;
			a[i].c.x=l+mid;
			a[i].c.y=l;
			a[i].d.x=mid;
			a[i].d.y=2*l;
			bb[tt++]=mid-0.01;
			bb[tt++]=mid+l-0.01;
			bb[tt++]=mid+l+0.01;
			bb[tt++]=mid+0.01;
			bb[tt++]=mid-l+0.01;
			bb[tt++]=mid-l-0.01;
		}
//		for(i=0;i<n;i++)
//			a[i].d.y-=0.01;
		memset(d,0,sizeof(d));
		l=0.0;
		t=0;
		d[n]=true;
		sort(bb,bb+tt);
		for(j=0;j<tt;j++)
		{
			l=bb[j];
			i=judge2(l);
			if(!d[i])
				d[i]=true;
		}
		for(i=0;i<n;i++)
		{
			if(d[i])
			{
				if(t)
					printf(" ");
				printf("%d",i+1);
				t++;
			}
		}
		printf("\n");
	}
	return 0;
}


