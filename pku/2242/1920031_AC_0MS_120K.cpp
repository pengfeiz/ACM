#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
int main()
{
	double x1,x2,x3,y1,y2,y3,a,b,c,s,l,r;
	while(cin>>x1>>y1>>x2>>y2>>x3>>y3)
	{
		a=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
		b=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
		c=sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
		l=a+b+c;
		l/=2;
		s=sqrt(l*(l-a)*(l-b)*(l-c));
		r=a*b*c/s/4;
		printf("%.2lf\n",r*2*3.1415926535);
	}
	return 0;
}