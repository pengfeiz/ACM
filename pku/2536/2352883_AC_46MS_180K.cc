#include <iostream>
#include <math.h>

using namespace std;
#define MAX 201
#define esp 1e-7
//y表示来自，z表示去向


int z[MAX],y[MAX],m,t,n1,n2;
bool a[MAX][MAX],q[MAX];
struct gao
{
	double x,y;
}c[MAX],d[MAX];


double ll(double x)
{return x*x;}


bool find(int x)
{
	int i;
	if(q[x])
		return false;
	q[x]=true;
	for(i=1;i<=n2;i++)
		if(a[x][i]&&(!y[i]||find(y[i])))
		{
			z[x]=i;
			y[i]=x;
			return true;
		}
	return false;
}


int main()
{
//	freopen("in.txt","r",stdin);
	int i,j;
	double s,v;
	while(scanf("%d%d%lf%lf",&n1,&n2,&s,&v)!=EOF)
	{
		t=0;
		for(i=1;i<=n1;i++)
			scanf("%lf%lf",&c[i].x,&c[i].y);
		for(i=1;i<=n2;i++)
			scanf("%lf%lf",&d[i].x,&d[i].y);
		memset(a,0,sizeof(a));
		for(i=1;i<=n1;i++)
			for(j=1;j<=n2;j++)
				if(sqrt(ll(c[i].x-d[j].x)+ll(c[i].y-d[j].y))/v<=s+esp)
					a[i][j]=true;
		memset(y,0,sizeof(y));
		memset(z,0,sizeof(z));
		for(i=1;i<=n1;i++)
		{
			memset(q,0,sizeof(q));
			if(find(i))
				t++;
		}
		printf("%d\n",n1-t);
		//t表示最大匹配数
	}
	return 0;
}