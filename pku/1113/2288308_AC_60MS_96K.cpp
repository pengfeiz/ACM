#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;


#define MAX 1003
#define esp 1e-8
#define pi 3.1415926535


struct poi
{
	double x,y;
}a[MAX];


int n,d[MAX],p;
bool u[MAX];
double s,l;


bool com(poi a,poi b)
{
	if(a.y!=b.y)
		return a.y<b.y;
	return a.x<b.x;
}


void init()
{
	int i;
	scanf("%d",&n);
	scanf("%lf",&s);
	s*=pi*2;
	for(i=1;i<=n;i++)
		scanf("%lf%lf",&a[i].x,&a[i].y);
}


bool cha(double x1,double y1,double x2,double y2)
{
	double x;
	x=x1*y2-x2*y1;
	if(x>esp)
		return true;
	return false;
}


void ready()
{sort(a+1,a+1+n,com);}


void tubao()
{
	int i;
	memset(u,0,sizeof(u));
	d[1]=1;
	d[2]=p=2;
	u[2]=true;
	for(i=3;i<=n;i++)
	{
		while( p>1 && cha( a[d[p]].x-a[d[p-1]].x , a[d[p]].y-a[d[p-1]].y , a[i].x-a[d[p-1]].x , a[i].y-a[d[p-1]].y))
			u[d[p--]]=false;
		d[++p]=i;
		u[i]=true;
	}
	for(i=n;i>0;i--)
	{
		if(!u[i])
		{
			while(cha( a[d[p]].x-a[d[p-1]].x , a[d[p]].y-a[d[p-1]].y , a[i].x-a[d[p-1]].x , a[i].y-a[d[p-1]].y))
				u[d[p--]]=false;
			d[++p]=i;
			u[i]=true;
		}
	}
}


double ll(double x)
{return x*x;}
double dis(poi a,poi b)
{return sqrt(ll(a.x-b.x)+ll(a.y-b.y));}


void solve()
{
	int i;
	d[p+1]=d[1];
	for(i=1;i<=p;i++)
		s+=dis(a[d[i]],a[d[i+1]]);
	printf("%.0lf\n",s);
}


int main()
{
	init();
	ready();
	tubao();
	solve();
	return 0;
}
