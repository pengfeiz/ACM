#include <iostream>
#include <math.h>
using namespace std;

double d,t,h,e,hh;
char c[3];

int main()
{
	while(scanf("%s",&c),c[0]!='E')
	{
		t=d=h=-99999;
		if(c[0]=='T')
			scanf("%lf",&t);
		else if(c[0]=='H')
			scanf("%lf",&h);
		else if(c[0]=='D')
			scanf("%lf",&d);
		scanf("%s",&c);
		if(c[0]=='T')
			scanf("%lf",&t);
		else if(c[0]=='H')
			scanf("%lf",&h);
		else if(c[0]=='D')
			scanf("%lf",&d);
		if(t==-99999)
		{
			e=6.11*exp(5417.7530*((1.0/273.16)-(1.0/(d+273.16))));
			hh=(0.5555)*(e-10.0);
			t=h-hh;
		}
		else if(h==-99999)
		{
			e=6.11*exp(5417.7530*((1.0/273.16)-(1.0/(d+273.16))));
			hh=(0.5555)*(e-10.0);
			h=t+hh;
		}
		else
		{
			hh=h-t;
			e=hh/0.5555+10;
			e/=6.11;
			e=log(e);
			e/=5417.7530;
			e=-e;
			e+=1.0/273.16;
			d=1/e-273.16;
		}
		printf("T %.1lf D %.1lf H %.1lf\n",t,d,h);
	}
	return 0;
}




