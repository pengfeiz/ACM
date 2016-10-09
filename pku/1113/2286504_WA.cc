#include <iostream>
#include <math.h>
using namespace std;


#define MAX 1002
#define esp 1e-6
#define pi 3.1415926535


struct poi
{
	double x,y;
}a[MAX],c[MAX];


bool b[MAX];
int n,d[MAX],p;
double s,l;


void init()
{
	int i;
	scanf("%d",&n);
	scanf("%lf",&s);
	s*=pi*2;
	for(i=0;i<n;i++)
		scanf("%lf%lf",&c[i].x,&c[i].y);
	memset(b,0,sizeof(b));
}


bool cha(double x1,double y1,double x2,double y2)
{
	double x;
	x=x1*y2-x2*y1;
	if(x>-esp)
		return true;
	return false;
}


void ready()
{
	int i,m;
	m=0;
	for(i=1;i<n;i++)
	{
		if(c[i].y<c[m].y)
			m=i;
		else if(c[i].y==c[m].y&&c[i].x<c[m].x)
			m=i;
	}
	for(i=0;i<n;i++)
	{
		a[i].x=c[(i+m)%n].x;
		a[i].y=c[(i+m)%n].y;
	}
}


void tubao()
{
	int i;
	d[0]=0;
	d[1]=p=1;
	b[0]=b[1]=true;
	for(i=2;i<n;i++)
	{
		while( p && cha( a[d[p]].x-a[d[p-1]].x , a[d[p]].y-a[d[p-1]].y , a[i].x-a[d[p-1]].x , a[i].y-a[d[p-1]].y))
			b[d[p--]]=false;
		d[++p]=i;
		b[i]=true;
	}

}


double ll(double x)
{return x*x;}
double dis(poi a,poi b)
{return ll(a.x-b.x)+ll(a.y-b.y);}


void solve()
{
	int i;
	d[p+1]=d[0];
	for(i=0;i<=p;i++)
		s+=sqrt(dis(a[d[i]],a[d[i+1]]));
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