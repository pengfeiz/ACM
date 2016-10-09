#include <iostream>
#include <stdlib.h>
using namespace std;
#define MAX 40001

struct gao
{
	int to,l;
	struct gao *next;
}*a[MAX];

int len,v,n,m,t;
bool b[MAX];

void bfs(int x)
{
	struct gao *p;
	int c[MAX][2],d[MAX][2],i;
	b[x]=true;
	c[0][0]=1;
	c[1][0]=x;
	c[1][1]=0;
	t=1;
	while(t<n)
	{
		d[0][0]=0;
		for(i=1;i<=c[0][0];i++)
		{
			b[c[i][0]]=true;
			p=a[c[i][0]];
			while(p)
			{
				if(!b[p->to])
				{
					t++;
					d[0][0]++;
					d[d[0][0]][0]=p->to;
					d[d[0][0]][1]=p->l+c[i][1];
					if(d[d[0][0]][1]>len)
					{
						v=p->to;
						len=d[d[0][0]][1];
					}
				}
				p=p->next;
			}
		}
		for(i=1;i<=d[0][0];i++)
		{
			c[i][0]=d[i][0];
			c[i][1]=d[i][1];
		}
		c[0][0]=d[0][0];
	}
}

int main()
{
	int i,from,to,l;
	char c;
	scanf("%d%d",&n,&m);
	len=0;
	gao *p;
	for(i=0;i<=n;i++)
	{
		b[i]=false;
		a[i]=NULL;
	}
	while(m--)
	{
		scanf("%d%d%d",&from,&to,&l);
		getchar();
		scanf("%c",&c);
		p=(struct gao *)malloc(sizeof(struct gao));
		p->to=to;
		p->l=l;
	         p->next=a[from];
		a[from]=p;
		p=(struct gao *)malloc(sizeof(struct gao));
		p->to=from;
		p->l=l;
		p->next=a[to];
		a[to]=p;

	}
	bfs(1);
	for(i=0;i<=n;i++)
		b[i]=false;
	bfs(v);
	printf("%d\n",len);
	return 0;
} 
