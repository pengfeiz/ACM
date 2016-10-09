#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
#define MA 10004
double espp=0.0000001;

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
	if(fabs(a.k-b.k)>espp)
		return a.k<b.k;
	if(fabs(a.x1-b.x1)>espp)
		return a.x1<b.x1;
	return a.y1<b.y1;
}

double maxx(double x,double y)
{return x>y?x:y;}
double minn(double x,double y)
{return x<y?x:y;}


int n;

int main()
{
//	freopen("in.txt","r",stdin);
	int i,t;
	double x1,y1,x2,y2,x,y;
	while(scanf("%d",&n),n)
	{
		t=0;
		for(i=0;i<n;i++)
		{
			scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
			if(x1>x2)
			{
				swapp(x1,x2);
				swapp(y1,y2);
			}
			else if(fabs(x1-x2)<espp&&y1>y2)
			{
				swapp(x1,x2);
				swapp(y1,y2);
			}
			a[i].x1=x1;
			a[i].x2=x2;
			a[i].y1=y1;
			a[i].y2=y2;
			if(fabs(x1-x2)<espp)
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
			x=maxx(x,a[i].x2);
			if(a[i].k>=0)
				y=maxx(y,a[i].y2);
			else
				y=minn(y,a[i].y2);
			t++;
			while(fabs(a[i].k-a[i+1].k)<espp&&(a[i+1].x1-x)<espp&&(((a[i+1].y1-y)<espp&&a[i+1].k>=0)||((a[i+1].y1-y)>-espp&&a[i+1].k<0)))
			{
				i++;
				x=maxx(x,a[i].x2);
				if(a[i].k>=0)
					y=maxx(y,a[i].y2);
				else
					y=minn(y,a[i].y2);
			}
			x=-99999999;
			if(a[i].k>=0)
				y=-99999999;
			else
				y=99999999;
		}
		printf("%d\n",t);
	}
	return 0;
}


