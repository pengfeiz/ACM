#include <iostream>
#include <math.h>
using namespace std;


float r=3950,R=432000,D=92900000;
float pi;
float L,t1,t2,b1,b;
float d,g,f;

float degree(float a)
{return a*180.0/pi;}
float betaT(float t)
{return b1-2*pi*t/24.0/3600.0;}


int main()
{
	float t;
	pi=4*atan(1);
	L=sqrt(D*D+R*R-r*r);
	t1=atan(R/D);
	t2=atan(L/r);
	b1=t1+t2;
	while(scanf("%f",&t)!=EOF)
	{
		b=betaT(t);
		d=(D*cos(b)-r)/sin(b);
		if(d<=-R)
			g=pi/2.0;
		else if((d>-R)&&(d<R))
			g=asin(d/R);
		else
			g=pi/2;
		f=0.5+g/pi+d*cos(g)/pi/R;
		printf("%.6f\n",f);
	}
	return 0;
}