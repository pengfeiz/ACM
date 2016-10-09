#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	double x,y,c,z,i,j,q;
	while(scanf("%lf%lf%lf",&x,&y,&c)!=EOF)
	{
		i=0;
		j=x>y?y:x;
		c=1/c;
		while(1)
		{
			z=(i+j)/2;
			q=c-1/sqrt(x*x-z*z)-1/sqrt(y*y-z*z);
			if(fabs(q)<1e-6)
				break;
			else if(q>0)
				i=z;
			else
				j=z;
		}
		printf("%.3lf\n",z);
	}
	return 0;
}
				
			