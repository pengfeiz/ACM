#include <iostream>
using namespace std;

#define MAX 200000


struct gao
{
	int a,b,n;
}c[MAX];


int n,m,tim,t,a[MAX];


void build(int x,int a,int b)
{
	c[x].a=a;
	c[x].b=b;
	c[x].n=0;
	if(a!=b)
	{
		build(2*x,a,(a+b)/2);
		build(2*x+1,(a+b)/2+1,b);
	}
}


void dosth(int p,int x)
{
	if(c[x].a==c[x].b)
	{
		t+=c[x].n;
		c[x].n++;
	}
	else if(p>(c[x].a+c[x].b)/2)
	{
		dosth(p,2*x+1);
		c[x].n++;
	}
	else
	{
		t+=c[2*x+1].n;
		dosth(p,2*x);
		c[x].n++;
	}
}


void solve()
{
	int i,p,q;
	t=0;
	scanf("%d%d",&n,&m);
	build(1,1,m+n);
	for(i=0;i<m+n;i++)
	{
		scanf("%d%d",&p,&q);
		a[p]=q;
	}
	for(i=1;i<=m+n;i++)
		dosth(a[i],1);
	printf("Scenario #%d:\n%d\n\n",tim,t);
}


int main()
{
	int k;
	tim=0;
	scanf("%d",&k);
	while(k--)
	{
		tim++;
		solve();
	}
	return 0;
}