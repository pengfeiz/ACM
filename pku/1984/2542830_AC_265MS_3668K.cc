#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;

#define MAX 40001
#define MAX2 10000

struct gsm
{
	int x,y;
}f[MAX];

struct gao
{
	int to,l;
	char c;
	struct gao *next; 
}*a[MAX];

struct song
{
	int from,to;
}b[MAX];

struct yanzi
{
	int from,to,time;
}e[MAX2];

bool c[MAX];
int d1[MAX],d2[MAX],n,m,d[MAX];
gao *p;

void dfs()
{
	int t=1,i;
	gao *p;
	f[1].x=f[1].y=0;
	c[1]=true;
	d1[0]=1;
	d1[1]=1;
	while(t<n)
	{
		d2[0]=0;
		for(i=1;i<=d1[0];i++)
		{
			c[d1[i]]=true;
			p=a[d1[i]];
			while(p)
			{
				if(!c[p->to])
				{
					d2[0]++;
					d2[d2[0]]=p->to;
					t++;
					f[p->to].x=f[d1[i]].x;
					f[p->to].y=f[d1[i]].y;
					if(p->c=='E')
						f[p->to].x+=p->l;
					else if(p->c=='W')
						f[p->to].x-=p->l;
					else if(p->c=='N')
						f[p->to].y+=p->l;
					else
						f[p->to].y-=p->l;
				}
				p=p->next;
			}
		}
		for(i=0;i<=d2[0];i++)
			d1[i]=d2[i];
	}
}	

int dosth(int x)
{
	int root;
	if(d[x]==x)
		return x;
	root=dosth(d[x]);
	d[x]=root;
	return root;
}

int main()
{
	int i,from,to,l,k,x,y,j;
	char s;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		c[i]=false;
		a[i]=NULL;
		d[i]=i;
	}
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d",&from,&to,&l);
		getchar();
		scanf("%c",&s);
		p=(struct gao*)malloc(sizeof(struct gao));
		p->to=to;
		p->l=l;
		p->c=s;
		p->next=a[from];
		a[from]=p;
		p=(struct gao*)malloc(sizeof(struct gao));
		p->to=from;
		p->l=l;
		if(s=='E')
			p->c='W';
		else if(s=='W')
			p->c='E';
		else if(s=='N')
			p->c='S';
		else
			p->c='N';
		p->next=a[to];
		a[to]=p;
		b[i].from=from;
		b[i].to=to;
	}
	scanf("%d",&k);
	for(i=0;i<k;i++)
	{
		scanf("%d%d%d",&e[i].from,&e[i].to,&e[i].time);
		if(e[i].time>m)
			e[i].time=m;
	}
	dfs();
	j=0;
	for(i=1;i<=m;i++)
	{
		x=b[i].from;
		y=b[i].to;
		x=dosth(x);
		y=dosth(y);
		if(x>y)
			d[x]=d[y];
		else if(x<y)
			d[x]=d[y];
		while(i==e[j].time)
		{
			if(dosth(e[j].from)==dosth(e[j].to))
				printf("%d\n",abs(f[e[j].from].x-f[e[j].to].x)+abs(f[e[j].from].y-f[e[j].to].y));
			else
				printf("-1\n");
			j++;
			if(j==k)
				break;
		}
	}
	return 0;
}
