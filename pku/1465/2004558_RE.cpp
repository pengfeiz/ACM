#include<cstdio>
#include<iostream>

const	int		maxlen=501;
const	int		maxn=5001;


int			n,m;	
int			dig[11];
int			mod10[maxlen];
bool		f[maxlen][maxn];



void	print(int	p,int	s)
{
	int	i,j;
	
	for (i=p;i>=1;i--)
		for (j=1;j<=m;j++)
			if (f[i-1][(s-dig[j]*mod10[i]+10*n)%n])
			{
				if ((i==p)&&(dig[j]==0))continue;
				printf("%d",dig[j]);
				s=(s-dig[j]*mod10[i]+10*n)%n;
				break;
			}
	
	printf("\n");
}

void	starmain()
{
	int		i,j,k;

	memset(f,0,sizeof(f));
	f[0][0]=true;
	
	for (i=1;i<maxlen;i++)
		for (j=0;j<n;j++)
			for (k=1;k<=m;k++)
				if (f[i-1][(j-dig[k]*mod10[i]+10*n)%n])
				{
					f[i][j]=true;
					if ((!j)&&(dig[k]))
					{
						print(i,j);
						return;
					}
				}

			
	printf("0\n");
}

int	main()
{
//	freopen("c:\\in.txt","r",stdin);
	while (scanf("%d",&n)!=EOF)
	{
		int		i,j;
		scanf("%d",&m);
		memset(dig,0,sizeof(dig));
		for (i=1;i<=m;i++)
		{
			scanf("%d",&dig[0]);
			j=i;
			while (dig[j-1]>dig[0])
			{
				dig[j]=dig[j-1];
				j--;
			}
			dig[j]=dig[0];
		}
		
		if (!n)
			printf("0\n");
		
			
		j=1;
		for (i=1;i<maxlen;i++)
		{
			mod10[i]=j;
			j=(j*10)%n;
		}
		if (n)
			starmain();
	}
	
	return(0);
}
