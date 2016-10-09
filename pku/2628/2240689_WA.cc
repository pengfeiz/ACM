#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
#define pi 3.1415926
#define esp 1e-8
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
		return false;
	return true;
}
	
int main()
{
	int i,j,k,xx,yy;
	double t,maxx;
	while(scanf("%d",&n),n)
	{
		maxx=9999999;
		for(i=0;i<n;i++)
		{
			scanf("%lf",&a[i].l);
			a[i].x=sin(i*1.0/double(n)*pi*2.0);
			a[i].y=cos(i*1.0/double(n)*pi*2.0);
		}
		sort(a,a+n,com);
		for(xx=1;xx>=0;xx--)
			if(fabs(a[xx].l-a[2].l)>esp)
				break;
		xx++;
		for(yy=3;yy<n;yy++)
			if(fabs(a[yy].l-a[2].l)>esp)
				break;
		if(xx==0)
		{
			for(i=xx;i<yy;i++)
				for(j=i+1;j<yy;j++)
					for(k=j+1;k<yy;k++)
					{
						if(dosth(i,j,k)&&dosth(j,i,k)&&dosth(k,i,j))
						{
							t=fabs(a[i].l-a[k].l);
							t+=fabs(a[j].l-a[k].l);
							if(t<maxx)
								maxx=t;
						}
					}
		}
		else if(xx==1)
		{	
			i=0;
			for(j=i+1;j<yy;j++)
				for(k=j+1;k<yy;k++)
				{
					if(dosth(i,j,k)&&dosth(j,i,k)&&dosth(k,i,j))
					{
						t=fabs(a[i].l-a[k].l);
						t+=fabs(a[j].l-a[k].l);
						if(t<maxx)
							maxx=t;
					}
				}
		}
		else if(xx==2)
		{
			i=0;
			j=1;
			for(k=j+1;k<yy;k++)
			{
				if(dosth(i,j,k)&&dosth(j,i,k)&&dosth(k,i,j))
				{
					t=fabs(a[i].l-a[k].l);
					t+=fabs(a[j].l-a[k].l);
					if(t<maxx)
						maxx=t;
				}
			}
		}
		if(n>3)
		{
			t=0;
			for(i=0;i<n;i++)
				t+=a[i].l-a[n-1].l;
			if(t<maxx)
				maxx=t;
		}
		printf("%.0lf\n\n",maxx);
	}
	return 0;
}


