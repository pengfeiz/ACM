#include<cstdio>
#include<algorithm>

const	int		maxn=100001;

int		rule[131072];
int		max[18][maxn];
int		mtail;
int		index[maxn];

int		q[maxn];
int		n,m;

void	rmqinit()
{
	int		i,j;
	rule[0]=0;
	rule[1]=0;
	
	for (i=1;(1<<i)<=mtail+1;i++)	
	{
		for (j=1<<i;j<=mtail;j++)					
			max[i][j]=std::max(max[i-1][j-(1<<(i-1))],max[i-1][j]);
			
		for (j=1<<i;j<(2<<i);j++)
			rule[j]=i;
	}			
		
}

int	find(int	l,int	r)
{
	if (l>r)
		return(0x80000000);
		
	return(std::max(max[rule[r-l+1]][r],
		max[rule[r-l+1]][l+(1<<rule[r-l+1])-1]));	
}

void	init()
{
	int		i,t,total;
	
	scanf("%d %d\n",&n,&m);
	if (!n)exit(0);
	
	mtail=0;
	total=1;	
	scanf("%d",&t);
	index[1]=1;
	q[1]=t;
	for (i=2;i<=n;i++)
	{
		scanf("%d",&q[i]);
		index[i]=mtail+1;
		
		if (t==q[i])
			total++;
		
		else
		{			
			index[i]++;
			mtail++;
			max[0][mtail]=total;
			t=q[i];			
			total=1;
		}				
	}
	
	mtail++;
	max[0][mtail]=total;
	
	
	scanf("\n");
	rmqinit();
	
}

void	starmain()
{
	int		i,l,r,t1,t2,ans;
	
	for (i=1;i<=m;i++)
	{
		scanf("%d %d\n",&l,&r);
		
		t1=std::upper_bound(q+l,q+r+1,q[l])-q;
		t2=std::lower_bound(q+l,q+r+1,q[r])-q-1;
		
		if (t2>t1)
			ans=std::max(find(index[t1],index[t2]),t1-l);
		else
			ans=t1-l;
			
		ans=std::max(ans,r-t2);
		
		printf("%d\n",ans);
	}
}

int		main()
{
//	freopen("c:\\in.txt","r",stdin);
	
	while (true)
	{
		init();
		starmain();
	}

	return(0);
} 