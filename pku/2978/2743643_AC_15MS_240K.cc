#include<cstdio>
#include<algorithm>

const	int		maxn=101;
const	int		maxm=5;
const	int		maxs=31;

int			n,m;
int			q[maxn];

void		init()
{
 			int	i;
 			
 			scanf("%d %d\n",&n,&m);
 			
			if (n+m==0)
		 	   exit(0);
			   
   			for (i=1;i<=n;i++)
   			{
			   scanf("%d",&q[i]);   
			   q[i]--;
   			}   
   			scanf("\n");   
	
}

int			f[maxn][maxs][maxm];

void		starmain()
{
 			int	i,j,k,ans;
 			
 			memset(f,0,sizeof(f));
			 
			 for (i=1;i<=n;i++)
			 	 for (j=0;j<(1<<m);j++)
			 	 	 for (k=0;k<m;k++)
			 	 	 	if ((j>>k)&1)
		 	 	 	 	{
		   			 	   if (k==q[i])
		   			 	   	  f[i][j][k]=f[i-1][j][k];
		   			 	   else	  
						      f[i][j][k]=f[i-1][j][k]+1;
						      
				      		if (!((j>>q[i])&1))
				      		   f[i][j][k]<?=f[i-1][j|(1<<q[i])][q[i]];
						}
			ans=0x7fffffff;
			for (i=0;i<(1<<m);i++)
				for (j=0;j<m;j++)
					if ((i>>j)&1)
					   ans<?=f[n][i][j];
			printf("%d\n",ans);
}

int			main()
{
 			//freopen("c:\\in.txt","r",stdin);
 			
 			while (true)
 			{
			 	  init();
			 	  starmain();
			} 	  
			

 			return(0);
}

