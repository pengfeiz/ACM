#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 102

struct gao
{
	__int64 x,y;
}a[MAX];

__int64 n,cc[MAX];

bool com(__int64 a,__int64 b)
{return a<b;}

int main()
{
	__int64 i,q,s,j;
	gao h,b,c;
	while(scanf("%I64d%I64d%I64d",&n,&a[0].x,&a[0].y),n||a[0].x||a[0].y)
	{
		for(i=0;i<n;i++)
		{
			scanf("%I64d%I64d",&q,&s);
			q--;
			h.x=a[q].x;
			h.y=a[q].y;
			s=s%(h.x+h.y);
			for(j=q;j<i;j++)
			{
				a[j].x=a[j+1].x;
				a[j].y=a[j+1].y;
			}
			if(s<h.x)
			{
				b.x=h.x-s;
				c.x=s;
				b.y=c.y=h.y;
			}
			else
			{
				s-=h.x;
				b.x=c.x=h.x;
				b.y=h.y-s;
				c.y=s;
			}
			if(b.x*b.y>c.x*c.y)
			{
				swap(b.x,c.x);
				swap(b.y,c.y);
			}
			a[i].x=b.x;
			a[i].y=b.y;
			a[i+1].x=c.x;
			a[i+1].y=c.y;
		}
		for(i=0;i<=n;i++)
			cc[i]=a[i].x*a[i].y;
		sort(cc,cc+1+n,com);
		printf("%I64d",cc[0]);
		for(i=1;i<=n;i++)
			printf(" %I64d",cc[i]);
		printf("\n");
	}
	return 0;
}



