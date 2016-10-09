#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;
int main()
{
	double x1,y1,r1,x2,y2,r2,a,b,pi,s;
	pi=3.1415926535;
	while(cin>>x1>>y1>>r1>>x2>>y2>>r2)
	{
		a=b=s=0;
		a=sqrt((x1-x2)*(x1-x2)+(y2-y1)*(y2-y1));
		if(a>=r1+r2)
		{
			printf("0.000\n");
			continue;
		}
		else if(a<=r1-r2)
		{
			printf("%.3lf\n",pi*r2*r2);
			continue;
		}
		else if(a<=r2-r1)
		{
			printf("%.3lf\n",pi*r1*r1);
			continue;
		}
		b=a+r1+r2;
		b/=2;
		s=sqrt(b*(b-a)*(b-r1)*(b-r2));
		b=4*s/a;
		s*=2;
		s=-s;
		b/=2;
		if(r1*r1+a*a-r2*r2>0)
			s+=asin(b/r1)*r1*r1;
		else
			s+=pi*r1*r1-asin(b/r1)*r1*r1;
		if(r2*r2+a*a-r1*r1>0)
			s+=asin(b/r2)*r2*r2;
		else
			s+=pi*r2*r2-asin(b/r2)*r2*r2;
		printf("%.3lf\n",s);
	}
	return 0;
}


