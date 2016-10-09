#include <iostream>
#include <stdlib.h>
using namespace std;

const	int			maxn=500;
const	int			maxm=2000;

int		n,m;
int		data[maxm+1][3];


int		parents[maxn*3];

void	init()
{
		int		i;
		char	ch;
		
		if (scanf("%d %d\n",&n,&m)==EOF)exit(0);
		
		for (i=1;i<=m;i++)
		{
			scanf("%d%c%d\n",&data[i][0],&ch,&data[i][1]);
			
			switch(ch)
			{
				case '<':
					data[i][2]=1;
					break;
				case '>':
					data[i][2]=2;
					break;
				case '=':
					data[i][2]=0;
					break;
		}
		}
}

int		set_find(int	x)
{
	int	current,root,t;
	
	current=x;
	while(parents[current]!=current)
		current=parents[current];
		
	root=current;
	
	current=x;
	while(parents[current]!=current)
	{			
		t=parents[current];
		parents[current]=root;
		current=t;
	}
	
	return(root);	
}

void	set_union(int	x,int	y)
{
	int	rootx,rooty;
	
	rootx=set_find(x);
	rooty=set_find(y);
	
	parents[rooty]=rootx;
}

bool	check(int	x,int	p)
{
	int	i,j;
	int	rootx,rooty;
	
	for (i=0;i<n*3;i++)
		parents[i]=i;
		
	for (i=1;i<=p;i++)
		if((data[i][0]!=x)&&(data[i][1]!=x))
		{
			rootx=set_find(data[i][0]*3);
			rooty=set_find(data[i][1]*3);
		
			if(rootx/3!=rooty/3)
				for (j=0;j<=2;j++)
					set_union((rootx/3)*3+(rootx+j+data[i][2])%3,(rooty/3)*3+(rooty+j)%3);
			else
				if((rootx+data[i][2])%3!=rooty%3)return(false);
		}
		
	return(true);	
}

void	starmain()
{	
	int		i,l,r;
	int		umpire;
	
	if (n==1)
	{
		printf("Player 0 can be determined to be the judge after 0 lines\n");		
		return;
	}
	if (check(n,m))	
	{
		printf("Can not determine\n");
		return;
	}
	
	umpire=n;	
	for (i=0;i<n;i++)
		if (check(i,m))
			if(umpire==n)
				umpire=i;
			else
			{
				printf("Can not determine\n");
				return;
			}
			
	if (umpire==n) 
	{
		printf("Impossible\n");
		return;
	}
	
	
	l=1;
	r=m;
	
	do
	{			
		for (i=0;i<n;i++)
			if (i!=umpire)			
				if (check(i,(l+r)/2))break;
				
		if (i>=n)		
			r=(l+r)/2;
		else
			l=(l+r)/2+1;			
	}while(l<r);
	
	printf("Player %d can be determined to be the judge after %d lines\n",umpire,l);
}
int	main()
{	
	freopen("c:\\in.txt","r",stdin);
	
	while (true)	
	{
		init();
		starmain();
	}
	
	return(0);
}

	
