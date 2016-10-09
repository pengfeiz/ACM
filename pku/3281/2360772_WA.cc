#include <iostream>
using namespace std;
#define MAX 101
//y表示来自，z表示去向
int y[MAX],z[MAX],n,m1,m2,t;
bool a[MAX][MAX],b[MAX][MAX],q[MAX];

bool find(int x)
{
	int i,j;
	bool f;
	if(q[x])
		return false;
	q[x]=true;
	for(i=1;i<=m1;i++)
		if(a[x][i]&&(!y[i]||find(y[i])))
		{
			if(y[i])
				f=true;
			else
				f=false;
			y[i]=x;
			for(j=1;j<=m2;j++)
			{
				if(a[x][j]&&(!z[j]||find(z[j])))
				{
					if(!f&&!z[j])
						t++;
					z[j]=x;
					return true;
				}
			}
		}
	return false;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i,j1,j2,w;
	scanf("%d%d%d",&n,&m1,&m2);
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
		find(i);
	}
	printf("%d\n",t);
	return 0;
}