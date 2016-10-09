#include <iostream>
#include <math.h>
using namespace std;
#define esp 1e-13


char s[105];
char *p;

double addsub(double x);

double read(double x)
{
	double y=0,i=1.0;
	while(*p<='9'&&*p>='0')
	{
		y=y*10+*p-'0';
		p++;
	}
	if(*p=='x')
	{
		p++;
		return x;
	}
	if(*p=='(')
	{
		p++;
		y=addsub(x);
		p++;
	}
	return y;
}

double mul(double x)
{
	double y;
	y=read(x);
	if(*p=='*')
	{
		p++;
		y*=mul(x);
	}
	return y;
}

double addsub(double x)
{
	double y;
	y=mul(x);
	if(*p=='-'||*p=='+')
	{
		p++;
		if(*(p-1)=='+')
			y+=addsub(x);
		else
			y-=addsub(x);
	}
	return y;
}

double dosth(double x)
{
	double a,b;
	p=s;
	a=addsub(x);
	p++;
	b=addsub(x);
	return a-b;
}

int main()
{
	int tim=0;
	double a1,b1,mid,a2,b2,mm;
	while(scanf("%s",s)!=EOF)
	{
		tim++;
		printf("Equation #%d\n",tim);
		a1=-9999999999.0;
		b1=9999999999.0;
		a2=dosth(a1);
		b2=dosth(b1);
		if(a2*b2>esp)
			printf("No solution.\n");
		else if(fabs(a2-b2)<esp)
			printf("Infinitely many solutions.\n");
		else
		{
			while(b1-a1>1e-7)
			{
				a2=dosth(a1);
				b2=dosth(b1);
				mid=(a1+b1)/2;
				mm=dosth(mid);
				if(a2*mm>esp)
					a1=mid;
				else
					b1=mid;
			}
			if(fabs(a1)<1e-6&&a1<=0)
				printf("x = 0.000000\n");
			else
				printf("x = %.6lf\n",a1);
		}
		printf("\n");
	}
	return 0;
}