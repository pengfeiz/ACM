#include <iostream>
#include <stdlib.h>
using namespace std;

#define MAX 40001
 
struct gao
{
	int to,l;
	struct gao *next;
}*a[MAX];

struct yanzi
{
	int d,father,l;
}b[MAX];

int n,m,k;
bool d[MAX];

void build()
{
	int i,from,to,l;
	char c;
	gao *p;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
	{
		d[i]=false;
		a[i]=NULL;
	}
	for(i=0;i<m;i++)
	{
		scanf("%d%d%d",&from,&to,&l);
		getchar();
		scanf("%c",&c);
		p=(struct gao*)malloc(sizeof(struct gao));
		p->to=to;
		p->l=l;
		p->next=a[from];
		a[from]=p;
		p=(struct gao*)malloc(sizeof(struct gao));
		p->to=from;
		p->l=l;
		p->next=a[to];
		a[to]=p;
	}
}
		
void bfs()
{
	int f[MAX],e[MAX],i,t=1,time=1;
	gao *p;
	b[1].d=1;
	b[1].father=b[1].l=0;
	f[0]=f[1]=1;
	while(t<n)
	{
		time++;
		e[0]=0;
		for(i=1;i<=f[0];i++)
		{
			d[f[i]]=true;
			p=a[f[i]];
			while(p)
			{
				if(!d[p->to])
				{
					e[0]++;
					t++;
					e[e[0]]=p->to;
					b[p->to].d=time;
					b[p->to].father=f[i];
					b[p->to].l=p->l;
				}
				p=p->next;
			}
		}
		for(i=0;i<=e[0];i++)
			f[i]=e[i];
	}
}

void find()
{
	int i,x,y,l;
	scanf("%d",&k);
	for(i=0;i<k;i++)
	{
		l=0;
		scanf("%d%d",&x,&y);
		while(b[x].d<b[y].d)
		{
			l+=b[y].l;
			y=b[y].father;
		}
		while(b[x].d>b[y].d)
		{
			l+=b[x].l;
			x=b[x].father;
		}
		while(x!=y)
		{
			l+=b[x].l;
			l+=b[y].l;
			x=b[x].father;
			y=b[y].father;
		}			
		printf("%d\n",l);
	}
}

int main()
{
	build();
	bfs();
	find();
	return 0;
}
