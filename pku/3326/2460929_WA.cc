#include<cstdio>
#include<algorithm>

const	int		maxn=1010;
const	int		maxtime=1261;

int		pc[maxn][maxtime];
int		last[maxn];
int		n,m;

void	init()
{
	memset(pc,0,sizeof(pc));
	memset(last,0,sizeof(last));
	
	scanf("%d %d\n",&n,&m);
	if (n+m==0)
		exit(0);
	
}

void	starmain()
{
	int		i,j,k,num,count;
	int		computer,student,time,key;
	int		stime,etime;
	bool	ok1,ok2;

	
	scanf("%d\n",&num);	
	for (i=1;i<=num;i++)
	{
		scanf("%d %d %d %d\n",&time,&computer,&student,&key);
		if (key)		
			last[computer]=time;
		else
		{
			for (j=last[computer];j<=time;j++)			
				pc[computer][j]=student;
			last[computer]=0;
		}
	}
	
	scanf("%d\n",&num);
	for (i=1;i<=num;i++)
	{		
		scanf("%d %d %d\n",&stime,&etime,&student);
		count=0;
		ok1=false;
		ok2=false;
		for (j=stime;j<etime;j++)
		{
			ok2=false;
			for (k=1;k<=n;k++)	
				if (pc[k][j]==student)
				{
					ok2=true;
//					if (j!=etime)
						count++;
					break;
				}
			if ((!ok2)&&(ok1))
				count--;
			ok1=ok2;
		}
			
		printf("%d\n",count);			
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
