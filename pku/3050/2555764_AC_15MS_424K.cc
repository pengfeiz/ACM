#include<cstdio>
#include<set>


const int rule[4][2]={{0,-1},{0,1},{-1,0},{1,0}};

std::set<int>	table;

int		a[7][7];

void	init()
{
	int	i,j;
	
	memset(a,128,sizeof(a));
	table.clear();
	for (i=1;i<=5;i++)
	{
		for (j=1;j<=5;j++)
			scanf("%d",&a[i][j]);
		scanf("\n");
	}	
}

int		num;
void	dfs(int	x,int	y,int	p)
{
	int		i;
	
	num=num*10+a[x][y];

	if (p>5)
	{
		table.insert(num);
		num/=10;
		return;
	}
	for (i=0;i<4;i++)
		if (a[x+rule[i][0]][y+rule[i][1]]>=0)			
			dfs(x+rule[i][0],y+rule[i][1],p+1);
	num/=10;
}
void	starmain()
{
	int i,j;

	num=0;
	for (i=1;i<=5;i++)
		for(j=1;j<=5;j++)
			dfs(i,j,1);
		
}
int		main()
{
	init();
	starmain();
	printf("%d\n",table.size());
	return(0);
}

