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


void init()
{
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%lf%lf",&a[i].x,&a[i].y);
	sort(a+1,a+1+n,com);
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
	for(i=n;i>0;i--)
	{
		if(!u[i])
		{
			while(cha( a[d[p]].x-a[d[p-1]].x , a[d[p]].y-a[d[p-1]].y , a[i].x-a[d[p]].x , a[i].y-a[d[p]].y)>esp)
				u[d[p--]]=false;
			d[++p]=i;
			u[i]=true;
		}
	}
p--;
}

double ll(double x)
{return x*x;}
double dis(poi a,poi b)
{return ll(a.x-b.x)+ll(a.y-b.y);}


void slove()
{
	int i,j;
	double ma=0;
	if(n==2)
		ma=dis(a[1],a[2]);
	else
		for(i=1;i<p;i++)
			for(j=i+1;j<=p;j++)
				if(ma<dis(a[d[i]],a[d[j]]))
					ma=dis(a[d[i]],a[d[j]]);
	printf("%.0lf\n",ma);
}


int main()
{
	init();
	tubao();
	slove();
	return 0;
}
