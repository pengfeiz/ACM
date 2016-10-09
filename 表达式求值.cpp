#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define MAX 128
#define esp 1e-10

char *s,c[MAX];

double read(double x);
double sincos(double x);
double muldiv(double x);
double addsub(double x);
double dosth(double x);

double read(double x)
{
	double y=0,i=1.0;
	while(*s<='9'&&*s>='0')
	{
		y=y*10+*s-'0';
		s++;
	}
	if(*s=='.')
	{
		s++;
		while(*s<='9'&&*s>='0')
		{
			i*=10.0;
			y+=(*s-'0')*1.0/i;
			s++;
		}
		return y;
	}
	if(*s=='X')
	{
		s++;
		return x;
	}
	if(*s=='(')
	{
		s++;
		y=addsub(x);
		s++;
	}
	return y;
}

double sincos(double x)
{
	double y;
	if(*s=='s')
	{
		s+=3;
		y=sin(read(x));
	}
	else if(*s=='c')
	{
		s+=3;
		y=cos(read(x));
	}
	else
		y=read(x);
	return y;
}

double muldiv(double x)
{
	double y;
	y=sincos(x);
	if(*s=='*')
	{
		s++;
		y*=muldiv(x);
	}
	return y;
}

double addsub(double x)
{
	double y=0;
	int b=0;
	if(*(s-1)=='-')
		b=1;
	y=muldiv(x);
	if(*s=='-'||*s=='+')
	{
		s++;
		if(!b)
		{			
			if(*(s-1)=='-')
				y-=addsub(x);
			else 
				y+=addsub(x);
		}
		if(b)
		{			
			if(*(s-1)=='-')
				y+=addsub(x);
			else 
				y-=addsub(x);
		}
	}
	return y;
}

double dosth(double x)
{
	double l,r;
	s=c;
	l=addsub(x);
	s++;
	r=addsub(x);
	return l-r;
}

int main()
{
	freopen("in.txt","r",stdin);

	while(scanf("%s",c)!=EOF)
	{
		double first,last,mid,h,l,m;
		first=1.0;
		last=-1.0;
		while(first-last>esp)
		{			
			h=dosth(first);
			l=dosth(last);
			if(h*l>0)
			{
				printf("No solution!\n");
				break;
			}
			mid=(first+last)/2;
			m=dosth(mid);
			if(h*m>0)
				first=mid;
			else 
				last=mid;
		}
		if(first-last<=esp)
			printf("X=%.8lf\n",first);
		
	}
	
	return 0;
}

