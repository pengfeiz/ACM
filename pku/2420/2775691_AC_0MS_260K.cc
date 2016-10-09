#include <iostream>
#include <math.h>
using namespace std;

struct gao
{
	int x,y;
}a[100],z[4]={1,0,-1,0,0,1,0};

int n;
int x,y,xx,yy;


int ll(int a)
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
			scanf("%d%d",&a[i].x,&a[i].y);
		x=y=5000;
		maxx=1e18;
		while(f)
		{
			f=false;
			for(j=0;j<4;j++)
			{
				t=0;
				xx=x+z[j].x;
				yy=y+z[j].y;
				for(i=0;i<n;i++)
				{
					t+=sqrt(ll(a[i].x-xx)+ll(a[i].y-yy));
					if(t>maxx)
						break;
				}
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
