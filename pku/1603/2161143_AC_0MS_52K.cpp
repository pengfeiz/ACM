#include <iostream>
using namespace std;
#define MAX 21

int a[MAX][MAX];
int main()
{
	int i,j,time=0,m,n,k;
	while(scanf("%d",&m)!=EOF)
	{
		time++;
		printf("Test Set #%d\n",time);
		for(i=1;i<=20;i++)
			for(j=1;j<=20;j++)
				a[i][j]=a[j][i]=99999999;
		for(i=0;i<m;i++)
		{
			scanf("%d",&j);
			a[1][j]=a[j][1]=1;
		}
		for(i=2;i<=19;i++)
		{
			scanf("%d",&m);
			for(j=0;j<m;j++)
			{
				scanf("%d",&n);
				a[i][n]=a[n][i]=1;
			}
		}
		for(k=1;k<=20;k++)
			for(i=1;i<=20;i++)
				for(j=1;j<=20;j++)
					if(a[i][k]+a[k][j]<a[i][j])
						a[i][j]=a[i][k]+a[k][j];
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&j,&k);
			printf("%d to %d: %d\n",j,k,a[j][k]);
		}
		printf("\n");
	}
	return 0;
}


		
