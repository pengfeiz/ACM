#include <iostream>
using namespace std;
#define MAX 201
int y[MAX],n,m,t;
bool a[MAX][MAX],q[MAX];
bool find(int x)
{
	int i;
	if(q[x])
		return false;
	q[x]=true;
	for(i=1;i<=m;i++)
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
	int i,j,w;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		t=0;
		memset(a,0,sizeof(a));
		memset(y,0,sizeof(y));
		for(i=1;i<=n;i++)
		{
			scanf("%d",&j);
			while(j--)
			{
				scanf("%d",&w);
				a[i][w]=true;
			}
		}
		for(i=1;i<=n;i++)
		{
			memset(q,0,sizeof(q));
			find(i);
		}
		printf("%d\n",t);
	}
	return 0;
}
