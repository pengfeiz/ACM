#include <stdio.h>
int main()
{
	long n,nn,i,tt;
	scanf("%ld",&nn);
	for(i=0;i<nn;i++)
    {
		scanf("%ld",&n);
		tt=0;
		while(n>0)
        {
			tt+=n/5;
			n/=5;
        }
		printf("%ld\n",tt);
	}
	return 0;
}
