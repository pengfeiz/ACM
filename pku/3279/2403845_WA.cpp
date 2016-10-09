#include <iostream>
using namespace std;

#define MAX 17

int a[MAX][MAX],n,m;
int b[MAX][MAX],c[MAX][MAX];
int t;

void dosth(int x,int y,int tt)
{
	int i,j;
	if(x==5)
	{
		if(tt<t)
		{
			t=tt;
			for(i=1;i<=n;i++)
				for(j=1;j<=m;j++)
					c[i][j]=b[i][j];
		}
		return;
	}
	if(y>m)
	{
		dosth(x+1,0,tt);
		return ;
	}
	if(!a[x][y])
	{
		dosth(x,y+1,tt);
		return ;
	}
	if(x==n&&y<=m)
		return;
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
	if(x<n)
	{
		a[x][y]^=1;
		a[x+1][y-1]^=1;
		a[x+1][y]^=1;
		a[x+1][y+1]^=1;
		b[x+1][y]=1;
		dosth(x,y+1,tt+1);
		b[x+1][y]=0;
		a[x][y]^=1;
		a[x+1][y-1]^=1;
		a[x+1][y]^=1;
		a[x+1][y+1]^=1;
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
		printf("%d\n",t);
	}
	return 0;
}

