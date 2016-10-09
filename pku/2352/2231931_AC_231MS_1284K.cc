#include <iostream>
using namespace std;
#define MAX 100000

struct gao
{
	int a,b,n;
}c[MAX];

int d[MAX],t;

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
		d[t]++;
	}
	else if(c[2*x+1].a<=p)
	{
		t+=c[x].n;
		dosth(p,2*x+1);
	}
	else
	{
		c[x].n++;
		dosth(p,2*x);
	}
}

int main()
{
	int n,i,p;
	scanf("%d",&n);
	memset(d,0,sizeof(d));
	build(1,0,32000);
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&p,&t);
		t=0;
		dosth(p,1);
	}
	for(i=0;i<n;i++)
		printf("%d\n",d[i]);
	return 0;
}

