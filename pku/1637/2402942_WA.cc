#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 800
#define MAX2 201

struct vertex
{
	int	c,f;
	bool enabled;
}graph[MAX][MAX];

struct gao
{
	int x,y;
}b[MAX];

int	nn,n,m,t;

bool visited[MAX],ff;
int a[MAX2],c[MAX2];

int min(int a,int b)
{return a<b?a:b;}

void init()
{
	int	i,x,y,q;
	ff=true;
	memset(graph,0,sizeof(graph));
	memset(a,0,sizeof(a));
	memset(c,0,sizeof(c));
	scanf("%d%d",&nn,&m);
	t=0;
	while(m--)
	{
		scanf("%d%d%d",&x,&y,&q);
		if(q==1)
		{
			a[x]++;
			a[y]--;
		}
		else
		{
			b[t].x=x;
			c[x]++;
			b[t].y=y;
			c[y]++;
			t++;
		}
	}
	for(i=1;i<=nn;i++)
	{
		if((a[i]+c[i])%2)
		{
			ff=false;
			return ;
		}
		else
			a[i]=(c[i]+a[i])/2;
	}
	n=t+nn+1;
	for(i=1;i<=t;i++)
	{
		graph[0][i].c=1;
		graph[0][i].enabled=true;
	}
	for(i=1;i<=t;i++)
	{
		graph[i][b[i-1].x+t].c=1;
		graph[i][b[i-1].x+t].enabled=true;
		graph[i][b[i-1].y+t].c=1;
		graph[i][b[i-1].y+t].enabled=true;
	}
	for(i=t+1;i<=t+nn;i++)
	{
		if(a[i-t]>0)
		{
			graph[i][n].c=a[i-t];
			graph[i][n].enabled=true;
		}
	}
}


int	search(int v,int d)
{
	int	i,t;
	if((visited[v])||!d)
		return 0;
	if(v==n)
		return d;
	visited[v]=true;
	for(i=0;i<=n;i++)
	{
		if((graph[v][i].enabled)&&(t=search(i,min(d,graph[v][i].c-graph[v][i].f))))
			{
				graph[v][i].f+=t;
				return t;
			}
		if((graph[i][v].enabled)&&(t=search(i,min(d,graph[i][v].f))))
			{
				graph[i][v].f-=t;
				return t;
			}		
	}
	return 0;
}

void maxflow()
{
	do
	{
		memset(visited,0,sizeof(visited));
	}while(search(0,0x7FFFFFFF));
}

void outit()
{
	int	total=0,i;
	if(ff)
	{
		for(i=0;i<=n;i++)
			total+=graph[0][i].f;
		if(total==t)
			printf("possible\n");
		else
			printf("impossible\n");
	}
	else
		printf("impossible\n");
}

int	main()
{
//	freopen("in.txt","r",stdin);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		init();
		if(ff)
			maxflow();
		outit();
	}
	return 0;
}
