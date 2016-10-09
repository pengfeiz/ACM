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

__int64 pollard(__int64 m)
{
	__int64 d=1;
	__int64 fd,fm,y;
	int i,k;
	__int64 x=43;
	y=x;
	k=2;
	i=1;
	while(1)
	{
		__int64 diff;
		++i;
		x=(modular(x,x,m)+m-1)%m;
		diff=abs(x-y);
		d=gcd(diff,m);
		if(d!=1&&d!=m)
			break;
		else if(i==k)
		{
			y=x;
			k<<=1;
		}
	}
	m/=d;
	if(miller(d)==0)
		fd=pollard(d);
	else
		fd=d;
	if(miller(m) == 0)
		fm=pollard(m);
	else
		fm=m;
	return __int64(fd<fm?fd:fm);
}

__int64 factor(__int64 n)
{
	__int64	f=-1,i;
	for(i=2;i<10000;i++)
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
