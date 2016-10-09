#include <stdio.h>
#include <math.h>
#include <string.h>
#define EPS 1e-10
double r,x,y,xx,yy,X,Y,dx,dy,dd,c;
void move(double x,double y,double X,double Y)
{
   char tmp[11];
   tmp[0]=0;
   if (Y-y>EPS)
	   strcpy(tmp,"north");
   if (Y-y<-EPS)
	   strcpy(tmp,"south");
   if (X-x>EPS)
	   strcat(tmp,"east");
   if (X-x<-EPS)
	   strcat(tmp,"west");
   printf("%s %0.10lf\n",tmp,hypot(X-x,Y-y));
}
int main()
{
	while (scanf("%lf%lf%lf%lf%lf",&r,&x,&y,&X,&Y)&&r!=-1) 
	{
		if(c++) 
			printf("\n");
		dx=fabs(X-x);
		dy=fabs(Y-y);
		if (dx==0||dy==0||dx==dy) 
		{
			move(x,y,X,Y);
			continue;
		}
		dd=dx<dy?dx:dy;
		xx=x+(X>x?dd:-dd);
		yy=y+(Y>y?dd:-dd);
		if(hypot(xx,yy)<r) 
		{
			move(x,y,xx,yy);
			move(xx,yy,X,Y);
			continue;
		}
		xx=X-(X>x?dd:-dd);
		yy=Y-(Y>y?dd:-dd);
		move(x,y,xx,yy);
		move(xx,yy,X,Y);
	}
	return 0;
}
