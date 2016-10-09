#include <iostream>
using namespace std;

int n,m,l,t,y[201];
bool a[201][201],q[201];

bool find(int x)
{
	int i;
	if(q[x])
		return false;
	q[x]=true;
	for(i=1;i<=m;i++)
	{
		if(a[x][i])
		{
			if(!y[i]||find(y[i]))
			{
				if(!y[i])
					y[i]=x;
				return true;
			}
		}
	}
	return false;
}

int main()
{
	int ca=1;
	while(scanf("%d%d%d",&n,&m,&l),n||m||l)
	{
		t=0;
		int i,j;
		int v1,v2;
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++)
				a[i][j]=true;
		for(i=0;i<l;i++)
		{
			scanf("%d%d",&v1,&v2);
			a[v1][v2]=0;
		}
		memset(y,0,sizeof(y));
		for(i=1;i<=n;i++)
		{
			memset(q,0,sizeof(q));
			if(find(i))
				t++;
		}
		printf("Case %d: %d\n",ca,n+m-t);
		ca++;
	}
	return 0;
}