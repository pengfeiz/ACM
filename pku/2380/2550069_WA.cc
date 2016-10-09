#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 500001

struct gao
{
	int x,y,n;
}a[MAX];

int b[MAX],c[MAX];
bool cc[MAX];

bool com(gao a,gao b)
{return a.y!=b.y?a.y<b.y:a.x<b.x;}

int n,m,p;

int main()
{
	memset(cc,0,sizeof(cc));
	int i,j,q,w,s,t,nn;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].n);
		c[i]=a[i].y;
		b[i]=a[i].x;
	}
	m=p=0;
	sort(a,a+n,com);
	sort(b,b+n);
	sort(c,c+n);

	a[n].x=a[n].y=-999999999;
	nn=0;
	for(i=0;i<n;i++)
	{
		if(a[i].x!=a[i+1].x||a[i].y!=a[i+1].y)
		{
			a[nn].x=a[i].x;
			a[nn].y=a[i].y;
			a[nn].n=a[i].n;
			nn++;
		}
		else
			a[i+1].n+=a[i].n;
	}
	a[nn].x=a[nn].y=-999999999;

	b[n]=-999999999;
	for(i=0;i<n;i++)
		if(b[i]!=b[i+1])
			b[m++]=b[i];
	b[m]=-999999999;

	c[n]=-999999999;
	for(i=0;i<n;i++)
		if(c[i]!=c[i+1])
			c[p++]=c[i];
	c[p]=-999999999;

	printf("-1");
	for(i=0;i<m;i++)
		printf(" %d",b[i]);
	printf("\n");

	n=nn;
	w=s=t=0;
	for(i=0;i<n;i++)
	{
		if(!cc[w])
		{
			printf("%d",c[w]);
			cc[w]=true;
		}
		if(a[i].y!=c[w])
		{
			for(j=s;j<m;j++)
				printf(" 0");
			printf("\n");
			s=0;
			w++;
			i--;
			continue;
		}
		q=lower_bound(b,b+m,a[i].x)-b;
		for(j=s;j<q;j++)
			printf(" 0");
		printf(" %d",a[i].n);
		s=q+1;
		if(s>=m)
		{
			printf("\n");
			w++;
			s=0;
		}
	}
	return 0;
}
		