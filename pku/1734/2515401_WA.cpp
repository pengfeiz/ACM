#include <iostream>
using namespace std;
#define MAX 102

int d[MAX][MAX];

int main()
{
	int n,m,i,j,k,x,y,l,p1,p2,maxx;
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
			d[x][y]=l;
	}
	for(k=1;k<=n;k++)
	{
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				if(d[i][j]>d[i][k]+d[k][j])
					d[i][j]=d[i][k]+d[k][j];
		for(i=1;i<n;i++)
			for(j=1;j<=n;j++)
			{
				if(i!=k&&j!=k&&i!=j)
				{
					if(maxx>d[i][k]+d[k][j]+d[j][i])
					{
						p1=i;
						p2=j;
					}
				}
			}
	}
	if(!p1)
		printf("No solution.\n");
	else
	{
		printf("%d",p1);
		i=p1;
		while(1){
			maxx=99999;
			for(j=1;j<=n;j++)
			{
				if(d[i][j]+d[j][p2]==d[i][p2])
					if(d[i][j]<maxx)
					{
						maxx=d[i][j];
						k=j;
					}
			}
			if(maxx==99999)
				break;
			printf(" %d",k);
			i=j;
		}
		printf(" %d",p2);
		i=p2;
		while(1){
			for(j=1;j<=n;j++)
			{
				if(d[i][j]+d[j][p1]==d[i][p1])
					if(d[i][j]<maxx)
					{
						maxx=d[i][j];
						k=j;
					}
			}
			if(maxx==99999)
				break;
			printf(" %d",k);
			i=j;
		}
	}
	return 0;
}