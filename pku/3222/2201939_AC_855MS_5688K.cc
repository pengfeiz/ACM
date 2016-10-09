#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;

#define MAX 20001

struct gao
{
	int to;
	bool t;
	struct gao *next;
	struct gao *other;
}*a[MAX];

int n,m;
bool d[MAX];

int homedfs(int x,int father)
{
	gao *p;
	int t,c,b;
	p=a[x];
	d[x]=true;
	t=0;
	while(p)
	{
		if(!p->t)
		{
			p=p->next;
			continue;
		}
		else
		{
			p->t=false;
			p->other->t=false;
		}
		if(d[p->to])
		{
			if(t==0)
			{
				t++;
				b=p->to;
			}
			else
			{
				printf("%d %d %d\n",b,x,p->to);
				t=0;
			}
		}
		else if(!d[p->to])
		{
			c=homedfs(p->to,x);
			if(c)
			{
				t++;
				if(t==1)
					b=p->to;
				if(t==2)
				{
					printf("%d %d %d\n",b,x,p->to);
					t=0;
				}
			}
		}
		p=p->next;
	}
	if(t)
	{
		printf("%d %d %d\n",father,x,b);
		return 0;
	}
	else
		return 1;
}

void homebuild()
{
	int i,from,to;
	gao *p,*q;
	scanf("%d%d",&n,&m);
	for(i=0;i<=n;i++)
	{
		a[i]=NULL;
		d[i]=false;
	}
	while(m--)
	{
		scanf("%d%d",&from,&to);
		if(from>to)
			swap(from,to);
		p=(struct gao *)malloc(sizeof(struct gao));
		p->to=to;
		p->t=true;
		p->next=a[from];
		q=(struct gao *)malloc(sizeof(struct gao));
		q->to=from;
		q->t=true;
		q->next=a[to];
		p->other=q;
		q->other=p;
		a[from]=p;
		a[to]=q;
	}
}

int main()
{
	homebuild();
	homedfs(1,1);
	return 0;
}