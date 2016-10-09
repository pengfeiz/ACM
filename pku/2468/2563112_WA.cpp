#include <iostream>
#include <math.h>
using namespace std;

double w,h,l,t,bw,bh,bl;

int dosth(double bw,double bh,double bl)
{
	double a;
	if(bw>w||bh>h||bl>l)
		return 0;
	if(bh<=t)
		return 1;
	if(bl<=t)
	{
		a=asin(bl/t);
		if(hypot(bh,bl)<=h&&bh*sin(a)<=l)
			return 1;
	}
	if(hypot(bw,bh)<=h&&bw<=t)
	{
		a=atan(bw/bh)+acos(t/hypot(bw,bh));
		if(bw*cos(a)+bh*sin(a)<=h&&hypot(bw,bh)<=w) 
			return 1;
	}
	return 0;
}


int main()
{
	while(cin>>w>>h>>l>>t>>bw>>bh>>bl)
	{
		if(dosth(bw,bh,bl)||dosth(bw,bl,bh)||dosth(bh,bw,bl)||dosth(bh,bl,bw)||dosth(bl,bw,bh)||dosth(bl,bh,bw)) 
            printf("The box goes on the truck.\n");
		else
			printf("The box will not go on the truck.\n");
	}
	return 0;
}

