#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
#define MA 4
#define esp 1e-8

struct gao
{
	double x1,y1,x2,y2;
	double k;
}a[MA];

void swapp(double &x,double &y)
{
	double s;
	s=x;
	x=y;
	y=s;
}

bool com(gao a,gao b)
{
	if(fabs(a.k-b.k)>esp)
		return a.k<b.k;
	if(fabs(a.x1-b.x1)>esp)
		return a.x1<b.x1;
	return a.y1<b.y1;
}

double maxx(double x,double y)
{return x>y?x:y;}
double minn(double x,double y)
{return x<y?x:y;}

bool b[MA];

int n;

int main()
{
	int i,t;
	double x1,y1,x2,y2,x,y;
	while(scanf("%d",&n),n)
	{
		t=0;
		memset(b,0,sizeof(b));
		for(i=0;i<n;i++)
		{
			scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
			if(x1>x2)
			{
				swapp(x1,x2);
				swapp(y1,y2);
			}
			else if(fabs(x1-x2)<esp&&y1>y2)
			{
				swapp(x1,x2);
				swapp(y1,y2);
			}
			a[i].x1=x1;
			a[i].x2=x2;
			a[i].y1=y1;
			a[i].y2=y2;
			if(fabs(x1-x2)<esp)
				a[i].k=9999999999.0;
			else
				a[i].k=(y2-y1)/(x2-x1);
		}
		sort(a,a+n,com);
		a[n].x1=999999;
		a[n].y1=999999;
		a[n].k=999;
		t=0;
		x=-99999999;
		if(a[0].k>=0)
			y=-99999999;
		else
			y=99999999;
		for(i=0;i<n;i++)
		{
			if(b[i])
				continue;
			b[i]=true;
			x=maxx(x,a[i].x2);
			if(a[i].k>=0)
				y=maxx(y,a[i].y2);
			else
				y=minn(y,a[i].y2);
			t++;
			if(fabs(a[i].k-a[i+1].k)>esp)
				continue;
			while(a[i+1].x1-x<esp&&((a[i+1].y1-y<esp&&a[i+1].k>=0)||(a[i+1].y1-y>-esp&&a[i+1].k<0)))
			{
				i++;
				x=maxx(x,a[i].x2);
				if(a[i].k>=0)
					y=maxx(y,a[i].y2);
				else
					y=minn(y,a[i].y2);
				b[i]=true;
			}
		}
		printf("%d\n",t);
	}
	return 0;
}


