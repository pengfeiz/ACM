#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 2001

struct	vertex
{
	int	c,f;
	bool	enabled;
};

vertex graph[MAX][MAX];
int	n,s,e;

bool visited[MAX];

int min(int a,int b)
{return a<b?a:b;}

void init()
{
	int	x,y;	
	memset(graph,0,sizeof(graph));
	scanf("%d %d %d\n",&n,&s,&e);	
	while(scanf("%d %d\n",&x,&y)!=EOF)
	{		
		scanf("%d\n",&graph[x][y].c);
		graph[x][y].enabled=true;
	}	
}


int	search(int v,int d)
{
	int	i,t;
	if((visited[v])||(!d))
		return 0;
	if(v==e)
		return d;
	visited[v]=true;
	for(i=0;i<n;i++)
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
	for(i=0;i<n;i++)
		total+=graph[s][i].f;
	printf("%d\n",total);
}

int	main()
{
	freopen("in.txt","r",stdin);
	init();
	maxflow();
	outit();
	system("pasue");
	return 0;
}
