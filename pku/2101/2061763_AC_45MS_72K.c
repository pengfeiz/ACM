#include <stdio.h>
#include <math.h>
#include <stdlib.h>
main()
{
	int n,m,i;
	double x,y,d;
	x=y=0;
	scanf("%d%d",&n,&m);
	for(i=1;i<n;i++)
	{
		scanf("%lf",&d);
		x+=d;
	}
	for(i=1;i<m;i++)
	{
		scanf("%lf",&d);
		y+=d;
	}
	printf("%d\n",(int)ceil(sqrt(x*x+y*y)));
}
	

