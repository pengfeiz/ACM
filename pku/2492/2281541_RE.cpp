#include <iostream>
using namespace std;

#define MAX 6


struct gao
{
	int a,b;
}c[MAX];


int n,m;
bool t;


void build()
{
	int i;
	scanf("%d%d",&n,&m);
	for(i=0;i<=n;i++)
	{
		c[i].a=i;
		c[i].b=2001;
	}
}


int getroot(int x)
{
	int root;
	if(c[x].a==x)
		return x;
	root=getroot(c[x].a);
	c[x].a=root;
	c[x].b=c[root].b;
	return root;
}


void solve()
{
	int p,q;
	int x,y;
	t=false;
	while(m--)
	{
		scanf("%d%d",&p,&q);
		if(!t)
		{
			x=getroot(p);
			y=getroot(q);
			if(x==y)
				t=true;
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
			if(c[x].b>y)
				c[x].b=y;
			if(c[y].b>x)
				c[y].b=x;
			if(x==y)
				t=true;
		}
	}
	if(t)
		printf("Suspicious bugs found!\n\n");
	else
		printf("No suspicious bugs found!\n\n");
}


int main()
{
//	freopen("in.txt","r",stdin);
	int i,k;
	scanf("%d",&k);
	for(i=1;i<=k;i++)
	{
		printf("Scenario #%d:\n",i);
		build();
		solve();
	}
	return 0;
}