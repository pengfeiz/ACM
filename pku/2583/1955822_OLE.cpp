#include <stdio.h>
#include <iostream.h>
main()
{
	double a,b,c;
	while(scanf("%lf %lf %lf",&a,&b,&c))
		cout<<(c-2*b+a)/2*9+(4*b-3*a-c)/2*3+a<<" "<<(c-2*b+a)/2*16+(4*b-3*a-c)/2*4+a<<" "<<(c-2*b+a)/2*25+(4*b-3*a-c)/2*5+a<<endl;
	return 0;
}
