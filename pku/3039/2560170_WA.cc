#include<stdio.h>
#include <math.h>
#define esp 1e-7
int main()
{
	double a,b,m,x,y,minn,mx,my;
	scanf("%lf%lf",&a,&b);
	m=b/a;
	minn=99999.0;
	x=y=1.0;
	while(y<32768)
	{
		if(fabs(a-x)<esp)
			x+=1.0;
		if(fabs(b-y)<esp)
			y+=1.0;
		if(fabs(y/x-m)<minn&&fabs(y/x-m)>esp)
		{
			my=y;
			mx=x;
			minn=fabs(y/x-m);
		}
		if(fabs((y+1)/x-m)>fabs(y/(x+1)-m))
			x++;
		else
			y++;
	}
	printf("%.0lf %.0lf\n",mx,my);		
	return 0;
}