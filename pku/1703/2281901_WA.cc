#include <iostream>
using namespace std;
#define MAX 100001


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
		c[i].a=i;
		c[i].b=50001+i;
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
	int p,q,x,y;
	char cc[2];
	while(m--)
	{
		scanf("%s",cc);
		scanf("%d%d",&p,&q);
		x=getroot(p);
		y=getroot(q);
		if(cc[0]=='D')
		{
			if(c[y].b>x)
				c[y].b=x;
			if(c[x].b>y)
				c[x].b=y;
			if(c[x].b<y)
			{
				c[y].a=c[x].b;
				c[y].b=x;
			}
			if(c[y].b<x)
			{
				c[x].a=c[y].b;
				c[x].b=y;
			}
		}
		if(cc[0]=='A')
		{
			if(x==y)
				printf("In the same gang.\n");
			else if(c[x].b==y&&c[y].b==x)
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