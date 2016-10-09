#include<cstdio>
#include<cmath>
#include<algorithm>

const int maxbase=31622;


struct	qnode
{
	int		a,q;
	friend	bool operator<(qnode a,qnode b)
	{
if (a.a!=b.a)return(a.a<b.a);
return(a.q<b.q);
	}

};

int		base;
int		x,z,k;
__int64	y,ybase;

qnode	q[maxbase];
int		qtail;

qnode	tq[maxbase];
int		ttail;

__int64		powermod(__int64	a,__int64	b,__int64	n)
{
	int	d;
	
	d=1;
	while ((b>0)&&(a!=1))
	{
		if (b&1) d=(d*a)%n;
		b=b>>1;
		a=(a*a)%n;
	}
	return (d);
}

void	init()
{
	int		i,limit;
	__int64	t;
	
	scanf("%d %d %d\n",&x,&z,&k);
	if (x+z+k==0)
		exit(0);	
	
	base=(int)sqrt(z)+1;
	limit=base;
	limit<?=z;
	ybase=powermod(x,base,z);
	
	t=1;
	ttail=0;
	for (i=0;i<limit;i++)
	{
		ttail++;
		tq[ttail].a=t;
		tq[ttail].q=i;
		t=(t*x)%z;
	}
	
	std::sort(tq+1,tq+ttail+1);
	
	qtail=0;
	q[0].a=-1;
	q[0].q=-1;
	for (i=1;i<=ttail;i++)
		if (tq[i].a!=q[qtail].a)
		{			
			qtail++;			
			q[qtail]=tq[i];
		}
}

int		find(int	x)
{
	int	l,r,m;
	
	l=1;
	r=qtail;
	while (l<r)
	{
		m=(l+r)>>1;
		if (q[m].a<x)
			l=m+1;
		else	if (q[m].a==x)
					return(q[m].q);				
		else
			r=m-1;
			
	}
	if (q[l].a==x)
		return(q[l].q);
	else
		return(-1);
}



void	extendgcd(__int64	a,__int64	b,__int64	&x,__int64	&y,__int64	&d)
{
	__int64	tx,ty;
	
	if (b==0)
	{
		x=1;
		y=0;
		d=a;
		return;
	}
	
	extendgcd(b,a%b,tx,ty,d);	
	x=ty;
	y=tx-(a/b)*ty;
}

bool	equation(__int64	a,__int64	b,__int64	n,__int64	&x,__int64	&y,__int64	&d)
{
	extendgcd(a,b,x,y,d);
	if (n%d!=0)	
		return(false);
	
	x*=n/d;
	y*=n/d;
	return(true);
}

bool	starmain()
{
	__int64		i,a,tx,ty,d,t;	
	
	a=1;
	for (y=0;y<z;y+=base)
	{		
		if (equation(a,z,k,tx,ty,d))
		{
			tx=(tx%z+z)%z;
			
			for (i=1;i<=d;i++)
			{				
				if ((t=find(tx))>=0)
				{
					y+=t;
					return(true);
				}
				tx+=z/d;
				if (tx>=z)
					tx-=z;
			}		
		}
		a=(a*ybase)%z;		
	}	
	
	return(false);
}

int main()
{
	while(1)
	{
		init();
		if (starmain())
			printf("%I64d\n",y);
		else
			printf("No Solution\n");
	}
	
	return(0);
}
