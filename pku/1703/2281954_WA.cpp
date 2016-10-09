#include <iostream>
using namespace std;
#define MAX 200002


int n,m;


struct gao
{
	int a,b;
}c[MAX];


void build()
{
	int i;
	scanf("%d%d",&n,&m);
	for(i=0;i<=n;i++)
	{
		c[i].a=c[i+100001].a=i;
		c[i].b=c[i+100001].b=100001+i;
	}
}


int getroot(int x)
{
	int root;
	if(c[x].a==x)
		return x;
	root=getroot(c[x].a);
	c[x].b=c[root].b;
	c[x].a=root;
	return root;
}


void solve()
{
	int p,q,x,y,xx,yy;
	char cc[2];
	while(m--)
	{
		scanf("%s",cc);
		scanf("%d%d",&p,&q);
		x=getroot(p);
		y=getroot(q);
		if(cc[0]=='D')
		{
			if(c[x].b<y)
			{
				c[y].a=c[x].b;
				y=c[y].a;
			}
			if(c[y].b<x)
			{
				c[x].a=c[y].b;
				x=c[x].a;
			}
			if(c[y].b>x)
				c[y].b=x;
			if(c[x].b>y)
				c[x].b=y;
		}
		if(cc[0]=='A')
		{
			xx=getroot(c[x].b);
			yy=getroot(c[y].b);
			if(xx==yy)
			{
				if(y<c[x].a)
					c[x].a=y;
				if(x<c[y].a)
					c[y].a=x;
				printf("In the same gang.\n");
			}
			else if(c[x].b==y||c[y].b==x)
				printf("In different gangs\n");
			else
				printf("Not sure yet.\n");
		}
	}
}


int main()
{
	int k;
	scanf("%d",&k);
	while(k--)
	{
		build();
		solve();
	}
	return 0;
}