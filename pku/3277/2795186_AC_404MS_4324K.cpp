#include <iostream>
#include <algorithm>
using namespace std;


struct gao
{
	int l,r;
	int h;
}a[300001];

int n,m;

struct gao2
{
	int x,y,h;
}b[50001];

__int64 p[90001];


__int64 maxx(__int64 a,__int64 b)
{return a>b?a:b;}


void build(int x,int l,int r)
{
	a[x].h=0;
	a[x].l=l;
	a[x].r=r;
	if(l==r-1)
		return;
	build(2*x,l,(l+r)/2);
	build(2*x+1,(l+r)/2,r);
}


void dosth(int x,int l,int r,int h)
{
	if(a[x].l==l&&a[x].r==r)
	{
		if(h>a[x].h)
			a[x].h=h;
		return;
	}
	if(l>=(a[x].l+a[x].r)/2)
		dosth(2*x+1,l,r,h);
	else if(r<=(a[x].l+a[x].r)/2)
		dosth(2*x,l,r,h);
	else
	{
		dosth(2*x,l,(a[x].l+a[x].r)/2,h);
		dosth(2*x+1,(a[x].l+a[x].r)/2,r,h);
	}
}


int find(int x,int l,int r)
{
	if(a[x].l==l&&a[x].r==r)
		return a[x].h;
	if(l>=(a[x].l+a[x].r)/2)
		return maxx(find(2*x+1,l,r),a[x].h);
	else if(r<=(a[x].l+a[x].r)/2)
		return maxx(find(2*x,l,r),a[x].h);
}


int main()
{
	int i;
	__int64 tt;
	scanf("%d",&n);
	tt=0;
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d",&b[i].x,&b[i].y,&b[i].h);
		p[i*2]=b[i].x;
		p[i*2+1]=b[i].y;
	}
	m=0;

	sort(p,p+2*n);
	p[2*n]=-1;
	for(i=0;i<2*n;i++)
		if(p[i]!=p[i+1])
			p[m++]=p[i];

	for(i=0;i<n;i++)
	{
		b[i].x=lower_bound(p,p+m,b[i].x)-p;
		b[i].y=lower_bound(p,p+m,b[i].y)-p;
	}

	build(1,0,m-1);
	for(i=0;i<n;i++)
		dosth(1,b[i].x,b[i].y,b[i].h);

	for(i=0;i<m-1;i++)
		tt+=(__int64)(p[i+1]-p[i])*find(1,i,i+1);

	printf("%I64d\n",tt);

	return 0;
}