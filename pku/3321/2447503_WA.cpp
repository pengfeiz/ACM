#include<cstdio>
#include<algorithm>

const	int		maxn=1001;

int		a[maxn][maxn],b[maxn][maxn],c[maxn][maxn];
__int64	r1[maxn],r2[maxn],c1[maxn],c2[maxn];
int		n,p,m;

void	init()
{
	int			i,j;
	__int64		t[maxn];
	
	memset(r2,0,sizeof(r2));
	memset(c2,0,sizeof(c2));
	
	scanf("%d %d %d\n",&n,&p,&m);
	
	for (i=0;i<n;i++)
	{
		for (j=0;j<p;j++)
			scanf("%d",&a[i][j]);
		scanf("\n");
	}
	
	for (i=0;i<p;i++)
	{
		for (j=0;j<m;j++)
			scanf("%d",&b[i][j]);
		scanf("\n");
	}
	
	for (i=0;i<n;i++)
	{
		for (j=0;j<m;j++)
			scanf("%d",&c[i][j]);
		scanf("\n");
	}
		
	
	for (i=0;i<n;i++)
	{
		r1[i]=0;
		for (j=0;j<m;j++)
			r1[i]+=c[i][j];
	}
	
	for (i=0;i<m;i++)
	{
		c1[i]=0;
		for (j=0;j<n;j++)
			c1[i]+=c[j][i];
	}
	
	memset(t,0,sizeof(t));
	for (i=0;i<p;i++)
		for (j=0;j<m;j++)
			t[i]+=b[i][j];

	for (i=0;i<n;i++)
		for (j=0;j<p;j++)
			r2[i]+=t[j]*a[i][j];	
				

	memset(t,0,sizeof(t));
	for (i=0;i<p;i++)
		for (j=0;j<n;j++)
			t[i]+=a[j][i];
			
	for (i=0;i<m;i++)
		for (j=0;j<p;j++)
			c2[i]+=t[j]*b[j][i];
	
}

void	starmain()
{
	int			x,y,i;
	__int64		sum;
	
	r1[n]=0;
	r2[n]=1;
	c1[m]=0;
	c2[m]=1;
	for (x=0;r1[x]==r2[x];x++);
	for (y=0;c1[y]==c2[y];y++);
	if ((x==n)&&(y==m))
	{
		printf("Yes\n");
		exit(0);
	}
	else
		printf("No\n");
//	
//	sum=0;
//	for (i=0;i<p;i++)
//		sum+=(__int64)a[x][i]*b[i][y];
//	
//	printf("No\n%d %d\n%I64d\n",x+1,y+1,sum);
}

int		main()
{
//	freopen("c:\\in.txt","r",stdin);
	
	init();
	starmain();
	return(0);
}
