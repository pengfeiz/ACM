#include<cstdio>
#include<algorithm>

const	int		maxn=101;

int		dist[maxn][maxn];
int		graph[maxn][maxn];
int		n,m,max;
int		ans,ansk,ansi,ansj;

void	init()
{
	int		i,u,v,w;
	
	scanf("%d %d\n",&n,&m);
	if (!n)
		exit(0);
	
	memset(dist,127,sizeof(dist));
	memset(graph,127,sizeof(graph));
	max=dist[0][0];
	ans=max;
	
	for (i=1;i<=m;i++)
	{
		scanf("%d %d",&u,&v);
		scanf("%d\n",&w);
		graph[u][v]<?=w;
		graph[v][u]=graph[u][v];		
	}
	memcpy(dist,graph,sizeof(graph));
}

void	starmain()
{
	int	i,j,k,t;
	
	for (k=1;k<=n;k++)
	{
		for (i=1;i<k;i++)	
			if (graph[i][k]<max)
			for (j=1;j<k;j++)
				if ((graph[j][k]<max)&&(i!=j))
				{
					t=graph[k][i]+dist[i][j]+graph[k][j];
					if (t<ans)
					{
						ans=t;
						ansi=i;
						ansj=j;
						ansk=k;
					}
				}
		
		for (i=1;i<=n;i++)
			if (dist[i][k]<max)
				for (j=1;j<=n;j++)
					if (dist[j][k]<max)
						dist[i][j]<?=dist[i][k]+dist[k][j];
	}
	
	memcpy(dist,graph,sizeof(graph));
	for (k=1;k<ansk;k++)
		for (i=1;i<=n;i++)
			if (dist[i][k]<max)
				for (j=1;j<=n;j++)
					if (dist[k][j]<max)
						dist[i][j]<?=dist[i][k]+dist[k][j];
	for (i=1;i<=n;i++)
		dist[i][i]=0;
	
}

void	outit()
{
	int		s,t,i;

	if (ans>=max)
	{
		printf("No solution.\n");
		return;
	}
	
	s=ansi;
	t=ansj;
	
	printf("%d %d",ansk,s);
	
	while (s!=t)
	{		
		for (i=1;i<=n;i++)
			if (graph[s][i]+dist[i][t]==dist[s][t])
				break;
		s=i;
		printf(" %d",s);
	}
	printf("\n");	
}

int		main()
{
//	freopen("c:\\in.txt","r",stdin);
	
	init();
	starmain();
	outit();
	
	return(0);
}

