#include<cstdio>
#include<algorithm>
#include<list>

const	int		maxn=1001;


struct	edge
{
	int		v,w;
};


int				n,s,e;
std::list<edge>	graph[maxn];
int				dist[maxn];

void	init()
{
	int		x;
	edge	t;
	
	scanf("%d%d%d",&n,&s,&e);
	while(scanf("%d%d%d",&x,&t.v,&t.w)!=EOF)
		graph[x].push_back(t);
}

void dijkstra()
{	
	int	i,j;
	bool marked[maxn];
	std::list<edge>::iterator iter;	
	memset(marked,0,sizeof(marked));	
	memset(dist,127,sizeof(dist));
	dist[s]=0;
	marked[s]=true;	
	i=s;
	while(i!=e)
	{
		iter=graph[i].begin();
		while(iter!=graph[i].end())
		{
			if(dist[i]+iter->w<dist[iter->v])
				dist[iter->v]=dist[i]+iter->w;
			iter++;
		}
		
		i=e;
		for(j=0;j<n;j++)
			if(!marked[j])
				if(dist[j]<dist[i])
					i=j;
		marked[i]=true;
	}
}

void outit()
{printf("%d\n",dist[e]);}

int	main()
{
	freopen("data4.in","r",stdin);	
	freopen("data4.out","w",stdout);
	init();
	dijkstra();
	outit();
	return 0;
}
