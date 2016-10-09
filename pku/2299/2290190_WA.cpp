#include <iostream>
#include <algorithm>
using namespace std;


#define MAX 1000002


struct gao
{
	int a,b,n;
}c[MAX];


int n,t,a[MAX],b[MAX],d[MAX];


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


void dosth(int a,int x)
{
	if(c[x].a==c[x].b)
		c[x].n++;
	else if(a>c[2*x].b)
	{
		dosth(a,2*x+1);
		c[x].n++;
	}
	else
	{
		t+=c[2*x+1].n;
		dosth(a,2*x);
		c[x].n++;
	}
}


void solve()
{
	int i;
	for(i=0;i<n;i++)
		dosth(a[i],1);
}


int main()
{
	int i;
	while(scanf("%d",&n),n)
	{
		for(i=0;i<n;i++)
		{
			scanf("%d",&b[i]);
			d[i]=b[i];
		}
		sort(d,d+n);
		build(1,1,n);
		for(i=0;i<n;i++)
			a[i]=lower_bound(d,d+n,b[i])-d+1;
		t=0;
		solve();
		printf("%d\n",t);
	}
	return 0;
}