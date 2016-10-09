#include <iostream>
#include <math.h>
using namespace std;
#define esp 1e-6

double xx,yy;

bool dosth1_add(double x1,double x3,double y3,double x4,double y4)
{
	double a,b;
	a=(y4-y3)/(x4-x3);
	b=y3-a*x3;
	xx=x1;
	yy=a*xx+b;
	return true;
}

bool dosth2_add(double x1,double y1,double x2,double y2,double x3,double y3,double x4,double y4)
{
	double a1,b1,a2,b2;
	a1=(y2-y1)/(x2-x1);
	b1=y1-a1*x1;
	a2=(y4-y3)/(x4-x3);
	b2=y3-a2*x3;
	//重合情况需要在这里加
	if(fabs(a1-a2)<esp)
		return false;
	xx=(b1-b2)/(a2-a1);
	yy=xx*a1+b1;
	return true;
}

bool compute_add(double x1,double y1,double x2,double y2,double x3,double y3,double x4,double y4)
{
	if(fabs(x1-x2)<esp)
	{
		if(fabs(x3-x4)<esp)
			return false;
		return dosth1_add(x1,x3,y3,x4,y4);
	}
	if(fabs(x3-x4)<esp)
		return dosth1_add(x3,x1,y1,x2,y2);
	return dosth2_add(x1,y1,x2,y2,x3,y3,x4,y4);
}

int main()
{
	double x1,y1,x2,y2,x3,y3,x4,y4;
	while(scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4))
	{
		if(!compute_add(x1,y1,x2,y2,x3,y3,x4,y4))
			printf("No\n");
		else
			printf("%lf %lf\n",xx,yy);
	}
	return 0;
}
