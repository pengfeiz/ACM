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
		if(!a[x][i])
		{
			if(!y[i]||find(y[i]))
			{
				y[i]=x;
				return true;
			}
		}
	}
	return false;
}

int main()
{
	int ca=0;
	int i;
	int v1,v2;
	while(scanf("%d%d%d",&n,&m,&l),n||m||l)
	{
		ca++;
		t=0;
		memset(a,0,sizeof(a));
		for(i=0;i<l;i++)
		{
			scanf("%d%d",&v1,&v2);
			a[v1][v2]=true;
		}
		memset(y,0,sizeof(y));
		for(i=1;i<=n;i++)
		{
			memset(q,0,sizeof(q));
			if(find(i))
				t++;
		}
		printf("Case %d: %d\n",ca,n+m-t);
	}
	return 0;
}