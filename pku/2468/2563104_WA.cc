#include <iostream>
#include <math.h>
using namespace std;

double w,h,l,t,bw,bh,bl;

int dosth(double bw,double bh,double bl)
{
	double a,h1,w1,l1;
	if(bw>w||bh>h||bl>l)
		return 0;
	if(bh<=t)
		return 1;
	if(bl<=t)
	{
		a=asin(bl/t);
		h1=hypot(bh,bl);
		l1=bh*sin(a);
		if(h1<=h&&l1<=l)
			return 1;
	}
	if(hypot(bw,bh)<=h&&bw<=t)
	{
		a=atan(bw/bh)+acos(t/hypot(bw,bh));
		w1=bw*cos(a)+bh*sin(a);
		h1=hypot(bw,bh);
		if(h1<=h&&w1<=w) 
			return 1;
	}
	return 0;
}


int main()
{
	while(scanf("%lf%lf%lf%lf",&w,&h,&l,&t)!=EOF)
	{
		scanf("%lf%lf%lf",&bw,&bh,&bl);
		if(dosth(bw,bh,bl)||dosth(bw,bl,bh)||dosth(bh,bw,bl)||dosth(bh,bl,bw)||dosth(bl,bw,bh)||dosth(bl,bh,bw)) 
            printf("The box goes on the truck.\n");
		else
			printf("The box will not go on the truck.\n");
	}
	return 0;
}

