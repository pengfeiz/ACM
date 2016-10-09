#include<cstdio>
#include<cmath>
#include<algorithm>

const	int		maxn=2001;

struct	pnode
{
	int	x,y;
};

pnode	q[maxn];
int		n,ans;

bool	cmp(pnode	a,pnode	b)
{
	if (a.x!=b.x)
		return(a.x<b.x);
	return(a.y<b.y);
}

void	init()
{
	int		i;
	
	if(scanf("%d\n",&n)==EOF)
		exit(0);
	
	for (i=1;i<=n;i++)
		scanf("%d %d\n",&q[i].x,&q[i].y);
	
	std::sort(q+1,q+n+1,cmp);
	
	ans=0;	
}


void	starmain()
{
	int		i,j,x,y;
	pnode	t1,t2;
	
	
	for (i=1;i<n;i++)
		for (j=i+1;j<=n;j++)
		{
			x=q[i].x-q[j].x;
			y=q[i].y-q[j].y;
			t1.x=q[i].x+y;
			t1.y=q[i].y-x;
			t2.x=q[i].x-y;
			t2.y=q[i].y+x;			
			if((t1.x+q[j].x)&1)continue;
			if((t1.y+q[j].y)&1)continue;
			if((t2.x+q[j].x)&1)continue;
			if((t2.y+q[j].y)&1)continue;
			t1.x=(t1.x+q[j].x)>>1;
			t1.y=(t1.y+q[j].y)>>1;
			t2.x=(t2.x+q[j].x)>>1;
			t2.y=(t2.y+q[j].y)>>1;
			if(std::binary_search(q+1,q+n+1,t1,cmp)&&
					std::binary_search(q+1,q+n+1,t2,cmp))
				ans++;
		}
	
	ans>>=1;
}

int		main()
{
//	freopen("c:\\in.txt","r",stdin);
	
	while (true)
	{
		init();
		starmain();
		printf("%d\n",ans);
	}
	
	return(0);
}


