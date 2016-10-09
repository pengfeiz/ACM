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
	if(miller(n))
		return n;
	__int64 y,d=n,p,x,a,i,k;
	p=n;
	do
	{
		a=rand()%(n-2);
	}while(a==0||a==-2);
	y=x=43;
	i=1;
	k=2;
	while(1)
	{
		i++;
		x=(x*x+a)%n;
		d=gcd(abs(y-x),n);
		if(d!=1&&d!=n)
			return min(pollard(d),pollard(n/d));
		else if(i==k)
		{
			y=x;
			k*=2;
		}
	}
	return d;
}

__int64 factor(__int64 n)
{
	__int64	f=-1,i;
	for(i=2;i<1000000;i++)
		if(n%i==0)
			return i;
	return pollard(n);
}

int main()
{
	__int64 n,nn;
	scanf("%I64d",&nn);
	while(nn-->0)
	{
		scanf("%I64d",&n);
		if(miller(n))
			printf("Prime\n");
		else
			printf("%I64d\n",factor(n));
	}
	return 0;
}
