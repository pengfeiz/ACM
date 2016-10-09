#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 10003
#define MAX2 1000005

struct gao
{
	int n,l;
}c[MAX2];

int a[MAX],n,m,d[MAX2],q[MAX];

bool com(gao a,gao b)
{return a.l>b.l;}

int main()
{
	int i,x,t,ma,mm;
	while(scanf("%d",&n),n)
	{
		t=0;
		memset(d,0,sizeof(d));
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			d[a[i]]++;
		}
		m=0;
		for(i=0;i<MAX2;i++)
		{
			if(d[i])
			{
				c[m].l=d[i];
				c[m++].n=i;
			}
		}
		sort(c,c+m,com);
		x=c[0].l-n%c[0].l;
		printf("%d\n",c[0].l);
		ma=c[0].l;
		while(c[0].l)
		{
			if(x)
			{
				t=n/ma;
				x--;
			}
			else
				t=n/ma+1;
			sort(c+1,c+m,com);
			mm=0;
			q[mm++]=c[0].n;
			c[0].l--;
			t--;
			for(i=1;i<m&&t;i++)
			{
				if(c[i].l)
				{
					q[mm++]=c[i].n;
					c[i].l--;
					t--;
				}
			}
			sort(q,q+mm);
			printf("%d",q[0]);
			for(i=1;i<mm;i++)
				printf(" %d",q[i]);
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}


