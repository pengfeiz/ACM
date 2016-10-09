#include <iostream>
#include <algorithm>
using namespace std;

struct gao
{
	double x,y;
}a[4];

int main()
{
	int i,j,t;
	double x1,y1,x2,y2;
	while(scanf("%lf%lf",&a[0].x,&a[0].y)!=EOF)
	{
		for(i=1;i<4;i++)
			scanf("%lf%lf",&a[i].x,&a[i].y);
		for(i=0;i<3;i++)
			for(j=i+1;j<4;j++)
				if(a[i].x==a[j].x&&a[i].y==a[j].y)
					t=i;
		swap(a[0],a[t]);
		for(i=1;i<4;i++)
			if(a[i].x==a[0].x&&a[i].y==a[0].y)
				swap(a[i],a[3]);
		x1=a[1].x-a[0].x;
		x2=a[2].x-a[0].x;
		y1=a[1].y-a[0].y;
		y2=a[2].y-a[0].y;
		x1+=x2;
		y1+=y2;
		printf("%.3lf %.3lf\n",a[0].x+x1,a[0].y+y1);
	}
	return 0;
}