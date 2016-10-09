#include <iostream>
using namespace std;

#define MAX 1002


struct gao
{
	int l1,l2;
}d[MAX][MAX];


int n,m,h;
bool marked[MAX];
int dist[MAX],dis[MAX];

void dijkstra()
{	
	int	i,j,tt=1;
	
	memset(marked,0,sizeof(marked));	
	memset(dist,127,sizeof(dist));	
	memset(dis,127,sizeof(dis));
	dist[h]=dis[h]=0;
	marked[h]=true;
	dist[n+1]=dis[n+1]=100000000;
	
	
	i=h;
	while(tt<n)
	{
		for(j=1;j<=n;j++)
		{
			if(dist[i]+d[i][j].l1<dist[j])
				dist[j]=dist[i]+d[i][j].l1;
		}		
		i=n+1;
		for(j=1;j<=n;j++)
			if(!marked[j])
				if(dist[j]<dist[i])
					i=j;
		marked[i]=true;
		tt++;
	}

	tt=1;
	memset(marked,0,sizeof(marked));
	marked[h]=true;
	i=h;
	while(tt<n)
	{
		for(j=1;j<=n;j++)
		{
			if(dis[i]+d[i][j].l2<dis[j])
				dis[j]=dis[i]+d[i][j].l2;
		}		
		i=n+1;
		for(j=1;j<=n;j++)
			if(!marked[j])
				if(dis[j]<dis[i])
					i=j;
		marked[i]=true;
		tt++;
	}
}

int main()
{
	int i,j,k,x,y,l,ma;
	scanf("%d%d%d",&n,&m,&h);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			d[i][j].l1=d[i][j].l2=99999999;
	for(k=0;k<m;k++)
	{
		scanf("%d%d%d",&x,&y,&l);
		if(d[x][y].l1>l)
		{
			d[x][y].l1=l;
			d[y][x].l2=l;
		}
	}
	ma=0;
	dijkstra();
	for(i=1;i<=n;i++)
		if(dist[i]+dis[i]>ma)
			ma=dist[i]+dis[i];
	printf("%d\n",ma);
	return 0;
}