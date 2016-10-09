#include<cstdio>
#include<algorithm>
#include<list>

const	int		maxn=1001;


struct	edge
{
	int		v,w;
};


int				n,s;
std::list<edge>	graph[maxn];
int				dist[maxn];

void	init()
{
	int		x,y;
	edge	t;
	
	scanf("%d%d",&n,&s);
	while(s--)
	{
		scanf("%d%d%d",&x,&y,&t.w);
		t.v=y;
		graph[x].push_back(t);
		t.v=x;
		graph[y].push_back(t);
	}
}

void dijkstra()
{	
	int	i,j;
	bool marked[maxn];
	std::list<edge>::iterator iter;	
	memset(marked,0,sizeof(marked));	
	memset(dist,127,sizeof(dist));
	dist[1]=0;
	marked[1]=true;	
	i=1;
	while(i!=n)
	{
		iter=graph[i].begin();
		while(iter!=graph[i].end())
		{
			if(dist[i]+iter->w<dist[iter->v])
				dist[iter->v]=dist[i]+iter->w;
			iter++;
		}
		
		i=n;
		for(j=0;j<n;j++)
			if(!marked[j])
				if(dist[j]<dist[i])
					i=j;
		marked[i]=true;
	}
}

void outit()
{printf("%d\n\n",dist[n]);}

int	main()
{
	int t,i;

	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		printf("Scenario #%d:\n",i);
		init();
		dijkstra();
		outit();
	}
	return 0;
}
