#include <iostream>
#include <math.h>
using namespace std;

struct gao
{
	double x,y;
}a[100],z[8]={1,0,-1,0,0,1,0,-1,1,1,1,-1,-1,1,-1,-1};

int n;
double x,y,xx,yy;


double ll(double a)
{return a*a;}

int main()
{
	int i,j;
	double t,maxx;
	bool f;
	while(scanf("%d",&n)!=EOF)
	{
		f=true;
		for(i=0;i<n;i++)
			scanf("%lf%lf",&a[i].x,&a[i].y);
		x=y=500.0;
		maxx=1e18;
		while(f)
		{
			f=false;
			for(j=0;j<8;j++)
			{
				t=0;
				xx=x+z[j].x;
				yy=y+z[j].y;
				for(i=0;i<n;i++)
					t+=sqrt(ll(a[i].x-xx)+ll(a[i].y-yy));
				if(t<maxx)
				{
					x=xx;
					y=yy;
					maxx=t;
					f=true;
				}
			}
		}
		printf("%.0lf\n",maxx);
	}
	return 0;
}

	