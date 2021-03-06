#include <iostream>
#include <algorithm>
using namespace std;


#define MAX 110
#define MAX2 1100

int e[MAX2];

struct	vertex
{
	int		c,f;
	bool	enabled;
};

vertex graph[MAX][MAX];
int	n,nn,mm;

struct 
{
	int n,a[MAX];
}b[MAX2];

bool visited[MAX];

int min(int a,int b)
{return a<b?a:b;}

int	search(int v,int d)
{
	int	i,t;
	if((visited[v])||(!d))
		return 0;
	if(v==n)
		return d;
	visited[v]=true;
	for(i=1;i<=n;i++)
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
	int	total,i;
	total=0;
	for(i=0;i<=n;i++)
		total+=graph[0][i].f;
	printf("%d\n",total);
}

int main()
{
	int i,j,x,h;
	scanf("%d%d",&mm,&nn);
	memset(graph,0,sizeof(graph));
	n=nn+1;
	for(i=1;i<=mm;i++)
		scanf("%d",&e[i]);
	memset(b,0,sizeof(b));
	for(i=1;i<=nn;i++)
	{
		scanf("%d",&h);
		graph[i][n].enabled=true;
		for(j=0;j<h;j++)
		{
			scanf("%d",&x);
			b[x].a[b[x].n]=i;
			b[x].n++;
			if(b[x].n==1)
				graph[i][n].c+=e[x];
		}
		scanf("%d",&x);
		graph[0][i].enabled=true;
		graph[0][i].c=x;
	}
	for(i=1;i<=mm;i++)
	{
		for(j=1;j<b[i].n;j++)
		{
			graph[b[i].a[j]][b[i].a[j-1]].enabled=true;
			graph[b[i].a[j]][b[i].a[j-1]].c=999999;
		}
	}

	maxflow();
	outit();
	return 0;
}		
