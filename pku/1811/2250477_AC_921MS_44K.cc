#include <stdio.h>
#include <stdlib.h>

unsigned __int64 n,ans;

unsigned __int64 mulmod(unsigned __int64 a,unsigned	__int64 b, unsigned __int64 n)
{
	unsigned __int64 t=0;
	while(b)
	{
		if(b&1)
			t=(t+a)%n;
		a=(a+a)%n;;
		b>>=1;
	}
	return t;
}

unsigned __int64 powermod(unsigned __int64 a,unsigned __int64 b,unsigned __int64 n)
{
	unsigned __int64 d;
	d=1;
	while(b&&(a>1))
	{
		if(b&1)
			d=mulmod(d,a,n);
		b=b>>1;
		a=mulmod(a,a,n);
	}
         if(a==0)
              return 0;
	return d;
}

bool rabin_miller(unsigned __int64 n)
{
	const unsigned int	rule[10]={2,3,5,7,11,13,17,19,23,29};
	unsigned __int64	x,b,last;
	int i,j,count;	
	count=0;
	b=n-1;
	while(!(b&1))
	{
		count++;
		b>>=1;
	}		
	for(i=0;i<10;i++)
	{
		if(rule[i]==n)
			return(true);
		x=powermod(rule[i],b,n);
		if(x==1)
			continue;		 
		for(j=1;j<=count;j++)
		{
			last=x;
			x=mulmod(last,last,n);
			if(x==1)
			{
				if(last!=n-1)
					return false;
				break;	
			}
		}
		if(x!=1)
			return false;
	}
	return true;
}

unsigned __int64 gcd(unsigned __int64 a,unsigned __int64 b)
{
	unsigned __int64 t;
	while(b)
	{
		t=a;
		a=b;
		b=t%b;
	}	
	return a;
}

unsigned __int64 rho(unsigned __int64 n)
{
	unsigned __int64 x,y,k,i,d,c;
	while(1)
	{	
		x=rand()%(n-2)+2;;
		y=x;
		c=rand()%n;
		i=0;
		d=k=1;
		while(d==1)
		{
			i++;
			x=(mulmod(x,x,n)+n-c)%n;
			if(x>y)
				d=gcd(x-y,n);
			else
				d=gcd(y-x,n);
			if((d!=1)&&(d!=n))
				return d;		
			if(i==k)
			{
				y=x;
				k<<=1;
			}		
		}
	}
	return d;
}

void dosth(unsigned __int64 n)
{
	unsigned __int64 t; 
	ans=n;
	while(n!=1)
	{
		t=n;
		while(!rabin_miller(t))
			t=rho(t);
		if(t<ans)
			ans=t;
		while(n%t==0)
			n/=t;
	}
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%I64u",&n);
		dosth(n);
		if(ans==n)
			printf("Prime\n");
		else
			printf("%I64u\n",ans);
	}
	return 0;
}
