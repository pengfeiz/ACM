#include<cstdio>
#include<iostream>
#include<string>

const	int		maxn=300;


struct	qnode
{
	int		v;	
	qnode	*next;
};

qnode	mem[maxn*2];
int		mtail;
qnode	*graph[maxn];

int		n,m;
int		f[maxn][maxn];
int		cost[maxn];
int		max;

std::string	namelist[maxn];
int		ntail;
int		ans;

bool	marked[maxn];

int		find(std::string		t)
{
	int		i;
	
	for (i=1;i<=ntail;i++)
		if (namelist[i]==t)
			return(i);
	ntail++;
	namelist[ntail]=t;
	return(ntail);
}

void	madd(int	u,int	v)
{
	marked[v]=false;
	mtail++;
	mem[mtail].v=v;
	mem[mtail].next=graph[u];
	graph[u]=&mem[mtail];
}

void	init()
{
	int				i,pos,u;
	std::string		t,tt;
	
	mtail=0;
	ntail=1;
	memset(f,127,sizeof(f));
	max=f[0][0];
	cost[1]=0x7fffffff;
	memset(marked,1,sizeof(marked));
	memset(graph,0,sizeof(graph));

	for (i=1;i<=n;i++)
	{
		std::cin>>t;
		std::cin>>cost[u=find(t)];
		getline(std::cin,t);
		if (t.empty())
			continue;
		t.erase(0,1);
		while ((pos=t.find_first_of(" "))^0xffffffff)
		{
			tt=t.substr(0,pos);
			t.erase(0,pos+1);
			madd(u,find(tt));
		}
		madd(u,find(t));
	}
	for (i=2;i<=n+1;i++)
		if(marked[i])
			madd(1,i);
}

int	dfs(int	v)
{
	qnode	*iter;
	int		i,j,total,tail;
	int		t[maxn];
	
	f[v][0]=0;
	
	if (!graph[v])
	{
		f[v][1]=cost[v];
		return(1);
	}	
	total=0;
	for (iter=graph[v];iter;iter=iter->next)
	{
		total+=tail=dfs(iter->v);
		memset(t,127,sizeof(t));
		t[0]=0;
		for (i=0;f[v][i]!=max;i++)
			for (j=0;f[iter->v][j]!=max;j++)
				t[i+j]<?=f[v][i]+f[iter->v][j];
		memcpy(f[v],t,sizeof(t));
	}
	total++;
	f[v][total]<?=cost[v];
	return(total);
}

void	starmain()
{
	int		i;
		
	dfs(1);
	if (!m)
		ans=0;
	else
		ans=0x7fffffff;
	for (i=m;i<=n;i++)
		ans<?=f[1][i];
}


void	makedata()
{
	int		i;
	int		num[200][2];
	num[1][0]=1;
	num[1][1]=0;
	
	printf("200 1\naa 10\n");
	
	for (i=1;i<200;i++)
	{
		num[i][0]=num[i-1][0]+1;
		num[i][1]=num[i-1][1];
		if (num[i][0]>26)
		{
			num[i][0]-=26;
			num[i][1]++;
		}
		printf("%c%c %d %c%c",num[i][1],num[i][0],i,num[i-1][1],num[i-1][0]);
	}
	
	printf("#\n");
		
}
int		main()
{
	
//	freopen("c:\\in.txt","w",stdout);
//	makedata();
	
//	freopen("c:\\in.txt","r",stdin);	
	while (std::cin>>n>>m)
	{
		init();
		starmain();
		std::cout<<ans<<std::endl;
	}
	
	return(0);
}
