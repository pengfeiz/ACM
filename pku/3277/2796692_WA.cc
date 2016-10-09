#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 100001 

struct gao
{
	int x,y,h,w;
}a[MAX],p,b[MAX],aa[MAX];

int n,m,mm,t;

bool com1(gao a,gao b)
{
	if(a.y!=b.y)
		return a.y<b.y;
	return a.h>b.h;
}
bool com2(gao a,gao b)
{
	if(a.x!=b.x)
		return a.x<b.x;
	return a.h>b.h;
}
bool com3(gao a,gao b)
{return a.x<b.x;}


int main()
{
	int i,l1,l2;
	m=mm=t=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].h);
		aa[i].x=a[i].x;
		aa[i].y=a[i].y;
		aa[i].h=a[i].h;
		b[mm++].x=a[i].x;
		b[mm++].x=a[i].y;
	}
	sort(b,b+mm,com3);
	b[mm].x=-1;
	for(i=0;i<mm;i++)
		if(b[i].x!=b[i+1].x)
		{
			b[m].h=0;
			b[m].y=b[i].x;
			b[m++].x=b[i].x;
			b[m].w=m;
		}
	b[m].h=-1;
	b[m].y=-1;
	sort(a,a+n,com2);
	sort(aa,aa+n,com1);
	for(i=0;i<n;i++)
	{
		l1=lower_bound(a,a+m,a[i],com2)-a;
		l2=lower_bound(aa,aa+m,aa[i],com1)-aa;
		if(a[l1].x==b[i].x)
		{
			b[i].h=a[l1].h;
			b[i].w=l1;
		}
		else if(aa[l2].y<a[b[i-1].w].y)
		{
			b[i].h=b[i-1].h;
			b[i].w=b[i-1].w;
		}
		else
			b[i].h=0;
	}
	for(i=0;i<m-1;i++)
		t+=(b[i+1].x-b[i].x)*b[i].h;
	printf("%d\n",t);
	return 0;
}

