#include <iostream>
#include <math.h>
using namespace std;
#define y 1e-5
int main()
{
	double x,i,m,w,p;
	while(scanf("%lf",&x),x!=0.0)
	{
		i=m=1;
		if(x<0)
		{
			p=2.0;
			x=-x;
		}
		else
			p=1.0;
		while(1)
		{
			w=pow(x,1.0/i);
			if(w<2)
				break;
			if(fabs(w-ceil(w-y))<=y)
				m=i;
			i+=p;
		}
		printf("%.0lf\n",m);
	}
	return 0;
}

