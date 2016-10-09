#include<cstdio>
#include<algorithm>

const int maxn=1002;


int	n,s,m;
int d[maxn][maxn];
int	dist[maxn];

int init()
{
	int	l,x,y;
	memset(d,127,sizeof(d));	
	if(scanf("%d%d%d",&n,&m,&s)==EOF)
		return false;
	while(m--)
	{
		scanf("%d%d%d",&x,&y,&l);
		if(d[x][y]>l)
			d[x][y]=d[y][x]=l;
	}
	return true;
}

void dijkstra()
{	
	int	i,j,t=1;
	bool marked[maxn];
	memset(marked,0,sizeof(marked));	
	memset(dist,127,sizeof(dist));
	dist[s]=0;
	marked[s]=true;	
	i=s;
	while(t<n)
	{
		for(j=1;j<=n;j++)
		{
			if(d[i][j]<dist[j]-dist[i])
				dist[j]=dist[i]+d[i][j];
		}
		for(j=1;j<=n;j++)
			if(!marked[j])
			{
				i=j;
				break;
			}
		for(j=1;j<=n;j++)
			if(!marked[j])
				if(dist[j]<dist[i])
					i=j;
		marked[i]=true;
		t++;
	}
}

void outit()
{
	int i,l=0;
	for(i=1;i<=n;i++)
		if(dist[i]>l)
			l=dist[i];
	printf("%d\n",l);
}

int	main()
{
	while(init())
	{
		dijkstra();
		outit();
	}
	return 0;
}
