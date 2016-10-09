#include<cstdio>
#include<list>
#include<vector>
#define MAX 100002

int	cost[MAX],n,m,in[MAX],out[MAX],dist[MAX];

std::vector<int>	a[MAX];
std::list<int>		q;

void	init()
{
	int		i,x,y;

	q.clear();
	
	scanf("%d%d",&n,&m);
	for (i=1;i<=n;i++)
	{
		scanf("%d",&cost[i]);
		in[i]=0;
		out[i]=0;
		dist[i]=0x80000000;		
	}
		
	for (i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		a[x].push_back(y);
		out[x]++;
		in[y]++;
	}
	cost[n+1]=0;
	dist[n+1]=0x80000000;	
	for (i=1;i<=n;i++)
	{
		if (!in[i])
		{
			in[i]=1;
			a[0].push_back(i);
		}		
		
		if (!out[i])
			a[i].push_back(n+1);
	}
	q.push_back(0);	

}

void	starmain()
{
	std::vector<int>::iterator		iter;
	int v;
	

	while (!q.empty())
	{		
		v=*q.begin();
		q.pop_front();
		
		iter=a[v].begin();
		while (iter!=a[v].end())
		{
			in[*iter]--;
			if (dist[v]+cost[*iter]>dist[*iter])
				dist[*iter]=dist[v]+cost[*iter];

			if (!in[*iter])
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
		a[i].clear();
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

