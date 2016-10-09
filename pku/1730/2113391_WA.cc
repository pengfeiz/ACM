#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	double x,i,m,w;
	while(scanf("%lf",&x),x!=0.0)
	{
		i=m=1;
		while(1)
		{
			w=pow(x,1/i);
			if(w<2)
				break;
			if(ceil(w)==w)
				m=i;
			i++;
		}
		printf("%.0lf\n",m);
	}
	return 0;
}

