#include <iostream>
using namespace std;

#define MAX 18

int a[MAX][MAX],n,m;
int b[MAX][MAX],c[MAX][MAX];
int t;

void dosth(int x,int y,int tt)
{
	int i,j;
	if(x==n+1)
	{
		if(tt<=t)
		{
			if(tt<t)
			{
				for(i=1;i<=n;i++)
					for(j=1;j<=m;j++)
						c[i][j]=b[i][j];
			}
			else
			{
				int f=0;
				for(i=1;!f&&i<=n;i++)
					for(j=1;!f&&j<=m;j++)
					{
						if(b[i][j]<c[i][j])
							f=1;
						else if(b[i][j]>c[i][j])
							f=2;
					}
				if(f==1)
					for(i=1;i<=n;i++)
						for(j=1;j<=m;j++)
							c[i][j]=b[i][j];
			}
			t=tt;
		}
		return;
	}
	if(y>m)
	{
		dosth(x+1,1,tt);
		return ;
	}
	if(!a[x][y])
	{
		dosth(x,y+1,tt);
		return ;
	}
	if(x==1&&y==1)
	{
		a[1][1]^=1;
		a[1][2]^=1;
		a[2][1]^=1;
		b[1][1]=1;
		dosth(x,y+1,tt+1);
		b[1][1]=0;
		a[1][1]^=1;
		a[1][2]^=1;
		a[2][1]^=1;
	}
	if(x==1&&y<m)
	{
		a[x][y]^=1;
		a[x][y+1]^=1;
		a[x][y+2]^=1;
		a[x+1][y+1]^=1;
		b[x][y+1]=1;
		dosth(x,y+1,tt+1);
		b[x][y+1]=0;
		a[x][y]^=1;
		a[x][y+1]^=1;
		a[x][y+2]^=1;
		a[x+1][y+1]^=1;
	}
	if(x==n)
		return;
	if(x<n)
	{
		a[x][y]^=1;
		a[x+1][y-1]^=1;
		a[x+1][y]^=1;
		a[x+1][y+1]^=1;
		a[x+2][y]^=1;
		b[x+1][y]=1;
		dosth(x,y+1,tt+1);
		b[x+1][y]=0;
		a[x][y]^=1;
		a[x+1][y-1]^=1;
		a[x+1][y]^=1;
		a[x+1][y+1]^=1;
		a[x+2][y]^=1;
	}
}

		




int main()
{
	memset(a,0,sizeof(a));
	int i,j;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	t=0x7fffffff;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			c[i][j]=1;
	memset(b,0,sizeof(b));
	dosth(1,1,0);
	if(t==0x7fffffff)
		printf("IMPOSSIBLE\n");
	else
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				if(j-1)
					printf(" ");
				printf("%d",c[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}

