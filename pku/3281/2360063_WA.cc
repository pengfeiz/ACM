#include <iostream>
using namespace std;
#define MAX 101
//y表示来自，z表示去向
int z[MAX],y[MAX],n,m1,m2,t;
bool a[MAX][MAX],b[MAX][MAX],q[MAX];

bool find(int x,bool a[MAX][MAX],int m)
{
	int i;
	if(q[x])
		return false;
	q[x]=true;
	for(i=1;i<=m;i++)
		if(a[x][i]&&(!y[i]||find(y[i],a,m)))
		{
			if(!y[i])
				t++;
			z[x]=i;
			y[i]=x;
			return true;
		}
	return false;
}

int main()
{
	int i,j1,j2,w,t1,t2;
	while(scanf("%d%d%d",&n,&m1,&m2)!=EOF)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&j1,&j2);
			while(j1--)
			{
				scanf("%d",&w);
				a[i][w]=true;
			}
			while(j2--)
			{
				scanf("%d",&w);
				b[i][w]=true;
			}
		}
		t=0;
		memset(y,0,sizeof(y));
		memset(z,0,sizeof(z));
		for(i=1;i<=n;i++)
		{
			memset(q,0,sizeof(q));
			find(i,a,m1);
		}
		t1=t;
		t=0;
		memset(y,0,sizeof(y));
		memset(z,0,sizeof(z));
		for(i=1;i<=n;i++)
		{
			memset(q,0,sizeof(q));
			find(i,b,m2);
		}
		t2=t;
		printf("%d\n",t1>t2?t2:t1);
		//t表示最大匹配数
	}
	return 0;
}