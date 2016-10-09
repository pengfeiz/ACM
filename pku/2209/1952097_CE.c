#include <stdio.h>
#include <math.h>
void main()
{
	long n,e,r[105],t,total=0;
	scanf("%d",&n);
	scanf("%d",&e);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&t);
		r[i]=(long)pow(t*1.0,e*1.0);
	}
	for(i=0;i<n;i++)
		if(r[i]>0)
			total+=r[i];
	printf("%ld\n",total);
}
