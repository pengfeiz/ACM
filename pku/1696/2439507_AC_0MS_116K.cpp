#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

#define MAX 101
#define esp 1e-7

struct poi
{
	double x,y;
	int n;
}a[MAX];

bool com(poi a,poi b)
{
	if(fabs(a.y-b.y)>esp)
		return a.y<b.y;
	return a.x<b.x;
}

int n,m;
bool b[MAX];
int c[MAX];

double cha(double x1,double y1,double x2,double y2)
{return x1*y2-x2*y1;}
double ll(double x)
{return x*x;}

double compute(poi a,poi b,poi c)
{
	double x1,y1,x2,y2,l1,l2,l3;
	x1=b.x-a.x;
	y1=b.y-a.y;
	x2=c.x-b.x;
	y2=c.y-b.y;
	if(cha(x1,y1,x2,y2)<-esp)
		return 9999;
	l1=ll(x1)+ll(y1);
	l2=ll(x2)+ll(y2);
	l3=ll(x2-x1)+ll(y2-y1);
	return acos((l1+l2-l3)/(2*sqrt(l1*l2)));
}

int main()
{
	int i,t,p;
	double angle,ma;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d%lf%lf",&a[i].n,&a[i].x,&a[i].y);
		memset(b,0,sizeof(b));
		sort(a+1,a+n+1,com);

		a[0].x=a[0].n=c[0]=0;
		a[0].y=a[1].y;
		m=c[1]=1;
		b[0]=b[1]=true;

		do
		{
			m++;
			p=-1;
			ma=999;
			for(i=0;i<=n;i++)
			{
				if(b[i])
					continue;
				angle=compute(a[c[m-2]],a[c[m-1]],a[i]);
				if(angle<ma-esp)
				{
					ma=angle;
					p=i;
				}
			}
			if(p>0)
			{
				c[m]=p;
				b[p]=true;
			}
		}while(p>0);

		printf("%d",m-1);
		for(i=1;i<m;i++)
			printf(" %d",a[c[i]].n);
		printf("\n");

	}
	return 0;
}
