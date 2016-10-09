#include<cstdio>
#include<algorithm>

const	int		maxn=41;
const	int		maxm=11;

struct	rnode
{
	int		x,y;
};

struct	mnode
{
	int		v;
	mnode	*next;
};

int		n,m;
bool	marked[maxn][maxn];

rnode	red[maxm];
bool	row[maxn][3];
bool	col[maxn][3];

mnode	mem[maxn*maxn];
int		mtail;
mnode	*graph[maxn];

int		mx[maxn];
int		my[maxn];
bool	visited[maxn];

int		ans;

void	init()
{
	int	i,k,x,y;
	
	memset(marked,0,sizeof(marked));	
	memset(row,0,sizeof(row));
	memset(col,0,sizeof(col));	
	ans=0;
	
	scanf("%d %d %d\n",&n,&m,&k);
	
	for (i=1;i<=m;i++)
	{
		scanf("%d %d\n",&red[i].x,&red[i].y);		
		red[i].x++;
		red[i].y++;		
	}
		
	for (i=1;i<=k;i++)
	{
		scanf("%d %d\n",&x,&y);		
		x++;
		y++;
		marked[x][y]=true;
	}
}

void	madd(int	u,int	v)
{
	mtail++;
	mem[mtail].v=v;
	mem[mtail].next=graph[u];
	graph[u]=&mem[mtail];
}

bool	search(int	v)
{
	mnode	*iter;
	
	if (visited[v])
		return(false);
	
	visited[v]=true;
	
	for (iter=graph[v];iter;iter=iter->next)
		if ((!my[iter->v])||(search(my[iter->v])))
		{
			mx[v]=iter->v;
			my[iter->v]=v;
			return(true);
		}
	return(false);
}

void	buildgraph(int	key)
{
	int		i,j;
	
	mtail=0;
	memset(graph,0,sizeof(graph));
	memset(mx,0,sizeof(mx));
	memset(my,0,sizeof(my));	
	
	for (i=1;i<=n;i++)		
		for (j=1;j<=n;j++)
			if (!marked[i][j])
				if((!col[j][key])&&(!row[i][key])&&(((i+j)&1)!=(key&1)))					
					madd(i,j);
}

int		match(int	key)
{
	int		i,total;
	
	buildgraph(key);
	
	total=0;
	
	for (i=1;i<=n;i++)
		if (!mx[i])
		{
			memset(visited,0,sizeof(visited));
			if (search(i))			
				total++;		
		}
	
	return(total);
}



void	dfs(int	p)
{
	int		i;
	if (ans>=n*2)
		return;
	if (p>m)
	{
		int	t=match(1)+match(2)+m;
		if (t>ans)
			ans=t;
		
		return;
	}
	
	
	for (i=1;i<=2;i++)
		if ((!row[red[p].x][i])&&(!col[red[p].y][i]))
		{			
			row[red[p].x][i]=true;
			col[red[p].y][i]=true;
			marked[red[p].x][red[p].y]=true;
			
			dfs(p+1);			
			marked[red[p].x][red[p].y]=false;
					
			row[red[p].x][i]=false;
			col[red[p].y][i]=false;
		}
}

int		main()
{
	int		i,t;
	
//	freopen("c:\\in.txt","r",stdin);
	
	scanf("%d\n",&t);
	
	for (i=1;i<=t;i++)
	{
		init();
		dfs(1);
		printf("%d\n",ans);
	}
	return(0);
}