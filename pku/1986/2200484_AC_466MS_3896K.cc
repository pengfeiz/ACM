#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;

#define MAX 40001
#define MAX2 10001

struct gao
{
	int to,l;
	struct gao *next;
}*a[MAX],*f[MAX];

struct yanzi
{
	int x,l,d;
}ans[MAX2];

int n,m,t,c[MAX],root[MAX];
bool d[MAX];

void build()
{
	int i,from,to,l,x,y;
	t=0;
	gao *p,*q;
	scanf("%d%d",&n,&m);
	for(i=0;i<=n;i++)
	{
		root[i]=i;
		d[i]=false;
		a[i]=NULL;
		f[i]=NULL;
	}
	for(i=1;i<n;i++)
	{
		scanf("%d%d%d%*s",&from,&to,&l);
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
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&x,&y);
		q=(struct gao *)malloc(sizeof(struct gao));
		q->to=y;
		q->l=i;
		q->next=f[x];
		f[x]=q;
		q=(struct gao *)malloc(sizeof(struct gao));
		q->to=x;
		q->l=i;
		q->next=f[y];
		f[y]=q;
		ans[i].x=x;
		ans[i].l=y;
	}
}

int root2(int x)
{
	int r=root[x];
	if(r!=x)
	{
		root[x]=root2(r);
		c[x]+=c[r];
	}
	return root[x];
}

void dosth(int x)
{
	gao *p;
	p=f[x];
	while(p)
	{
		if(d[p->to])
			ans[p->l].d=root2(p->to);
		p=p->next;
	}
}
	
void dfs(int x)
{
	gao *p;
	d[x]=true;
	p=a[x];
	while(p)
	{
		if(!d[p->to])
		{
			dfs(p->to);
			root[p->to]=x;
			c[p->to]=p->l;
		}
		p=p->next;
	}
	dosth(x);
}

void find()
{
	int i;
	for(i=0;i<m;i++)
	{
		root2(ans[i].x);
		root2(ans[i].l);
		root2(ans[i].d);
		printf("%d\n",c[ans[i].x]+c[ans[i].l]-2*c[ans[i].d]);
	}
}

int main()
{	
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	build();
	dfs(n/5);
	find();
	return 0;
}