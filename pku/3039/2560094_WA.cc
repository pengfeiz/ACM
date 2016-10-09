#include <iostream>
#include <math.h>
using namespace std;
int gcd(int a,int b)
{
	int c;
	while(b)
	{
		c=b;
		b=a%b;
		a=c;
	}
	return a;
}

int main()
{
	double a,b,m,xx,yy,minn;
	int x,y,my,mx;
	scanf("%lf%lf",&a,&b);
	m=b/a;
	minn=9999999;
	for(x=1;x<32768;x++)
	{	
		if(x==a)
			continue;
		y=x*m;
		if(y>32767)
			break;
		if(gcd(x,y)==1)
		{
			yy=y;
			xx=x;
			if(fabs(yy/xx-m)<minn)
			{
				minn=fabs(yy/xx-m);
				my=y;
				mx=x;
			}
		}
		y++;
		if(gcd(x,y)==1)
		{
			yy=y;
			xx=x;
			if(fabs(yy/xx-m)<minn)
			{
				minn=fabs(yy/xx-m);
				my=y;
				mx=x;
			}
		}
	}
	printf("%d %d\n",mx,my);		
	return 0;
}