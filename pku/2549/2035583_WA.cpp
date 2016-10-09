#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 500000
#define MAX2 1000
struct gao
{
	int a,b,c;
}a[MAX];
bool com(gao x,gao y)
{
	return x.c<y.c;
}
int main()
{
	int c[MAX2],i,j,n,m,t,ma;
	gao *q;
	q=(gao *)malloc(sizeof(gao));
	while(scanf("%d",&n)&&n)
	{
		m=0;
		ma=-536870913;
		for(i=0;i<n;i++)
			scanf("%d",&c[i]);
		for(i=0;i<n-1;i++)
			for(j=i+1;j<n;j++)
			{
				if(c[i]-c[j]>0)
				{
					a[m].a=c[i];
					a[m].b=c[j];
					a[m].c=c[i]-c[j];
				}
				else
				{
					a[m].a=c[j];
					a[m].b=c[i];
					a[m].c=c[j]-c[i];
				}
				m++;
			}
		sort(a,a+m,com);
		for(i=0;i<n-1;i++)
			for(j=i+1;j<n;j++)
			{				
				q->c=c[i]+c[j];
				if(q->c<0)
				{
					t=-q->c;
					q->c*=-1;
					q->a=-536870913;
					q=lower_bound(a,a+m,*q,com);
					if(q->a==-536870913)
						continue;
					while(q->c==t)
					{
						if(c[i]==q->a||c[i]==q->b||c[j]==q->a||c[j]==q->b)
							;
						else if(q->b>ma)
							ma=q->b;
						q++;
					}
				}
				else
				{
					t=q->c;
					q->a=-536870913;
					q=lower_bound(a,a+m,*q,com);
					if(q->a==-536870913)
						continue;
					while(q->c==t)
					{
						if(c[i]==q->a||c[i]==q->b||c[j]==q->a||c[j]==q->b)
							;
						else if(q->a>ma)
							ma=q->a;
						q++;
					}
				}
			}
		if(ma==-536870913)
			printf("no solution\n");
		else
			printf("%d\n",ma);
	}
	return 0;
}
				


							

	



