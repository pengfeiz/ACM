#include<cstdio>
#include<algorithm>

const	int		maxn=1200;

bool	graph[maxn][maxn];
int		n;

void	init()
{
	int		i,m,x,y;
	
	scanf("%d %d\n",&n,&m);	
	for (i=1;i<=m;i++)
	{
		scanf("%d %d\n",&x,&y);
		graph[x][y]=graph[y][x]=true;		
	}
}

void	starmain()
{
	int		i,j,k,p;
	
	for (i=1;i<=n;i++)
		for (j=i+1;j<=n;j++)
			if ((!graph[i][j]))
				for (k=1;k<=n;k++)
					if ((graph[i][k])&&(graph[j][k]))
						for (p=1;p<=n;p++)
							if ((graph[p][j])&&(!graph[p][i])&&(!graph[p][k]))
							{
								printf("No\n");
								exit(0);
							}
	printf("Yes\n");
}

int		main()
{
//	freopen("c:\\in.txt","r",stdin);	
	init();
	starmain();
	return(0);	
} 