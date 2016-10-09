#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;
#define esp 1e-15

int main()
{
	int i,l;
	double a,h,h1,h2,md,ml,mm;
	scanf("%lf%d",&a,&l);
	mm=99999999;
	for(i=1;i<=l;i++)
	{
		h=i*a;
		h1=floor(h);
		h2=floor(h+1.0);
		if(fabs(h1-h)/(i*1.0)<mm-esp&&h1<(l*1.0+esp))
		{
			md=h1;
			ml=i*1.0;
			mm=fabs(h1-h)/(i*1.0);
		}
		else if(fabs(h2-h)/(i*1.0)<mm-esp&&h2<(l*1.0+esp))
		{
			md=h2;
			ml=i*1.0;
			mm=fabs(h2-h)/(i*1.0);
		}
	}
	printf("%.0lf %.0lf\n",md,ml);
	return 0;
}
		