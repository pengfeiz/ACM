#include<cstdio>
#include<algorithm>
#include<cmath>

const	int		maxn=101;
const	double	zero=1e-8;

struct	node
{
	double	current,speed,maxspeed;
};

int		n,t;
node	q[maxn];
double	finish[maxn];
double	bandwidth;

void	init()
{
	int		i;
	
	memset(finish,0,sizeof(finish));
	
	scanf("%d",&n);
	if (!n)exit(0);
	t++;
	scanf("%lf\n",&bandwidth);
	
	for (i=1;i<=n;i++)	
		scanf("%lf%lf%lf\n",&q[i].current,&q[i].speed,&q[i].maxspeed);				
}

void	starmain()
{
	int		i,j,minj,count;
	double	min;
	bool	marked[maxn];
	double	speed,dis,t;
	
	memset(marked,0,sizeof(marked));
	
	for(i=1;i<=n;i++)
	{
		min=1e100;
		for(j=1;j<=n;j++)
			if((!marked[j])&&((t=q[j].current/q[j].speed)<min))
			{
				min=t;
				minj=j;
			}			
		for(j=1;j<=n;j++)
			if(!marked[j])
			{
				q[j].current-=q[j].speed*min;
				finish[j]+=min;
			}				
		marked[minj]=true;		
		while(true)
		{
			for(j=1,speed=bandwidth,count=0;j<=n;j++)
				if(!marked[j])
				{
					if(q[j].maxspeed-q[j].speed>zero)count++;
					speed-=q[j].speed;
				}
			if((fabs(speed)<=zero)||(!count))break;
			dis=speed/count;
			for(j=1;j<=n;j++)
				if((!marked[j])&&(q[j].maxspeed-q[j].speed>zero))
				{
					q[j].speed+=dis;
					if(q[j].speed>q[j].maxspeed)						
						q[j].speed=q[j].maxspeed;						
				}			
		}	
	}
}

void	outit()
{
	int	i;
	
	printf("Case %d:\n",t);
	for (i=1;i<=n;i++)
		printf("NO%d:%.3lfs\n",i,finish[i]);		
}

int		main()
{
//	freopen("c:\\in.txt","r",stdin);
	
	t=0;	
	while (true)
	{
		init();
		starmain();
		outit();
	}
	return(0);
}
