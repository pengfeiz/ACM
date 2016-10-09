#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
#define MAX 64
unsigned __int64 c[50];
unsigned __int64 cc[25]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};

bool com(unsigned __int64 a,unsigned __int64 b)
{
	return a<b;
}


unsigned __int64 modular(unsigned __int64 a,unsigned __int64 b,unsigned __int64 n)
{
	unsigned __int64 d,x,c[MAX];
	d=x=1;
	memset(c,0,sizeof(c));
	while(b>0)
	{
		c[x]=b%2;
		x++;
		b/=2;
	}
	while(x>1)
	{
		x--;
		d=(d*d)%n;			
		if(c[x]==1)
			d=(d*a)%n;
	}
	return d;
}
bool witness(unsigned __int64 a,unsigned __int64 n)
{
	unsigned __int64 u,x,t=0,xx,i;
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
bool miller(unsigned __int64 n)
{
	if(n==2)
		return true;
	if(n%2==0||n==1)
		return false;
	int i;
	unsigned __int64 x;
	for(i=0;i<25;i++)
	{
		x=cc[i];
		if(witness(x,n))
			return false;
	}
	return true;
}

bool prime(__int64 n)
{
	unsigned __int64 i;
	for(i=2;i<=(unsigned __int64)sqrt(n*1.0);i++)
		if(n%i==0)
			return false;
	return true;
}

unsigned __int64 gcd(unsigned __int64 a,unsigned __int64 b)
{
	unsigned __int64 temp;
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

unsigned __int64 min(unsigned __int64 a,unsigned __int64 b)
{
	return a<b?a:b;
}

unsigned __int64 pollard(unsigned __int64 c,unsigned __int64 n)
{
	unsigned __int64 i,x,y,k,d;
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

unsigned __int64 rho(unsigned __int64 n)
{
	unsigned __int64 t,q;
	if(n<=8589934592&&prime(n))
		return n;
	if(n>8589934592&&miller(n))	
		return n;
	while(t=pollard(rand()%(n-1)+1,n))
		if(t!=1)
			break;
	q=rho(n/t);
	t=rho(t);
	if(q<t&&q!=1)
		return q;
	return t;
}

int main()
{
	unsigned __int64 n,nn,v,time=0;
	scanf("%I64d",&nn);
	while(nn-->0)
	{
		scanf("%I64d",&n);
//		n=nn;
		v=rho(n);		
		if(v==n)
			printf("Prime\n");
		else
			printf("%d\n",v);
	}
	return 0;
}
