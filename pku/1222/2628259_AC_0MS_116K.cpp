#include <iostream>
using namespace std;

#define MAX 17

int a[MAX][MAX];
int b[MAX][MAX],c[MAX][MAX];
int n,tt;

void dosth(int x,int y,int t)
{
	if(t>=tt)
		return;
	if(x==6)
	{
		int i,j;
		for(i=1;i<=6;i++)
			if(a[5][i])
				return;
		tt=0;
		for(i=1;i<=5;i++)
			for(j=1;j<=6;j++)
				c[i][j]=b[i][j];
		return;
	}
	if(y==7)
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
	int i,j,kk;
	scanf("%d",&n);
	for(kk=1;kk<=n;kk++)
	{
		printf("PUZZLE #%d\n",kk);
		tt=9999;
		memset(b,0,sizeof(b));
		for(i=1;i<=5;i++)
			for(j=1;j<=6;j++)
				scanf("%d",&a[i][j]);
		dosth(1,1,0);
		for(i=1;i<=5;i++)
		{
			for(j=1;j<=6;j++)
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
