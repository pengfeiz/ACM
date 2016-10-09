#include <iostream>
using namespace std;
#define MAX 201
//y表示来自，z表示去向
int z[MAX],y[MAX],n,t,m;
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
			z[x]=i;
			y[i]=x;
			return true;
		}
	return false;
}

int main()
{
	int tt,i,j,w;
	scanf("%d",&tt);
whilr(tt--)
{
	scanf("%d%d",&n,&m);
		t=0;
		memset(a,0,sizeof(a));
		memset(y,0,sizeof(y));
		memset(z,0,sizeof(z));
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
		if(t==n)
printf("YES\n");
else
printf("NO\n");
		//t表示最大匹配数
	}
	return 0;
}