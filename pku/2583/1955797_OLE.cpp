#include <stdio.h>
#include <iostream.h>
main()
{
	double a,b,c;
	while(scanf("%lf %lf %lf",&a,&b,&c))
		cout<<a-3*b+3*c<<" "<<3*a-8*b+6*c<<" "<<6*a-15*b+10*c<<endl;
	return 0;
}
