#include <math.h>
#include <stdio.h>
#define Pi 3.1415926
int main()
{
	double D,d,V;
	while(scanf("%lf%lf",&D,&V)&&(D||V))
	printf("%.3lf\n",pow(D*D*D-6*V/Pi,1.0/3));

}