#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 100001 


struct gao
{
	__int64 x,y,h;
}a[MAX],p,b[MAX];

__int64 n,m,mm,t;


bool com2(gao a,gao b)
{
	if(a.x!=b.x)
		return a.x<b.x;
	return a.y>b.y;
}
bool com3(gao a,gao b)
{return a.x<b.x;}


int main()
{
	__int64 i,j;
	m=mm=t=0;
	scanf("%I64d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%I64d%I64d%I64d",&a[i].x,&a[i].y,&a[i].h);
		b[mm++].x=a[i].x;
		b[mm++].x=a[i].y;
	}
	sort(b,b+mm,com3);
	b[mm].x=-1;
	for(i=0;i<mm;i++)
		if(b[i].x!=b[i+1].x)
		{
			b[m].h=0;
			b[m++].x=b[i].x;
		}
	sort(a,a+n,com2);
	for(i=0;i<m;i++)
	{
		j=lower_bound(a,a+n,b[i],com3)-a;
		while(j>=0)
		{
			if(b[j].x>a[i].y)
				break;
			if(b[j].h<a[i].h)
				b[j].h=a[i].h;
			j--;
		}
	}
	for(i=0;i<m-1;i++)
		t+=(b[i+1].x-b[i].x)*b[i].h;
	printf("%I64d\n",t);
	return 0;
}

