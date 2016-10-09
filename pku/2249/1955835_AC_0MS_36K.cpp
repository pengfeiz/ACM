#include<stdio.h>
void main()
{ 
	double s;
    long i,n,k;    
    while(scanf("%ld %ld",&n,&k)&&n)
	{
		s=1;
		if(k>n/2) 
			k=n-k;
		for(i=1;i<=k;i++)
		{ 
			s=s/i;
			s=s*(n-i+1);
		}
		printf("%.0f\n",s);
	}
}
