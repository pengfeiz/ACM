#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;
double s;
double compute(double i,double n)
{
	double t=1,j;
	if(2*i>n)
		i=n-i;
	for(j=0;j<i;j++)
	{
		t*=(n-j);
		t/=j+1;
	}
	return t;
}
int main()
{	
	double n,m;
	int i;
	while(scanf("%lf",&n)&&n)
	{
		i=1;
		m=1;
		s=1/n;
		while(compute(i*1.0,n-2)*pow(s,i*1.0)>1e-20&i<=n-2)
		{
			if(i%2)
				m=m-compute(i*1.0,n-2)*pow(s,i*1.0);
			else
				m=m+compute(i*1.0,n-2)*pow(s,i*1.0);
			i++;
		}
		m-=0.0000000000000049;
		printf("%.14lf\n",m);
	}
	return 0;
}

