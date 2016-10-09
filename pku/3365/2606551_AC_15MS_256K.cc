#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
#define pi 3.14159265357

double n,m,maxx;
int nn,mm;
double minn(double a,double b)
{return a<b?a:b;}

int main()
{
	double r,rr;
	while(scanf("%d%d",&mm,&nn),nn||mm)
	{
		n=double(nn);
		m=double(mm);
		maxx=0;
		r=minn(n/(2+2*pi),m/2);
		if(r*r*pi*m>maxx)
		{
			rr=r;
			maxx=r*r*pi*m;
		}
		r=minn(n/3,m/pi/2);
		if(r*r*pi*(n-2*r)>maxx)
		{
			rr=r;
			maxx=r*r*pi*(n-2*r);
		}
		printf("%.3lf\n",maxx);
	}
	return 0;
}

