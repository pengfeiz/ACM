#include<cstdio>
#include<list>
#include<vector>

const	int			maxn=100002;

std::vector<int>	graph[maxn];
int					cost[maxn];
int					n,m;
int					totalin[maxn],totalout[maxn];

std::list<int>		q;
int					dist[maxn];

void	init()
{
	int		i,x,y;

	q.clear();
	
	scanf("%d %d\n",&n,&m);
	for (i=1;i<=n;i++)
	{
		scanf("%d\n",&cost[i]);
		totalin[i]=0;
		totalout[i]=0;
		dist[i]=0x80000000;		
	}
		
	for (i=1;i<=m;i++)
	{
		scanf("%d %d\n",&x,&y);
		graph[x].push_back(y);
		totalout[x]++;
		totalin[y]++;
	}
	cost[n+1]=0;
	dist[n+1]=0x80000000;	
	for (i=1;i<=n;i++)
	{
		if (!totalin[i])
		{
			totalin[i]=1;
			graph[0].push_back(i);
		}		
		
		if (!totalout[i])
			graph[i].push_back(n+1);
	}
	q.push_back(0);	

}

void	starmain()
{
	std::vector<int>::iterator		iter;
	int								v;
	

	while (!q.empty())
	{		
		v=*q.begin();
		q.pop_front();
		
		iter=graph[v].begin();
		while (iter!=graph[v].end())
		{
			totalin[*iter]--;
			if (dist[v]+cost[*iter]>dist[*iter])
				dist[*iter]=dist[v]+cost[*iter];

			if (!totalin[*iter])
				q.push_back(*iter);
			iter++;
		}	
	}	
}

void	outit()
{
	int		i;
	
	printf("%d\n",dist[n+1]);
	
	for (i=0;i<=n+1;i++)
		graph[i].clear();
}

int		main()
{
//	freopen("c:\\in.txt","r",stdin);
	
	while (!feof(stdin))
	{
		init();
		starmain();
		outit();
	}	
	
	return(0);	
}

