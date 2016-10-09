#include <iostream>
using namespace std;
#define MAX 502

int y[MAX],n,m,t;
bool a[MAX][MAX];
bool q[MAX];


bool find(int x)
{
	int i;
	if(q[x])
		return false;
	q[x]=true;
	for(i=1;i<=n;i++)
		if(a[x][i]&&(!y[i]||find(y[i])))
		{
			if(!y[i])
				t++;
			y[i]=x;
			return true;
		}
	return false;
}

int main()
{
	int i,xx,yy,j,k;
	while(scanf("%d%d",&n,&m),n||m)
	{
		t=0;
		memset(a,0,sizeof(a));
		memset(y,0,sizeof(y));
		for(i=0;i<m;i++)
		{
			scanf("%d%d",&xx,&yy);
			a[xx][yy]=true;
		}
		for(k=1;k<=n;k++)
			for(i=1;i<=n;i++)
				for(j=1;j<=n;j++)
					if(!a[i][j]&&a[i][k]&&a[k][j])
						a[i][j]=true;

		for(i=1;i<=n;i++)
		{
			memset(q,0,sizeof(q));
			find(i);
		}
		printf("%d\n",n-t);
	}
	return 0;
}
