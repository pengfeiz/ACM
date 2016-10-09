#include <iostream>
#include <math.h>
using namespace std;

struct gao
{
	__int64 x,y;
}a[100],z[4]={1,0,-1,0,0,1,0,-1};

__int64 n;
__int64 x,y,xx,yy;


__int64 ll(__int64 a)
{return a*a;}
int main()
{
	__int64 i,j;
	double t,maxx;
	bool f;
	while(scanf("%I64d",&n)!=EOF)
	{
		f=true;
		for(i=0;i<n;i++)
			scanf("%I64d%I64d",&a[i].x,&a[i].y);
		x=y=500;
		maxx=1e18;
		while(f)
		{
			for(j=0;j<4;j++)
			{
				f=false;
				t=0;
				xx=x+z[j].x;
				yy=y+z[j].y;
				for(i=0;i<n;i++)
					t+=sqrt(ll(a[i].x-xx)+ll(a[i].y-yy)*1.0);
				if(t<maxx)
				{
					x=xx;
					y=yy;
					maxx=t;
					f=true;
					break;
				}
			}
		}
		printf("%.0lf\n",maxx);
	}
	return 0;
}

	