#include<cstdio>
#include<list>
#include<utility>
#include<algorithm>

const	int		maxn=10001;

int		n,limit;
std::list<std::pair<int,int> >	graph[maxn];
int		q[maxn];
bool	marked[maxn];
int		ans;

void	init()
{
	int	i,x,y,w;
	
	scanf("%d %d\n",&n,&limit);
	
	for (i=0;i<=n;i++)
		graph[i].clear();
	memset(q,0,sizeof(q));
	memset(marked,0,sizeof(marked));
	ans=0;
	
	if (!(n+limit))exit(0);
	for (i=1;i<n;i++)
	{
		scanf("%d %d %d\n",&x,&y,&w);
		graph[x].push_back(std::make_pair(y,w));
		graph[y].push_back(std::make_pair(x,w));		
	}
}

void	dfs(int	v)
{
	std::list<std::pair<int,int> >::iterator	iter;
	int		i,j,t,first;
	
	q[0]++;
	q[q[0]]=0;
	marked[v]=true;
	first=q[0];
	for (iter=graph[v].begin();iter!=graph[v].end();iter++)
		if (!marked[iter->first])
		{
			t=q[0];
			dfs(iter->first);
			for(i=t+1;i<=q[0];i++)			
				q[i]+=iter->second;
	
			for (i=first;i<=t;i++)			
			{
				for (j=q[0];(j>t)&&(q[i]+q[j]>limit);j--);
				ans+=j-t;
			}			
			std::inplace_merge(q+first,q+t+1,q+q[0]+1);
		}
}

int		main()
{
//	freopen("c:\\in.txt","r",stdin);
	while (true)
	{
		init();
		dfs(1);
		printf("%d\n",ans);		
	}
	return(0);
}