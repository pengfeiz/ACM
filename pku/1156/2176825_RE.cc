#include <iostream>
using namespace std;
#define MAX 15
int a[MAX][MAX],b[MAX][MAX][2],h;
int main()
{
	int n,i,j,m,k,top,dow,total;
	scanf("%d%d",&m,&n);
	total=0;
	for(i=0;i<=n+1;i++)
		for(j=0;j<=m+1;j++)
			a[i][j]=999999;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{
			top=a[i][j];
			dow=a[i][j];
			for(k=i-1;k>=0;k--)
			{
				if(a[k][j]>top)
					top=a[k][j];
				if(a[k][j]<dow)
					dow=a[k][j];
				if(top-dow>h)
					break;
			}
			b[i][j][0]=i-k;
			top=a[i][j];
			dow=a[i][j];			
			for(k=i+1;k<=n+1;k++)
			{
				if(a[k][j]>top)
					top=a[k][j];
				if(a[k][j]<dow)
					dow=a[k][j];
				if(top-dow>h)
					break;
			}
			b[i][j][1]=k-i;
		}
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{
			top=b[i][j][0];
			dow=b[i][j][1];
			for(k=0;k<100;k++)
			{
				if(j+k>m)
					break;
				if(abs(a[i][j]-a[i][j+k])>h)
					break;
				if(b[i][j+k][0]<top)
					top=b[i][j+k][0];
				if(b[i][j+k][1]<dow)
					dow=b[i][j+k][1];
				if((dow+top-1)*(k+1)>total)
					total=(dow+top-1)*(k+1);
			}
		}
	printf("%d\n",total);
	return 0;
}

	