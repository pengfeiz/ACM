#include<cstdio>
#include<algorithm>

const	int	maxn=10000000;

struct	mnode
{
	int		v;	
	mnode	*next;
};

mnode	mem[maxn];
int		mtail;

mnode	*graph[maxn];
int		n,m;

int		tree[maxn*2];
int		ttail;

int		index[maxn][2];
bool	marked[maxn];

void	madd(int	u,int	v)
{
	mtail++;
	mem[mtail].v=v;
	mem[mtail].next=graph[u];
	graph[u]=&mem[mtail];
}

int		lowbit(int	x)
{
	return(x&(-x));
}

void	dfs(int		v,int	parents)
{
	mnode		*iter;
	
	marked[v]=true;
	ttail++;
//	printf("%d \n",v);
	if (ttail<index[v][0])
		index[v][0]=ttail;
	if (ttail>index[v][1])
		index[v][1]=ttail;
//	index[v][0]<?=ttail;
//	index[v][1]>?=ttail;
	
	for (iter=graph[v];iter;iter=iter->next)
		if ((iter->v!=parents)&&(!marked[iter->v]))
		{			
			dfs(iter->v,v);
			ttail++;
			if (ttail<index[v][0])
				index[v][0]=ttail;
			if (ttail>index[v][1])
				index[v][1]=ttail;
//			index[v][1]>?=ttail;
//			index[v][1]>?=ttail;		
//			printf("%d \n",v);
		}	
}

void	update(int	x,int	d)
{
	int		i;
	
	for (i=x;i<=ttail;i+=lowbit(i))
		tree[i]+=d;
}

int		sum(int	l,int	r)
{
	int	i,j,ret;
	ret=0;
	
	for (i=r;i>=l;i-=lowbit(i))
		ret+=tree[i];
	
	
	for (j=l-1;j>i;j-=lowbit(j))
		ret-=tree[j];
	
	return(ret);
}
void	init()
{
	int	i,u,v;
	
	ttail=0;
	mtail=0;
	memset(graph,0,sizeof(graph));
	memset(marked,0,sizeof(marked));
	memset(tree,0,sizeof(tree));
	
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		index[i][0]=0x7fffffff;
		index[i][1]=0;
	}
	
	for (i=1;i<n;i++)
	{
		scanf("%d %d\n",&u,&v);
		madd(u,v);
		madd(v,u);
	}
	dfs(1,0);
	

	
	for (i=1;i<=n;i++)
		update(index[i][0],1);
		
	scanf("%d\n",&m);
	memset(marked,1,sizeof(marked));
}




void	starmain()
{
	int		i,v;
	char	ch;
	
	for (i=1;i<=m;i++)
	{
		scanf("%c %d\n",&ch,&v);
		if (ch=='Q')
			printf("%d\n",sum(index[v][0],index[v][1]));
		else
		{
			if (marked[v])			
				update(index[v][0],-1);
			else
				update(index[v][0],1);
			marked[v]=!marked[v];
		}
	}
}
int		main()
{
//	int		i;

//	freopen("c:\\in.txt","r",stdin);
	init();
	starmain();
	
	return(0);
	
}
