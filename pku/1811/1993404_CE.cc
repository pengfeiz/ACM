#include <iostream>
#include <math.h>
using namespace std;
#define MAX 64
__int64 modular(__int64 a,__int64 b,__int64 n)
{
	__int64 d,x,c[MAX];
	d=1;
	x=0;
	while(b>0)
	{
		c[x]=b%2;
		x++;
		b/=2;
	}
	while(x-->=0)
	{
		d=(d*d)%n;
		if(c[x]==1)
			d=(d*a)%n;
	}
	return d;
}
bool witness(__int64 a,__int64 n)
{
	__int64 u,x,t=0,xx,i;
	u=n-1;
	while(u%2==0)
	{
		u/=2;
		t++;
	}
	xx=modular(a,u,n);
	for(i=0;i<t;i++)
	{
		x=(xx*xx)%n;
		if(x==1&&xx!=1&&xx!=n-1)
			return true;
		xx=x;
	}
	if(x!=1)
		return true;
	return false;
}
bool miller(__int64 n)
{
	if(n==2)
		return true;
	if(n%2==0||n==1)
		return false;
	int i;
	__int64 x;
	for(i=0;i<100;i++)
	{
		x=rand()%(n-2)+1;
		if(witness(x,n))
			return false;
	}
	return true;
}
__int64 gcd(__int64 a,__int64 b)
{
	__int64 temp;
	if(a>b)
	{
		temp=a;
		a=b;
		b=temp;
	}
	while(a%b)
	{
		temp=a%b;
		a=b;
		b=temp;
	}
	return b;
}	
__int64 min(__int64 a,__int64 b)
{
	return a<b?a:b;
}
__int64 pollard(__int64 n)
{
	__int64 y,d=1,p,i,x;
	p=n;
	x=rand()%(n-1);
	y=x;
	for(i=0;i<100;i++)
	{
		x=(x*x-1)%n;
		d=gcd(abs(y-x),n);
		if(d==1||d==n)
			continue;
		d=min(pollard(d),pollard(n/d));
		return d;
	}
	return p;
}
int main()
{
	__int64 n,x,p,q,nn;
	scanf("%I64d",&nn);
	while(nn-->0)
	{
		scanf("%I64d",&n);
		if(miller(n))
			printf("Prime\n");
		else
		{
			x=99999999999;
			for(q=0;q<1000;q++)
			{
				p=pollard(n);
				if(x>p)
					x=p;
			}
			printf("%I64d\n",x);
		}
	}
	return 0;
}
