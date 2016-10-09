#include <iostream>
#include <math.h>
using namespace std;
#define pi 3.14159265
int main()
{
	double h,r,d1,p1,d2,p2,t;
	while(scanf("%lf%lf%lf%lf%lf%lf",&r,&h,&d1,&p1,&d2,&p2)!=EOF)
	{
		t=fabs(p1-p2)/180*pi;
		if(t>pi)
			t=2*pi-t;
		t*=r/sqrt(h*h+r*r);
		t=sqrt(d1*d1+d2*d2-2*d1*d2*cos(t));
		printf("%.2lf\n",t);
	}
	return 0;
}


		