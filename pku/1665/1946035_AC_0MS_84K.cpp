#include<iostream.h>
#include<stdio.h>
void main()
{	
	double d,t,l,v,r;
	int n=0;	
	while (cin>>d>>r>>t&&r)
	{       
		l=d*r*3.1415927/12/5280;
		v=l/t*3600;
		n++;
		printf("Trip #%d: %0.2f %0.2f\n",n,l,v);
	}
}