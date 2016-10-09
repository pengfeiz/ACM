#include <iostream>
#include <math.h>
using namespace std;
#define esp 1e-5
int main()
{
	double v,h,u,d,f,hh;
	int i;
	while(scanf("%lf%lf%lf%lf",&h,&u,&d,&f),fabs(h)>esp||fabs(u)>esp||fabs(d)>esp||fabs(f)>esp)
	{
		f/=100.0;
		f*=u;
		v=u;
		hh=0;
		i=0;
		while(1)
		{
			i++;
			hh+=v;
			v-=f;
			if(hh>h+esp)
				break;			
			hh-=d;
			if(hh<-esp)
				break;
		}
		if(hh<-esp)
			printf("failure on day %d\n",i);
		else
			printf("success on day %d\n",i);
	}
	return 0;
}

