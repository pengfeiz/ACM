#include <iostream>
using namespace std;
#define MAX 101
//y表示来自，z表示去向
int y[MAX],z[MAX],n,m1,m2,t,xx;
bool a[MAX][MAX],b[MAX][MAX],q1[MAX],q2[MAX],g[MAX],ff;


bool find2(int x)
{
	int i;
	if(q2[x])
		return false;
	q2[x]=true;
	for(i=1;i<=m2;i++)
		if(b[x][i]&&(!z[i]||find2(z[i])))
		{	
			z[i]=x;
			ff=true;
			return true;
		}
	return false;
}

bool find(int x)
{
	int i,qq;
	if(q1[x])
		return false;
	q1[x]=true;
	for(i=1;i<=m1;i++)
		if(a[x][i]&&(!y[i]||find(y[i])))
		{
			qq=y[i];
			y[i]=x;
			if(ff||find2(xx))
				return true;
			y[i]=qq;
		}
	return false;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i,j1,j2,w;
	scanf("%d%d%d",&n,&m1,&m2);
	memset(g,0,sizeof(g));
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
		xx=i;
		ff=false;
		memset(q1,0,sizeof(q1));
		memset(q2,0,sizeof(q2));
		if(find(i))
			t++;
	}
	printf("%d\n",t);
	return 0;
}