#include <iostream>
#include <stdlib.h>
using namespace std;
#define MAX 10001

struct gao
{
	int to,l;
	struct gao *next;
}*a[MAX];

int len,v,n,m;
bool b[MAX];

void dfs(int x,int l)
{
	struct gao *p;
	b[x]=true;
	if(l>len)
	{
		v=x;
		len=l;
	}
	p=a[x];
	while(p)
	{
		if(!b[p->to])
			dfs(p->to,l+p->l);
		p=p->next;
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
		p->next=NULL;
		if(a[from])
		{
			p->next=a[from];
			a[from]=p;
		}
		else
			a[from]=p;
		p=(struct gao *)malloc(sizeof(struct gao));
		p->to=from;
		p->l=l;
		p->next=NULL;
		if(a[to])
		{
			p->next=a[to];
			a[to]=p;
		}
		else
			a[to]=p;
	}
	dfs(1,0);
	memset(b,0,sizeof(b));
	dfs(v,0);
	printf("%d\n",len);
	return 0;
}





