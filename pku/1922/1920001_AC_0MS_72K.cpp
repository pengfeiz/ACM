#include <stdio.h>
#include <math.h>
int main()
{
	int n,s,t,i;	
	while(scanf("%d",&n)&&n!=0)
	{
		double time,sum;
		sum=0;
		time=99999999;
		for(i=0;i<n;i++)
		{
			scanf("%d %d",&s,&t);
			if(t>=0)
			{
				double d=ceil(4500*3.6/(double)s+(double)t);				
				if(d<time)
					time=d;
			}
		}		
		printf("%.0lf\n",time);
	}
	return 0;
}
 
