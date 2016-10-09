#include"stdio.h"
main()
{
	long a,b,c;
	while(scanf("%ld %ld %ld",&a,&b,&c))
		printf("%ld %ld %ld\n",a-3*b+3*c,3*a-8*b+6*c,6*a-15*b+10*c);
	return 0;
}
