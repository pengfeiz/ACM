#include <iostream>
using namespace std;

#define MAX 17

int a[MAX][MAX];
int b[MAX][MAX];
bool f;
int m,n;

void dosth(int x,int y)
{
	if(f)
		return;
	if(x==n+1)
	{
		int i;
		for(i=1;i<=n;i++)
			if(a[n][i])
				return;
		f=true;
		return;
	}
	if(y==m+1)
		dosth(x+1,1);
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
			dosth(x,y+1);
			if(f)
				return;
			b[x][y]=0;
			a[x][y]^=1;
			a[x-1][y]^=1;
			a[x+1][y]^=1;
			a[x][y-1]^=1;
			a[x][y+1]^=1;
		}
		else
			dosth(x,y+1);
	}
	else
	{
		dosth(x,y+1);
		if(f)
			return;
		b[x][y]=1;
		a[x][y]^=1;
		a[x-1][y]^=1;
		a[x+1][y]^=1;
		a[x][y-1]^=1;
		a[x][y+1]^=1;
		dosth(x,y+1);
		if(f)
			return;
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
//	freopen("in.txt","r",stdin);
	int i,j;
	scanf("%d%d",&n,&m);
	f=false;
	memset(b,0,sizeof(b));
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	dosth(1,1);
	if(f)
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				if(j-1)
					printf(" ");
				printf("%d",b[i][j]);
			}
			printf("\n");
		}
	else
		printf("IMPOSSIBLE\n");
	return 0;
}
