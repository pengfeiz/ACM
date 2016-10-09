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
	m=b*1.0/a;
	minn=32768.0;
	x=1;y=1;
	while(y<32768&&x<32768)
	{
		if(fabs(y*1.0/x-m)<minn&&gcd(x,y)==1&&!(x==a&&y==b))
		{
			my=y;
			mx=x;
			minn=fabs(y*1.0/x-m);
		}
		if(fabs((y+1)*1.0/x-m)>fabs(y*1.0/(x+1)-m))
			x++;
		else
			y++;
	}
	printf("%d %d\n",mx,my);		
	return 0;
}