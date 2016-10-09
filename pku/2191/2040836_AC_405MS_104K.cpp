#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
#define MAX 64
unsigned __int64 c[7];
unsigned __int64 cc[25]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};

bool com(unsigned __int64 a,unsigned __int64 b)
{
	return a<b;
}


unsigned __int64 modular(unsigned __int64 a,unsigned __int64 b,unsigned __int64 n)
{
	unsigned __int64 d,x,c[MAX];
	d=1;
	x=1;
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

unsigned __int64 rho(unsigned __int64 n,unsigned __int64 x)
{
	unsigned __int64 t;
	if(n<=3203431780337)
	{
		n=unsigned __int64(n);
		if(prime(n))
		{
			c[x]=n;
			return x+1;
		}
	}
	if(n>3203431780337&&miller(n))
	{
		c[x]=n;	
		return x+1;
	}
	t=pollard(rand()%(n-1)+1,n);
	c[x]=t;
	return rho(n/t,x+1);
}

int main()
{
	unsigned __int64 n,nn,v,i,time=0;
	int p[18]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,100};
	scanf("%I64d",&nn);
	n=2048;
	while(p[time++]<=nn)
	{
		memset(c,0,sizeof(c));
		n=(unsigned __int64)pow(2,p[time-1]*1.0)-1;
		v=rho(n,0);		
		if(v==1)
			continue;
		else
		{
			sort(c,c+v,com);
			for(i=0;i<v;i++)
			{
				if(i)
					printf("* ");
				printf("%I64d ",c[i]);
			}
			printf("= %I64d = ( 2 ^ %d ) - 1\n",n,p[time-1]);
		}
	}
	return 0;
}
