#include<stdio.h>
const int M = 2000005;
int last[M];
void getlast()
{
	last[0]=1;
	int a,b,i;
	for(i=1;i<M;i++)
	{
		a=last[i-1];
		b=i;
		while(b%10==0)
			b/=10;
		while(b%5==0)
		{
			a>>=1;
			if(a&1)
				a+=5;
			b/=5;
		}
		last[i]=(a*b)%10;
	}
}
int l2(int v)
{
	int re=0;
	while(v)
	{
		v>>=1;
		re+=v;
	}
	return re;
}
int l5(int v)
{
	int re=0;
	while(v)
	{
		v/=5;
		re+=v;
	}
	return re;
}

int main()
{
	getlast();
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if( (m<<1)>n )m=n-m;
		if(m==0)
		{
			printf("1\n");
			continue;
		}
		if(m==1)
		{
			while(n%10==0)n/=10;
			printf("%d\n",n);
			continue;
		}
		int isodd = l2(n)-l5(n)-(l2(m)-l5(m)+l2(n-m)-l5(n-m));
		if(isodd<0)
		{
			printf("5\n");
			continue;
		}
		isodd=isodd?0:1;
		int i;\
		for(i=1;i<10;i++)
		{
			if( isodd^(i&1) )
				continue;
			if( (i*last[m])%10==last[n] )
				break;
		}
		printf("%d\n",i);
	}
	return 0;
}