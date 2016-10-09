#include <iostream>
using namespace std;

#define MAX 1002
#define MAX2 10002

struct gao
{
	int x,y,l;
}a[MAX2],b[MAX2];

int d[MAX],n,ma,mb;

int solve()
{
	int i,x,y,t=0,l;
	bool f;
	do{
		t++;
		f=false;
		for(i=0;i<ma;i++)
		{
			x=a[i].x;
			y=a[i].y;
			l=a[i].l;
			if(d[y]<d[x])
			{
				d[x]=d[y];
				f=true;
			}
			if(d[y]>d[x]+l)
			{
				d[y]=d[x]+l;
				f=true;
			}
		}
		for(i=0;i<mb;i++)
		{
			x=b[i].x;
			y=b[i].y;
			l=b[i].l;
			if(d[y]<d[x])
			{
				d[x]=d[y];
				f=true;
			}
			if(d[x]+l>d[y])
			{
				d[x]=d[y]-l;
				f=true;
			}
		}
		for(i=1;i<n;i++)
			if(d[i]>d[i+1])
			{
				d[i]=d[i+1];
				f=true;
			}
	}while(f&&t<n+5);
	if(t==n+5)
	{
		if(d[n]==n*1000000)
			return -2;
		return -1;
	}
	return d[n]-d[1];
}

int main()
{
	int i;
	scanf("%d%d%d",&n,&ma,&mb);
	for(i=1;i<=n;i++)
		d[i]=i*1000000;
	for(i=0;i<ma;i++)
	{
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].l);
		if(a[i].x>a[i].y)
			swap(a[i].x,a[i].y);
	}
	for(i=0;i<mb;i++)
	{
		scanf("%d%d%d",&b[i].x,&b[i].y,&b[i].l);
		if(b[i].x>b[i].y)
			swap(b[i].x,b[i].y);
	}
	printf("%d\n",solve());
	return 0;
}