#include<stdio.h>
#include <math.h>
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
	double m,minn;
	int a,b,x,y,mx,my;
	scanf("%d%d",&a,&b);
	m=a*1.0/b;
	minn=1.0;
	x=1;y=2;
	while(y<32768)
	{
		if(fabs(x*1.0/y-m)<minn&&gcd(x,y)==1)
		{
			my=y;
			mx=x;
			minn=fabs(x*1.0/y-m);
		}
		if(fabs((x+1)*1.0/y-m)>fabs(x*1.0/(y+1)-m))
			y++;
		else
			x++;
		if(x==a&&y==b)
			y++;
	}
	printf("%d %d\n",mx,my);		
	return 0;
}