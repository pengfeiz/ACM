#include <iostream>
#include <math.h>
using namespace std;
#define MAX 1001
#define esp 1e-9

struct poi
{
	double x,y;
}a[MAX];

int n,m,b[MAX];
double s,ma;

double compute(poi a,poi b,poi c)
{return (a.x*b.y+b.x*c.y+c.x*a.y)-(a.y*b.x+b.y*c.x+c.y*a.x);}


int main()
{
	int i,t,j,tt,he;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%lf%lf",&a[i].x,&a[i].y);
		scanf("%d",&tt);
		s=-1;
		he=1;
		for(j=1;j<=tt;j++)
		{
			scanf("%d",&m);
			for(i=0;i<m;i++)
				scanf("%d",&b[i]);
			if(m>2)	
			{
				ma=0;
				for(i=2;i<m;i++)
					ma+=compute(a[b[0]],a[b[i-1]],a[b[i]]);
				ma=fabs(ma);
			}
			if(ma>s)
			{
				s=ma;
				he=j;
			}
		}
		printf("%d\n",he);
	}
	return 0;
}
		

