#include <iostream>
#include <math.h>
using namespace std;
#define MAX 41
int n,a[MAX][MAX],p,q;
void dosth()
{
	int i,j;
	double l;
	for(i=0;i<=n;i++)
		for(j=0;j<=n;j++)
		{
			if(a[i][j])
				continue;
			l=(i-p)*(i-p)+(j-q)*(j-q);
			l=sqrt(l);
			if(i-l<0||i+l>n||j-l<0||j+l>n)
				a[i][j]=1;
		}
}
int main()
{
	int i,j,t,m;
	scanf("%d",&t);
	while(t-->0)
	{
		memset(a,0,sizeof(a));
		scanf("%d%d",&n,&m);
		for(i=0;i<m;i++)
		{
			scanf("%d%d",&p,&q);
			a[p][q]=1;
			dosth();
		}
		for(i=0;i<=n;i++)
		{
			for(j=0;j<=n;j++)
			{
				if(!a[i][j])
				{
					printf("%d %d\n",i,j);
					break;
				}
			}
			if(j<=n)
				break;
		}
		if(i>n)
			printf("poodle\n");
	}
	return 0;
}
