#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;


#define MAX 50003
#define esp 1e-10


struct poi
{
	double x,y;
}a[MAX];


int n,d[MAX],p;
bool u[MAX];


bool com(poi a,poi b)
{
	if(a.y!=b.y)
		return a.y<b.y;
	return a.x<b.x;
}


bool init()
{
	int i;
	scanf("%d",&n);
	if(n<0)
		return false;
	for(i=1;i<=n;i++)
		scanf("%lf%lf",&a[i].x,&a[i].y);
	sort(a+1,a+1+n,com);
	return true;
}

double cha(double x1,double y1,double x2,double y2)
{return x1*y2-x2*y1;}


void tubao()
{
	int i;
	memset(u,0,sizeof(u));
	d[1]=1;
	d[2]=p=2;
	u[2]=true;
	for(i=3;i<=n;i++)
	{
		while( p>1 && cha( a[d[p]].x-a[d[p-1]].x , a[d[p]].y-a[d[p-1]].y , a[i].x-a[d[p]].x , a[i].y-a[d[p]].y)>=0)
			u[d[p--]]=false;
		d[++p]=i;
		u[i]=true;
	}
	for(i=n;i>1;i--)
	{
		if(!u[i])
		{
			while(cha( a[d[p]].x-a[d[p-1]].x , a[d[p]].y-a[d[p-1]].y , a[i].x-a[d[p]].x , a[i].y-a[d[p]].y)>esp)
				u[d[p--]]=false;
			d[++p]=i;
			u[i]=true;
		}
	}
}

double ll(double x)
{return x*x;}
double dis(poi a,poi b)
{return ll(a.x-b.x)+ll(a.y-b.y);}
double compute2(double x,double y,double z)
{
	double p;
	p=(x+y+z)/2;
	return sqrt(p*(p-x)*(p-y)*(p-z));
}
double compute(poi a,poi b,poi c)
{return compute2( sqrt( ll(a.x-b.x)+ll(a.y-b.y) ), sqrt( ll(a.x-c.x)+ll(a.y-c.y)), sqrt(ll(b.x-c.x)+ll(b.y-c.y)));}

void slove()
{
	int i,p1,p2;
	bool f;
	double ma=0,s1,s2;
	if(n<3)
	{
		printf("%.2lf\n",ma);
		return;
	}
	p1=2;
	p2=3;
	for(i=1;i<=p;i++)
	{
		s1=compute(a[i],a[p1],a[p2]);
		do
		{
			f=false;
			while(1)
			{
				s2=compute(a[i],a[p1%p+1],a[p2]);
				if(s2>s1)
				{
					s1=s2;
					f=true;
					p1=p1%p+1;
				}
				else
					break;
			}
			while(1)
			{
				s2=compute(a[i],a[p1],a[p2%p+1]);
				if(s2>s1)
				{
					s1=s2;
					f=true;
					p2=p2%p+1;
				}
				else
					break;
			}
			while(1)
			{
				s2=compute(a[i],a[p1%p+1],a[p2%p+1]);
				if(s2>s1)
				{
					s1=s2;
					f=true;
					p2=p2%p+1;
					p1=p1%p+1;
				}
				else
					break;
			}
		}while(f);
		if(s1>ma)
			ma=s1;
	}
	printf("%.2lf\n",ma);
}


int main()
{
	while(init())
	{
		tubao();
		slove();
	}
	return 0;
}