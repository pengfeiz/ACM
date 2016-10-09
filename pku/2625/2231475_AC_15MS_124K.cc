#include <iostream>
using namespace std;

__int64 gcd(__int64 a,__int64 b)
{
	__int64 c;
	while(b)
	{
		c=a;
		a=b;
		b=c%b;
	}
	return a;
}

__int64 lcm(__int64 a,__int64 b)
{
	return a/gcd(a,b)*b;
}

__int64 length(__int64 a)
{
	__int64 i=0;
	while(a)
	{
		a/=10;
		i++;
	}
	return i;
}

int main()
{
	__int64 n,l,i,a,b,c,la,lc;
	while(scanf("%I64d",&n)!=EOF)
	{
		c=1;
		for(i=2;i<=n;i++)
			c=lcm(c,i);
		a=b=0;
		for(i=1;i<=n;i++)
		{
			b+=c/i;
			a+=b/c;
			b%=c;
		}
		a*=n;
		b*=n;
		a+=b/c;
		b%=c;
		l=gcd(b,c);
		b/=l;
		c/=l;
		la=length(a);
		if(b)
		{
			for(i=0;i<=la;i++)
				printf(" ");
			printf("%I64d\n",b);
		}
		printf("%I64d ",a);
		lc=length(c);
		if(b)
		{
			for(i=0;i<lc;i++)
				printf("-");
			printf("\n");
			for(i=0;i<=la;i++)
				printf(" ");
			printf("%I64d\n",c);
		}
		if(!b)
			printf("\n");
	}
	return 0;
}


