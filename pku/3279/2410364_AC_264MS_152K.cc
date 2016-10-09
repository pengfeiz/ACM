#include <iostream>
using namespace std;

#define MAX 17

int a[MAX][MAX];
int b[MAX][MAX],c[MAX][MAX];
int m,n,tt;

void dosth(int x,int y,int t)
{
	if(t>=tt)
		return;
	if(x==n+1)
	{
		int i,j;
		for(i=1;i<=m;i++)
			if(a[n][i])
				return;
		if(t<tt)
		{
			tt=t;
			for(i=1;i<=n;i++)
				for(j=1;j<=m;j++)
					c[i][j]=b[i][j];
		}
		return;
	}
	if(y==m+1)
		dosth(x+1,1,t);
	else if(x>1)
	{
		if(a[x-1][y])
		{
			b[x][y]=1;
			a[x][y]^=1;
			a[x-1][y]^=1;
			a[x+1][y]^=1;
			a[x][y-1]^=1;
			a[x][y+1]^=1;
			dosth(x,y+1,t+1);
			b[x][y]=0;
			a[x][y]^=1;
			a[x-1][y]^=1;
			a[x+1][y]^=1;
			a[x][y-1]^=1;
			a[x][y+1]^=1;
		}
		else
			dosth(x,y+1,t);
	}
	else
	{
		dosth(x,y+1,t);
		b[x][y]=1;
		a[x][y]^=1;
		a[x-1][y]^=1;
		a[x+1][y]^=1;
		a[x][y-1]^=1;
		a[x][y+1]^=1;
		dosth(x,y+1,t+1);
		b[x][y]=0;
		a[x][y]^=1;
		a[x-1][y]^=1;
		a[x+1][y]^=1;
		a[x][y-1]^=1;
		a[x][y+1]^=1;
	}
}



int main()
{
	//freopen("in.txt","r",stdin);
	int i,j;
	scanf("%d%d",&n,&m);
	tt=9999;
	memset(b,0,sizeof(b));
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	dosth(1,1,0);
	if(tt!=9999)
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
	else
		printf("IMPOSSIBLE\n");
	return 0;
}
