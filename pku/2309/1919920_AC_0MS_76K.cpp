#include <stdio.h>
#include <math.h>
main()
{
	long p,n,i,m;
	scanf("%ld",&p);
	while(p-->0)
	{
		scanf("%ld",&n);
		m=n;
		i=0;
		while(n%2==0)
		{
			i++;
			n/=2;
		}
		printf("%ld %ld\n",m+1-(long)pow(2,double(i)),m-1+(long)pow(2,double(i)));
	}
	return 0;
}