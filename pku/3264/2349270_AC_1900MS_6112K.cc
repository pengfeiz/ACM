#include<cstdio>
#include<algorithm>
#include<functional>
#include<cmath>

const	int		maxn=50001;

int		rule[65537];
int		min[17][maxn],max[17][maxn];
int		n,m;

void	init()
{
	int	i,j;
	
	scanf("%d %d\n",&n,&m);
	for (i=1;i<=n;i++)
	{
		scanf("%d\n",&min[0][i]);
		max[0][i]=min[0][i];
	}
	
	rule[0]=0;
	rule[1]=0;
	
	for (i=1;(1<<i)<=n+1;i++)
	{
		rule[1<<i]=i;
		for (j=1<<i;j<=n;j++)
		{
			min[i][j]=std::min(min[i-1][j-(1<<(i-1))],min[i-1][j]);
			max[i][j]=std::max(max[i-1][j-(1<<(i-1))],max[i-1][j]);
		}
		
		for (j=1<<i;j<(2<<i);j++)
			rule[j]=i;
	}
}

inline	int		fmin(int	a,int	b)
{
	if (a<b)
		return(a);
	else
		return(b);
		
}

inline	int		fmax(int	a,int	b)
{
	if (a<b)
		return(b);
	else
		return(a);
}

void	starmain()
{
	int		i,l,r,t1,t2,k;
	
	for (i=1;i<=m;i++)
	{
		scanf("%d %d\n",&l,&r);
		k=rule[r-l+1];
		t1=std::min(min[k][r],min[k][l+(1<<k)-1]);
		t2=std::max(max[k][r],max[k][l+(1<<k)-1]);		
		printf("%d\n",(int)fabs(t1-t2));
	}
}

int		main()
{
//	freopen("c:\\in.txt","r",stdin);
	
	init();
	starmain();
	
	return(0);
}
