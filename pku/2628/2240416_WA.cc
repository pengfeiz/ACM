#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
#define pi 3.1415926
#define esp 1e-5
#define MAX 60

struct gao
{
	double l,x,y;
}a[MAX];

int n;

bool com(gao a,gao b)
{
	return a.l>b.l;
}

bool dosth(int p,int q,int r)
{
	double x1,y1,x2,y2,angle,l1,l2,l3;
	x1=a[q].x-a[p].x;
	y1=a[q].y-a[p].y;
	x2=a[r].x-a[p].x;
	y2=a[r].y-a[p].y;
	l1=x1*x1+y1*y1;
	l2=x2*x2+y2*y2;
	l3=pow(x1-x2,2)+pow(y1-y2,2);
	angle=acos((l1+l2-l3)/(2.0*sqrt(l1*l2)));
	if(2*angle>pi-esp)
		return true;
	return false;
}
	
int main()
{
	int i;
	double t;
	while(scanf("%d",&n),n)
	{
		t=0;
		for(i=0;i<n;i++)
		{
			scanf("%lf",&a[i].l);
			a[i].x=sin(i*1.0/double(n)*pi*2.0);
			a[i].y=cos(i*1.0/double(n)*pi*2.0);
		}
		sort(a,a+n,com);
		if(dosth(0,1,2)||dosth(1,2,0)||dosth(2,0,1))
		{
			for(i=0;i<3;i++)
				t+=a[i].l-a[3].l;
			printf("%.0lf\n\n",t);
		}
		else
		{
			for(i=0;i<2;i++)
				t+=a[i].l-a[2].l;
			printf("%.0lf\n\n",t);
		}
	}
	return 0;
}


