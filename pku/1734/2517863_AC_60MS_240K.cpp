#include <iostream>
using namespace std;
#define MAX 102

int d[MAX][MAX],a[MAX][MAX];

int main()
{
	int n,m,i,j,k,x,y,l,p1,p2,p3,maxx;
	p1=p2=0;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			d[i][j]=9999999;
	maxx=9999999;
	for(i=0;i<m;i++)
	{
		scanf("%d%d%d",&x,&y,&l);
		if(d[x][y]>l)
			d[x][y]=d[y][x]=l;
	}
	memcpy(a,d,sizeof(a));
	for(k=1;k<=n;k++)
	{
		for(i=1;i<k;i++)
			for(j=i+1;j<k;j++)
			{
				if(maxx>a[i][k]+a[k][j]+d[j][i])
				{
					maxx=a[i][k]+a[k][j]+d[j][i];
					p1=i;
					p2=j;
					p3=k;
				}
			}
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				if(d[i][j]>d[i][k]+d[k][j])
					d[i][j]=d[i][k]+d[k][j];
	}
	if(!p1)
	{
		printf("No solution.\n");
		return 0;
	}
	memcpy(d,a,sizeof(a));
	for(k=1;k<p3;k++)
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				if(d[i][j]>d[i][k]+d[k][j])
					d[i][j]=d[i][k]+d[k][j];
	printf("%d %d",p3,p1);
	for(i=1;i<=n;i++)
		d[i][i]=0;
	i=p1;
	while(i!=p2)
	{
		for(j=1;j<=n;j++)
			if(a[i][j]+d[j][p2]==d[i][p2])
				break;
		printf(" %d",j);
		i=j;
	}
	printf("\n");
	return 0;
}