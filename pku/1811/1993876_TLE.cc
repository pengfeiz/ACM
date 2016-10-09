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

__int64 pollard(__int64 c,__int64 n)
{
	__int64 i,x,y,k,d;
	i=1;
	x=rand()%n;
	y=x;
	k=2;
	do
	{
		i++;
		d=gcd(2*n+y-x,n);
		if(d>1&&d<n)
			return d;
		else if(i==k)
		{
			y=x;
			k*=2;
		}
		x=(x*x+1)%n;
	}while(y!=x);
	return n;
}

__int64 rho(__int64 n)
{
	__int64 t;
	if(miller(n))
		return n;
	do
	{
		t=pollard(rand()%(n-1)+1,n);
		if(t<n)
		{
			__int64 a,b;
			a=rho(t);
			b=rho(n/t);
			return min(a,b);
		}
	}while(1);
}

int main()
{
	__int64 n,nn,v;
	scanf("%I64d",&nn);
	while(nn-->0)
	{
		scanf("%I64d",&n);
		v=rho(n);
		if(v==n)
			printf("Prime\n");
		else
			printf("%I64d\n",v);
	}
	return 0;
}