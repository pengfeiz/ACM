#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 201

struct	vertex
{
	int		c,f;
	bool	enabled;
};

vertex graph[MAX][MAX];
int	n,s,e;

bool visited[MAX];

int min(int a,int b)
{return a<b?a:b;}

bool init()
{
	int	x,y,m;	
	memset(graph,0,sizeof(graph));
	if(scanf("%d%d",&m,&n)!=2)
		return false;;	
	s=1;
	e=n;
	while(m--)
	{
		scanf("%d%d",&x,&y);	
		scanf("%d",&graph[x][y].c);
		graph[x][y].enabled=true;
	}
	return true;
}


int	search(int v,int d)
{
	int	i,t;
	if((visited[v])||(!d))
		return 0;
	if(v==e)
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
	}while(search(s,0x7FFFFFFF));
}

void outit()
{
	int	total,i;
	total=0;
	for(i=1;i<=n;i++)
		total+=graph[s][i].f;
	printf("%d\n",total);
}

int	main()
{
//	freopen("in.txt","r",stdin);
	while(init())
	{
		maxflow();
		outit();
	}
	return 0;
}
