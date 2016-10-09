#include <iostream>
#include <algorithm>
using namespace std;


#define MAX 1000000
#define MAX2 200002


struct gao
{
	int a,b;
	__int64 n;
	__int64 m;
}c[MAX];


int n,a[MAX2],b[MAX2],d[MAX2];
__int64 t;

void build(int x,int a,int b)
{
	c[x].a=a;
	c[x].b=b;
	c[x].n=c[x].m=0;
	if(a!=b)
	{
		build(2*x,a,(a+b)/2);
		build(2*x+1,(a+b)/2+1,b);
	}
}


void dosth(int a,int x)
{
	c[x].n++;
	c[x].m+=a;
	if(c[x].a==c[x].b);
	else if(a>c[2*x].b)
		dosth(a,2*x+1);
	else
	{
		t+=c[2*x+1].n*a;
		t+=c[2*x+1].m;
		dosth(a,2*x);
	}
}


void solve()
{
	int i;
	for(i=1;i<=n;i++)
		dosth(a[i],1);
}


int main()
{
	int i;
	scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&b[i]);
			d[i]=b[i];
		}
		sort(d+1,d+n+1);
		build(1,1,n);
		for(i=1;i<=n;i++)
			a[i]=lower_bound(d+1,d+1+n,b[i])-d;
		t=0;
		solve();
		printf("%I64d\n",t);
	return 0;
}
