#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>

int	x,y,z,k,base;
std::vector<std::pair<int,int> >	q;

void init()
{
	int	i;
	__int64	t;	
	scanf("%d%d%d",&x,&z,&k);
	if(!x&&!z&&!k)
		exit(0);
	base=(int)sqrt(z*1.0)+1;
	q.clear();	
	t=1;
	base=base<z?base:z;
	for(i=0;i<base;i++)
	{	
		q.push_back(std::make_pair(t,i));
		t=(__int64)(t*x)%z;	
	}	
	std::sort(q.begin(),q.end());
}

__int64	mod_exp(__int64	a,__int64 b,__int64	n)
{
	__int64	d=1;
	while(b&&a!=1)
	{
		if(b&1)
			d=(d*a)%n;
		b=b>>1;
		a=(a*a)%n;
	}
	return d;
}

void ext_gcd(__int64 a,__int64 b,__int64 &x,__int64	&y,__int64 &d)
{
	__int64	tx,ty;	
	if(!b)
	{
		x=1;
		y=0;
		d=a;
		return;
	}	
	ext_gcd(b,a%b,tx,ty,d);	
	x=ty;
	y=tx-(a/b)*ty;
}

int	find(int p)
{
	std::vector<std::pair<int,int> >::iterator	t;		
	t=std::lower_bound(q.begin(),q.end(),std::make_pair(p,-1));
	if((t==q.end())||((*t).first!=p))
		return base;
	else
		return (*t).second;
}

bool starmain()
{
	__int64	a,ty,tx,d,tt,t;	
	for(y=0;y<z;y+=base)
	{
		a=mod_exp(x,y,z);
		ext_gcd(a,z,tx,ty,d);		
		if(k%d==0)
		{
			tt=z/d;
			tx=((tx*k/d)%tt+tt)%tt;				
			if((t=find(tx))<base)
			{
				y+=t;
				return true;
			}	
		}
	}	
	return false;
}


int	main()
{
	while(1)
	{			
		init();
		if(starmain())
			printf("%d\n",y);
		else
			printf("No Solution\n");
	}	
	return 0;
}